//
// Created by Stellaris on 2021/6/17.
//

#ifndef C99_COMPILER_BLOCKS_HPP
#define C99_COMPILER_BLOCKS_HPP

#include "header.hpp"
#include "SymbolTable.hpp"
#include "NodeBase.hpp"
#include "Declarators.hpp"
#include "Statements.hpp"
#include "Types.hpp"

class GlobalDeclaration : public NodeBase {
public:
    std::string code() const = 0;
    void genPcode() override = 0;
    bool analysis() override {return true;};

};
class GlobalDeclarationList : public GlobalDeclaration {
public:
    GlobalDeclarationList() {
        childrens = NodeBaseList{};
    }
    std::string code() const override {
        std::string res = "";
        for (int i = 0; i < childrens.size(); i++)
            res = res + childrens[i]->code();
        return res;
    }
    void genPcode() override;
    bool analysis() override ;

};
//class GlobalVarDecl : public GlobalDeclaration {
//public:
//    GlobalVarDecl(NodeBasePtr type, NodeBasePtr declaratorList);
//    std::string code() const override;
//    void genPcode() override {
//        print_in_asm(osa, "var ", "global_" + )
//    }
//};
//class GlobalTypeDecl : public GlobalDeclaration {
//public:
//    GlobalTypeDecl(NodeBasePtr type);
//    std::string code() const override;
//    void genPcode() const override{}
//};
class GlobalFuncDecl: public GlobalDeclaration {
public:
    // type funcdeclarator funcbody
    GlobalFuncDecl(NodeBasePtr type, NodeBasePtr funcDec, NodeBasePtr compSt);
    std::string code() const override;
    void genPcode() override;
    bool analysis() override;
    Type* getType() { return dynamic_cast<Type*>(childrens[0]);}
    FunctionDeclarator* getDeclarator()  {return dynamic_cast<FunctionDeclarator*>(childrens[1]);}
    void genVarPcode();
};
class GlobalVarList : public GlobalDeclaration {
public:
    GlobalVarList();
    std::string code() const override;
    bool analysis() override;
    void genPcode() override;
};

#endif //C99_COMPILER_BLOCKS_HPP
