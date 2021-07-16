//
// Created by Stellaris on 2021/6/19.
//

#ifndef C_MINUSPLUS_SYMBOLTABLE_HPP
#define C_MINUSPLUS_SYMBOLTABLE_HPP

#include "header.hpp"
#include "Types.hpp"
class SymbolTable;
class Symbol;
typedef SymbolTable* SymbolTablePtr;
typedef Symbol* SymbolPtr;

extern SymbolTablePtr globalSymTab;
extern SymbolTablePtr curSymTab;
extern int curSymDep;
extern std::string bracketSeq;


class FuncTable {
public:
    std::map<std::string, FuncType*> table;
    std::map<std::string, SymbolTable*> fieldtable;
    bool findFunc(std::string name);
    FuncType* getFuncType(std::string name);
    SymbolTable* getFuncField(std::string name);
    bool insertFunc(std::string name);
    bool insertFunc(std::string name, FuncType* funcType, SymbolTable *field);
    FuncTable(){}
};

class SymbolTable {
public:
    SymbolTable();
    SymbolTable(std::string _seq) : seq(_seq){prev = curSymTab;}
    void newScope();
    void exitScope();
    int getdepth();
    std::string findname(std::string name);
    std::string findnameall(std::string name);
    std::vector<std::string> getParams();
    std::vector<std::string> getAllParams();
    std::vector<std::string> getParamsWithoutArgs();
    Type* findall(std::string name);
    Type* find(std::string name);
    bool insert(std::string name, Type* type);

    SymbolTablePtr prev;
    std::vector<SymbolTablePtr> childrens;
    std::map<std::string, Type*> scope;
    std::string seq;
};

extern FuncTable ftable;
#endif //C_MINUSPLUS_SYMBOLTABLE_HPP
