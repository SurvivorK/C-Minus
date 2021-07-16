%option yylineno
%option noyywrap
%{
// #define DEBUG_LEXER

#include <stdio.h>
#include <string>
#include "parser.tab.h"
void locate();
void comment_check();
void unrecognized_char(char c);
void yyerror(const char * msg);
#ifdef DEBUG_LEXER
#define RETURN_TOKEN(X) printf(#X); printf(" \n"); //return(X)
#else
#define RETURN_TOKEN(X) return(X)
#endif
%}
/*Definition Part*/


/*keyword part*/
AUTO auto
BREAK break
CASE case
CHAR char
CONST const
CONTINUE continue
DEFAULT default
DO do
DOUBLE double
ELSE else
ENUM enum
EXTERN extern
FLOAT float
FOR for
GOTO goto
IF if
INLINE inline
INT int
LONG long
REGISTER register
RESTRICT restrict
RETURN  return
SHORT short
SIGNED signed
SIZEOF sizeof
STATIC static
STRUCT struct
SWITCH switch
TYPEDEF typedef
UNION union
UNSIGNED unsigned
VOID void
VOLATILE volatile
READ read
WHILE while
_BOOL _Bool
_COMPLEX _Complex
_IMAGINARY _Imaginary

SINGLE_LINE_COMMENT			"//".*
MULTI_LINE_COMMENT			"/*"
COMMENT 					{SINGLE_LINE_COMMENT}|{MULTI_LINE_COMMENT}
/*identifiers part*/

NONDIGIT 						[_a-zA-Z]
DIGIT 							[0-9]
NONZERO_DIGIT					[1-9]
OCTAL_DIGIT 					[0-7]
HEXADECIMAL_DIGIT 				[0-9A-Fa-f]
HEXADECIMAL_PREFIX				"0X"|"0x"
HEX_QUAD 						{HEXADECIMAL_DIGIT}{HEXADECIMAL_DIGIT}

/*Escape sequence*/

SIMPLE_ESCAPE_SEQUENCE 			"\'"|"\""|"\?"|"\\"|"\a"|"\b"|"\f"|"\n"|"\r"|"\t"|"\v"
OCTAL_ESCAPE_SEQUENCE 			"\\"{OCTAL_DIGIT}|"\\"{OCTAL_DIGIT}{OCTAL_DIGIT}|"\\"{OCTAL_DIGIT}{OCTAL_DIGIT}{OCTAL_DIGIT}
HEXADECIMAL_ESCAPE_SEQUENCE 	"\\x"{HEXADECIMAL_DIGIT}+

IDENTIFIER_NONDIGIT 			{NONDIGIT}
IDENTIFIER						{NONDIGIT}+({DIGIT}|{NONDIGIT})*

ESCAPE_SEQUENCE					{SIMPLE_ESCAPE_SEQUENCE}|{OCTAL_ESCAPE_SEQUENCE}|{HEXADECIMAL_ESCAPE_SEQUENCE}

/*Constant*/
/* Integer */
DECIMAL_CONSTANT 				{NONZERO_DIGIT}{DIGIT}*
OCTAL_CONSTANT					"0"{OCTAL_DIGIT}*
HEXADECIMAL_CONSTANT			{HEXADECIMAL_PREFIX}{HEXADECIMAL_DIGIT}+
UNSIGNED_SUFFIX 				"u"|"U"
LONG_SUFFIX						"L"|"l"
LONGLONG_SUFFIX					"LL"|"ll"
INTEGER_SUFFIX 					{UNSIGNED_SUFFIX}{LONG_SUFFIX}?|{UNSIGNED_SUFFIX}{LONGLONG_SUFFIX}?|{LONG_SUFFIX}{UNSIGNED_SUFFIX}?|{LONGLONG_SUFFIX}{UNSIGNED_SUFFIX}?
INTEGER_CONSTANT 				{DECIMAL_CONSTANT}{INTEGER_SUFFIX}?|{OCTAL_CONSTANT}{INTEGER_SUFFIX}?|{HEXADECIMAL_CONSTANT}{INTEGER_SUFFIX}?

/* FLOATING */
SIGN 							"+"|"-"
DIGIT_SEQUENCE					{DIGIT}+
HEXADECIMAL_DIGIT_SEQUENCE 		{HEXADECIMAL_DIGIT}+
EXPONENT						("E"|"e"){SIGN}?{DIGIT_SEQUENCE}
FLOATING_SUFFIX					"f"|"F"|"L"|"l"
BINARY_EXPONENT					("P"|"p"){SIGN}?{DIGIT_SEQUENCE}
FRACTIONAL_CONSTANT 			{DIGIT_SEQUENCE}?"\."{DIGIT_SEQUENCE}|{DIGIT_SEQUENCE}"\."
HEXADECIMAL_FRACTIONAL_CONSTANT	{HEXADECIMAL_DIGIT_SEQUENCE}?"\."{HEXADECIMAL_DIGIT_SEQUENCE}|{HEXADECIMAL_DIGIT_SEQUENCE}"\."

DECIMAL_FLOATING_CONSTANT 		{FRACTIONAL_CONSTANT}{EXPONENT}?{FLOATING_SUFFIX}?|{DIGIT_SEQUENCE}{EXPONENT}{FLOATING_SUFFIX}?
HEXADECIMAL_FLOATING_CONSTANT	{HEXADECIMAL_PREFIX}{HEXADECIMAL_FRACTIONAL_CONSTANT}{BINARY_EXPONENT}{FLOATING_SUFFIX}?|{HEXADECIMAL_PREFIX}{HEXADECIMAL_DIGIT_SEQUENCE}{BINARY_EXPONENT}{FLOATING_SUFFIX}?

FLOATING_CONSTANT 				{DECIMAL_FLOATING_CONSTANT}|{HEXADECIMAL_FLOATING_CONSTANT}
/* Charactor */
C_CHAR 							{ESCAPE_SEQUENCE}|[^("\'"|"\\"|"\n")]
C_CHAR_SEQUENCE					{C_CHAR}+
CHARACTER_CONSTANT				L?'{C_CHAR_SEQUENCE}'

/*String literals*/
S_CHAR  						{ESCAPE_SEQUENCE}|[^("\""|"\\"|"\n")]
S_CHAR_SEQUENCE					{S_CHAR}+
STRING_LITERAL 					\042[^\042\n]*\042

CHAR_LEFT 						{DIGIT}|{NONDIGIT}|\.

/*Maybe Header Name*/

/*Preprocessing Number  -- what is that*/

%%
{SINGLE_LINE_COMMENT}  {locate(); }
{MULTI_LINE_COMMENT} {locate(); comment_check();}

{AUTO} { locate(); RETURN_TOKEN(T_AUTO); }
{BREAK} { locate(); RETURN_TOKEN(T_BREAK); }
{CASE} { locate(); RETURN_TOKEN(T_CASE); }
{CHAR} { locate(); RETURN_TOKEN(T_CHAR); }
{CONTINUE} { locate(); RETURN_TOKEN(T_CONTINUE); }
{DO} { locate(); RETURN_TOKEN(T_DO); }
{DOUBLE} { locate(); RETURN_TOKEN(T_DOUBLE); }
{ELSE} { locate(); RETURN_TOKEN(T_ELSE); }
{ENUM} { locate(); RETURN_TOKEN(T_ENUM); }
{EXTERN} { locate(); RETURN_TOKEN(T_EXTERN); }
{FLOAT} { locate(); RETURN_TOKEN(T_FLOAT); }
{FOR} { locate(); RETURN_TOKEN(T_FOR); }
{IF} { locate(); RETURN_TOKEN(T_IF); }
{INT} { locate(); RETURN_TOKEN(T_INT); }
{LONG} { locate(); RETURN_TOKEN(T_LONG); }
{RETURN} { locate(); RETURN_TOKEN(T_RETURN); }
{SHORT} { locate(); RETURN_TOKEN(T_SHORT); }
{SIGNED} { locate(); RETURN_TOKEN(T_SIGNED); }
{SIZEOF} { locate(); RETURN_TOKEN(T_SIZEOF); }
{STRUCT} { locate(); RETURN_TOKEN(T_STRUCT); }
{SWITCH} { locate(); RETURN_TOKEN(T_SWITCH); }
{UNION} { locate(); RETURN_TOKEN(T_UNION); }
{UNSIGNED} { locate(); RETURN_TOKEN(T_UNSIGNED); }
{VOID} { locate(); RETURN_TOKEN(T_VOID); }
{WHILE} { locate(); RETURN_TOKEN(T_WHILE); }
"read" {locate(); RETURN_TOKEN(T_READ);}
"print" {locate(); RETURN_TOKEN(T_PRINT);}


{IDENTIFIER} {locate(); yylval.string_val = new std::string(yytext); RETURN_TOKEN(IDENTIFIER);}
{INTEGER_CONSTANT} {locate(); yylval.string_val = new std::string(yytext); RETURN_TOKEN(INTEGER_LITERAL);}
{FLOATING_CONSTANT} {locate(); yylval.string_val = new std::string(yytext); RETURN_TOKEN(FLOATING_LITERAL);}
{CHARACTER_CONSTANT} {locate(); yylval.string_val = new std::string(yytext); RETURN_TOKEN(CHARACTER_LITERAL);}
{STRING_LITERAL} {locate();  yylval.string_val = new std::string(yytext); RETURN_TOKEN(STRING_LITERAL);}

"&&" {  locate();  RETURN_TOKEN(AND); }
"||" {  locate();  RETURN_TOKEN(OR); }
"<=" {  locate();  RETURN_TOKEN(LEQ); }
">=" {  locate();  RETURN_TOKEN(GEQ); }
"==" {  locate();  RETURN_TOKEN(EQ); }
"!=" {  locate();  RETURN_TOKEN(NE); }

"+" { locate(); RETURN_TOKEN(PLUS); }
"-" { locate(); RETURN_TOKEN(MINUS); }
"*" { locate(); RETURN_TOKEN(STAR); }
"/" { locate(); RETURN_TOKEN(DIV); }
"%" { locate(); RETURN_TOKEN(MOD);}
"=" { locate(); RETURN_TOKEN(ASSIGNOP); }
"<" { locate(); RETURN_TOKEN(LE); }
">" { locate(); RETURN_TOKEN(GE); }
"." { locate(); RETURN_TOKEN(DOT); }
"," { locate(); RETURN_TOKEN(COMMA); }
":" { locate(); RETURN_TOKEN(MAO); }
";" { locate(); RETURN_TOKEN(SEMI); }
"?" { locate(); RETURN_TOKEN(WEN); }

"(" { locate(); RETURN_TOKEN(LP); }
")" { locate(); RETURN_TOKEN(RP); }
"[" { locate(); RETURN_TOKEN(LB); }
"]" { locate(); RETURN_TOKEN(RB); }
"{" { locate(); RETURN_TOKEN(LC); }
"}" { locate(); RETURN_TOKEN(RC); }

"!" { locate(); RETURN_TOKEN(NOT); }
"~" { locate(); RETURN_TOKEN(INV); }

[ \t\v\n\f]		{ locate(); }
.			{locate(); unrecognized_char(yytext[0]); }

%%

int col = 0;
int row = 0;
void locate() {
	for (int i = 0; i < strlen(yytext); ++i){
		if (yytext[i] == '\n') {col = 0, row++; /* printf("\n"); */}
		else if (yytext[i] == '\t') col += 8 - (col % 8);
		else col++;
  }
  row = yylineno;
}

void comment_check() {
	char c, prev = 0;
	while ((c = yyinput()) != 0) {
		if (c == '/' && prev == '*')
			return;
		prev = c;
	}
	yyerror("Syntax Error: Improper Comments");
}

void unrecognized_char(char c) {
    char buf[32] = "Unrecognized character: ?";
    buf[24] = c;
    yyerror(buf);
}

void yyerror(const char* msg) {
    printf("\nSyntax Error at line:%d Col:%d, \n\t %s \n", yylineno, col, msg);
}