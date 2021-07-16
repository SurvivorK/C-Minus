%code requires{
  #include <string>
  #include "ast.hpp"
  extern FILE *yyin;
  extern int col, row;
  extern NodeBasePtr root;
  NodeBasePtr parse();
  int yylex(void);
  void yyerror(const char * msg);
  #define setpos(ptr) (ptr)->setpos(col, row)
}

%union{
    NodeBasePtr expr;
    yytokentype token;
    int int_val;
    std::string *string_val;
    double double_val;
}
/* Identifer, constant and string */
%token IDENTIFIER INTEGER_LITERAL FLOATING_LITERAL CHARACTER_LITERAL STRING_LITERAL

/* Punctuators (with more than one char) */
%token AND OR LEQ GEQ EQ NE MOD
%token PLUS MINUS STAR DIV ASSIGNOP LE GE
%token DOT COMMA MAO SEMI WEN LP RP LB RB LC RC NOT INV

/* Keyword */
%token T_AUTO T_BREAK T_CASE T_CHAR T_CONST T_CONTINUE T_DEFAULT T_DO T_DOUBLE T_ELSE T_ENUM T_EXTERN T_FLOAT T_FOR T_GOTO T_IF
%token T_INLINE T_INT T_LONG T_REGISTER T_RESTRICT T_RETURN T_SHORT T_SIGNED T_SIZEOF T_STATIC T_STRUCT T_SWITCH T_TYPEDEF T_UNION T_UNSIGNED T_VOID T_VOLATILE T_WHILE
%token T_PRINT T_READ

%start program

%nonassoc LOWER_THAN_ELSE
%nonassoc T_ELSE

%right ASSIGNOP
%left OR
%left AND
%left LEQ GEQ EQ NE LE GE
%left PLUS MINUS
%left STAR DIV MOD
%right NOT
%left LP RP LB RB DOT


%type <expr> INTEGER_LITERAL FLOATING_LITERAL CHARACTER_LITERAL STRING_LITERAL IDENTIFIER
%type <expr> external_declaration_list external_declaration external_declarator_list
%type <expr> specifier type_specifier struct_specifier tag_opt tag
%type <expr> variable_declarator function_declarator parameter_list parameter
%type <expr> compound_statement statement_list statement
%type <expr> declaration_list declaration declarator_list declarator
%type <expr> external_var_list program
%type <expr> Exp Args ID

%%

// High-level Definitions
program:
           external_var_list external_declaration_list {
                root = new NodeBase();
                root->childrens.push_back($1);
                root->childrens.push_back($2);
                setpos(root);
            }
        ;
external_var_list :
            %empty {
                $$ = new GlobalVarList();
                setpos($$);
            }
        |   external_var_list declaration {
            $1->childrens.push_back($2);
            $$ = $1;
        }
        ;
external_declaration_list:
            external_declaration{
                $$ = new GlobalDeclarationList();
                $$ -> childrens.push_back($1);
                setpos($$);
            }
        |  external_declaration external_declaration_list {
            $2->childrens.insert($2->childrens.begin(), $1);
            $$ = $2;
        }
        ;
external_declaration:
// cancelled
//            specifier external_declarator_list SEMI {
//                $$ = new GlobalVarDecl($1, $2);
//            }
// cancelled
//        |   specifier SEMI {
//                $$ = new GlobalTypeDecl($1);
//            }
        // |
            specifier function_declarator compound_statement {
                $$ = new GlobalFuncDecl($1, $2, $3);
                setpos($$);
            }
        ;
// Global var is cancelled
//external_declarator_list:
//            variable_declarator {
//                $$ = new GlobalVarList();
//            }
//        |   external_declarator_list COMMA variable_declarator  {
//                $1->childrens.push_back($3);
//                $$ = $1;
//            }
//        ;
// Specifiers
specifier:
            T_VOID        {$$ = new Type(Type::VARTYPE::VOID); setpos($$);}
        //|   T_CHAR        {$$ = new Type(Type::VARTYPE::CHAR); }
        |   T_INT         {$$ = new Type(Type::VARTYPE::INT); setpos($$);}
        ;


// Declarators
variable_declarator:
            ID {
                $$ = new DirectDeclarator($1);
                cur_node = $$;
                setpos($$);
            }
        ;

function_declarator:
            ID LP parameter_list RP {
                $$ = new FunctionDeclarator($1, $3);
                setpos($$);
            }
        |   ID LP RP {
                $$ = new FunctionDeclarator($1);
                setpos($$);
            }
        ;
parameter_list:
            parameter_list COMMA parameter  {
                $1->childrens.push_back($3);
                $$ = $1;
            }
        |   parameter {
                $$ = new ParameterList($1);
                setpos($$);
            }
        ;
parameter:
            specifier ID{
                $$ = new Parameter($1, new DirectDeclarator($2));
                setpos($$);
            }
        ;

// Statement
compound_statement:
            LC declaration_list statement_list RC {
                $$ = new CompStmt($2, $3);
                setpos($$);
            }
        ;

statement_list:
            %empty {
                $$ = new StmtList();
                setpos($$);
            }
        |   statement_list statement {
                $1->childrens.push_back($2);
                $$ = $1;
            }
        ;

statement:
            Exp SEMI {
                $$ = $1;
                setpos($$);
            }
        |   compound_statement {
                $$ = $1;
                setpos($$);
            }
        |   T_PRINT LP Exp COMMA Args RP SEMI {
                $$ = new PrintStmt($3, $5);
                setpos($$);
            }
        |   T_RETURN SEMI {
                $$ = new ReturnStmt();
                setpos($$);
            }
        |   T_RETURN Exp SEMI {
                $$ = new ReturnStmt($2);
                setpos($$);
            }
        |   T_IF LP Exp RP compound_statement %prec LOWER_THAN_ELSE {
                $$ = new IfStmt($3, $5);
                setpos($$);
            }
        |   T_IF LP Exp RP compound_statement T_ELSE compound_statement {
                $$ = new IfStmt($3, $5, $7);
                setpos($$);
            }
        |   T_WHILE LP Exp RP compound_statement {
                $$ = new WhileStmt($3, $5);
                setpos($$);
            }
        |   T_BREAK SEMI {
                $$ = new BreakStmt();
                setpos($$);
            }
        |   T_CONTINUE SEMI {
                $$ = new ContinueStmt();
                setpos($$);
            }
        ;
// Local Definitions
declaration_list:
            %empty { $$ = new DeclarationList(); setpos($$); }
        |   declaration_list declaration {
                $1->childrens.push_back($2);
                $$ = $1;
            }
        ;

declaration:
            specifier ID SEMI {
                $$ = new Declarations($1, new DirectDeclarator($2));
                setpos($$);
            }
        ;

//declarator_list:
//            declarator {
//                $$ = new DeclaratorList($1);
//            }
//        |   declarator_list COMMA declarator {
//                $1->childrens.push_back($3);
//            }
//        ;
//declarator:
//            variable_declarator {
//                $$ = $1;
//            }
//        |   variable_declarator ASSIGNOP Exp {
//                $$ = new InitDeclarator($1, $3);
//        }
//        ;
        
// Expressions
Exp:
            Exp ASSIGNOP Exp {
                $$ = new BinaryAssignments($1, BinaryAssignments::AssignOP::ASSIGNEQ, $3);
                setpos($$);
            }
        |   Exp AND Exp {
                $$ = new BinaryOperators($1, BinaryOperators::OP::LOGAND, $3);
                setpos($$);
            }
        |   Exp OR Exp {
                $$ = new BinaryOperators($1, BinaryOperators::OP::LOGOR, $3);
                setpos($$);
            }
        |   Exp GE Exp {
                $$ = new BinaryOperators($1, BinaryOperators::OP::GE, $3);
                setpos($$);
            }
        |   Exp LE Exp {
                $$ = new BinaryOperators($1, BinaryOperators::OP::LE, $3);
                setpos($$);
            }
        |   Exp GEQ Exp {
                $$ = new BinaryOperators($1, BinaryOperators::OP::GEQ, $3);
                setpos($$);
            }
        |   Exp LEQ Exp {
                $$ = new BinaryOperators($1, BinaryOperators::OP::LEQ, $3);
                setpos($$);
            }
        |   Exp EQ Exp {
                $$ = new BinaryOperators($1, BinaryOperators::OP::EQ, $3);
                setpos($$);
            }
        |   Exp NE Exp {
                $$ = new BinaryOperators($1, BinaryOperators::OP::NEQ, $3);
                setpos($$);
            }
        |   Exp PLUS Exp {
                $$ = new BinaryOperators($1, BinaryOperators::OP::ADD, $3);
                setpos($$);
            }
        |   Exp MINUS Exp {
                $$ = new BinaryOperators($1, BinaryOperators::OP::SUB, $3);
                setpos($$);
            }
        |   Exp STAR Exp {
                $$ = new BinaryOperators($1, BinaryOperators::OP::MUL, $3);
                setpos($$);
            }
        |   Exp DIV Exp {
                $$ = new BinaryOperators($1, BinaryOperators::OP::DIV, $3);
                setpos($$);
            }
        |   Exp MOD Exp {
                $$ = new BinaryOperators($1, BinaryOperators::OP::MOD, $3);
                setpos($$);
            }
        |   LP Exp RP {
                $$ = $2;
                setpos($$);
            }
        |   MINUS Exp {
                $$ = new UnaryOperators(UnaryOperators::OP::SUB, $2);
                setpos($$);
            }
        |   NOT Exp {
                $$ = new UnaryOperators(UnaryOperators::OP::NOT, $2);
                setpos($$);
            }
        |   ID LP Args RP {
                $$ = new FunctionCall($1, $3);
                setpos($$);
            }
        |   ID LP RP {
                $$ = new FunctionCall($1);
                setpos($$);
            }
//        |   ID LB Exp RB {
//                $$ = new ArrayReference($1, $3);
//            }
//        |   Exp DOT ID {
//                $$ = new StructReference($1, $3);
//            }
            // look up in the symbol table
        |   T_READ LP RP{
                $$ = new ReadInt();
                setpos($$);
            }
        |   IDENTIFIER      {$$ = new ExpID(*yylval.string_val);setpos($$);}
        |   INTEGER_LITERAL {$$ = new Constants(Type::VARTYPE::INT,*yylval.string_val);setpos($$);}
//        |   FLOATING_LITERAL   {$$ = new Constants(Constants::ValueType::FLOAT,*yylval.string_val);}
        |   STRING_LITERAL   {$$ = new Constants(Type::VARTYPE::STRING,*yylval.string_val);setpos($$);}

    ;
ID:
            IDENTIFIER{
                $$ = new Identifier(*yylval.string_val);
                setpos($$);
            }
Args:
            Args COMMA Exp {
                $1->childrens.push_back($3);
                $$ = $1;
            }
        |   Exp {
            $$ = new ExpressionList($1);
            setpos($$);
            }
        ;


%%

NodeBasePtr root; // Definition of variable (to match declaration earlier)

NodeBasePtr parse()
{
  root = NULL;
  yyparse();
  return root;
}
