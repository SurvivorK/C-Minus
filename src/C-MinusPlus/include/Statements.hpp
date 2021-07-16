//
// Created by Stellaris on 2021/6/18.
//

#ifndef C_MINUSPLUS_STATEMENT_H
#define C_MINUSPLUS_STATEMENT_H

#include "header.hpp"
#include "NodeBase.hpp"
#include "Declarations.hpp"

class Statement : public NodeBase {
public:
    virtual std::string code() const {};
    virtual void genPcode() {};
    bool analysis() override { return true; };
    virtual Type getType(){ return Type::VOID;}
};

class ForStmt : public Statement{
public:
    ForStmt(NodeBasePtr start, NodeBasePtr condition, NodeBasePtr step, NodeBasePtr block);

    std::string code() const override;
    bool analysis()  override {return true;}
};

class WhileStmt : public Statement {
public:
    WhileStmt(NodeBasePtr condition, NodeBasePtr localblock);
    std::string code() const override;
    void genPcode() override;
    bool analysis()  override;
};

class DoWhileStmt : public Statement{
public:
    DoWhileStmt(NodeBasePtr localblock, NodeBasePtr condition);
    std::string code() const override;

};

class IfStmt : public Statement {
public:
    IfStmt(NodeBasePtr condition, NodeBasePtr trueBlock, NodeBasePtr falseBlock);
    IfStmt(NodeBasePtr condition, NodeBasePtr trueBlock);
    std::string code() const override;
    virtual void genPcode();
    bool analysis() override;
};
class BreakStmt : public Statement{
public:
    std::string code() const override;
    void genPcode() override;
    bool analysis() override {
        if (while_top > 0) return true;
        else {
            raise_error(col, line, "Break can't be used without while;");
            return false;
        }
    }
};
class ContinueStmt: public Statement {
public:
    std::string code() const override;
    void genPcode() override;
    bool analysis() override{
        if (while_top > 0) return true;
        else {
            raise_error(col, line, "Break can't be used without while;");
            return false;
        }
    }
};
// Todo: return type and number check
class ReturnStmt : public Statement {
public:
    ReturnStmt();
    ReturnStmt(NodeBasePtr exp);
    std::string code() const override;
    void genPcode() override;
    Type getType() override{
        Type t = *(ftable.getFuncType(cur_func_name)->retType);
        return t;
    }
    bool analysis() override {
        // if (dynamic_cast<D>(childrens[0])->)
        bool flag = childrens[0]->analysis();
        Type t = *(ftable.getFuncType(cur_func_name)->retType);
        Type tt = dynamic_cast<Statement*>(childrens[0])->getType();
        if (!(tt == t)) {
            if (tt == Type(Type::TERROR))
                raise_error(col, line, "error occur in '" + childrens[0]->code());
            else
            raise_error(col, line, "function '" + cur_func_name + "' returns type " + t.code() + " but here returns " + tt.code());
            return false;
        }
        return flag;
    }
};

class StmtList : public Statement{
public:
    StmtList();
    StmtList(NodeBasePtr singleStmt);

    StmtList(NodeBaseList stmts);

    std::string code() const override;
    void genPcode() override;
    bool analysis() override {
        bool flag = true;
        for (auto i : childrens)
            flag = i->analysis() && flag;
        return flag;
    }
};

class CompStmt : public Statement {
public:
    CompStmt(NodeBasePtr declaration, NodeBasePtr stmtList);
    std::string code() const override;
    virtual void genPcode() ;
    bool analysis() override;
    SymbolTablePtr symptr;

};


#endif //C_MINUSPLUS_STATEMENT_H
