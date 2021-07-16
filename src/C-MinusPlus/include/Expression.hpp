//
// Created by Stellaris on 2021/6/17.
//

#ifndef C_MINUSPLUS_EXPRESSION_HPP
#define C_MINUSPLUS_EXPRESSION_HPP

#include "header.hpp"
#include "NodeBase.hpp"
#include "Statements.hpp"
#include "Identifier.hpp"
#include "Types.hpp"
class Expression;

class Operators;

class BinaryAssignments;

class BinaryOperators;

class TernaryOperators;

class UnaryOperators;

class Expression : public Statement {
public:
    virtual std::string code() const {};
    void genPcode() override {};
    bool analysis() override {};
    Type expType;
    virtual bool isLValue() const {};
    Type getType() override {return expType;};
};
class ExpressionList : public Expression {
public:
    ExpressionList(NodeBasePtr exp);
    ExpressionList();
    std::string code() const override;
    void genPcode() override;
    bool analysis() override;
    std::vector<Type> getTypes();
    // Type getType() override;
    virtual bool isLValue() const {return false;}
};
class Operators : public Expression {
public:
    virtual std::string getOP() const = 0;
    void genPcode() override {}
    bool analysis() override {}
    bool isLValue() const override {return false;}
};
class BinaryOperators: public Operators{
public :
    enum OP {
        GE, LE, ADD, SUB, MUL, DIV, MOD,
        BITOR, BITAND, BITXOR,
        LOGOR, LOGAND,
        EQ, NEQ, GEQ, LEQ,
        SHR, SHL,
    };
    const std::string OPName[18] = {">", "<", "+", "-", "*", "/", "%",
                                    "|", "&", "^",
                                    "||", "&&",
                                    "==", "!=", ">=", "<=",
                                    ">>", "<<"};
    const std::string OPinst[18] = {"cmpgt", "cmplt", "add", "sub", "mul",
                                    "div", "mod", "bitor", "bitand", "bitxor",
                                    "or", "and",
                                    "cmpeq", "cmpne", "cmpge", "cmple"};

    BinaryOperators(NodeBasePtr left, OP op,NodeBasePtr right);
    std::string code() const override;
    std::string getOP() const override { return OPName[op];}
    void genPcode() override;
    bool analysis() override;
private:
    OP op;
};

class BinaryAssignments: public Operators {
public:
    enum AssignOP {
        ASSIGNEQ, ADDEQ, SUBEQ, MULEQ, DIVEQ, MODEQ,
        ANDEQ, XOREQ, OREQ,
        SHLEQ, SHREQ
    };
    const std::string AssignOPName[11] = {"=", "+=", "-=", "*=", "/=", "%=", "&=", "^=", "|=", "<<=", ">>="};
    BinaryAssignments(NodeBasePtr left, AssignOP op,NodeBasePtr right);
    std::string getOP() const override { return AssignOPName[op];}
    std::string code() const override;
    void genPcode() override ;
    bool analysis() override;

private:
    AssignOP op;
};

class UnaryOperators : public Operators{
public:
    enum OP {
        SUB, NOT
    };
    const std::string OPNAME[2] = {"-", "!"};
    const std::string OPinst[2] = {"neg", "not"};
    UnaryOperators(OP _op, NodeBasePtr right);
    std::string getOP() const override { return OPNAME[op];}
    std::string code() const override;
    void genPcode() override ;
    bool analysis() override;
private:
    OP op;
};

//class TernaryOperator: public Operators{
//public:
//    TernaryOperator(NodeBasePtr condition, NodeBasePtr trueS, NodeBasePtr falseS);
//    std::string code() const override;
//    virtual void genPcode() {};
//};

// function analysis
class FunctionCall : public Expression {
public:
    FunctionCall(NodeBasePtr identifier, NodeBasePtr params);
    FunctionCall(NodeBasePtr identifier);
    std::string code() const override;
    std::string getName();
    void genPcode() override ;
    bool analysis() override;
    Type getType() override;
};

//class ArrayReference : public Expression {
//public:
//    ArrayReference(NodeBasePtr left, NodeBasePtr right);
//    std::string code() const override;
//    virtual void genPcode() {};
//};
//
//class StructReference : public Expression {
//public:
//    StructReference(NodeBasePtr exp, NodeBasePtr identifier);
//    std::string code() const override;
//    virtual void genPcode() {};
//};
class ReadInt : public Expression {
public:
    ReadInt(){
        // std::cerr << "fuck here" << std::endl;
    }
    std::string code() const override {
        return "read";
    }
    bool isLValue() const override { return false;}
    bool analysis() override {return true;}
    void genPcode() override {
        print_in_asm(osa, "\treadint", " \"\"");
    }
    Type getType() override { return Type(Type::INT); }
};
class Constants;

class Constants : public Expression {
public:

    enum ValueType {
        INTEGER, FLOAT, CHAR, STRING
    };
    const std::string ValueTypeName[4] = {"int", "float", "char", "string"};

    Constants(Type::VARTYPE _type, std::string _value);
    std::string code() const override;
    void genPcode() override ;
    bool isLValue() const override {return false;}
    bool analysis() override {return true;}
    std::string value;
};

// identifier in expression
class ExpID : public Expression {
public:
    ExpID(std::string _name) : name(_name) {};

    // 1. if exist 2. if conflict with func 3. init exptype
    bool analysis() override;
    // Type::VARTYPE getType() override;
    bool isLValue() const override {return true;}
    std::string getName();
    void genPcode() override {
        print_in_asm(osa, "\tpush " + getName());
    }
    std::string code() const override {
        return name;
    }
    std::string name;
};

class PrintStmt : public Expression{
public:
    PrintStmt(NodeBasePtr string, NodeBasePtr args);
    std::string code() const override;
    bool analysis() override {
        bool flag = childrens[1]->analysis();
        std::vector<Type> t = dynamic_cast<ExpressionList*>(childrens[1])->getTypes();
        for (auto i: t)
        if (!(i == Type(Type::INT))) {
            raise_error(col, line, "function print() needs integer arguments" );
            return false;
        }
        return flag;
    }
    void genPcode() override;
};
#endif //C_MINUSPLUS_EXPRESSION_HPP
