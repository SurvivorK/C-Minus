////
//// Created by Stellaris on 2021/6/19.
////
//
#include "SymbolTable.hpp"
FuncTable ftable;
SymbolTablePtr globalSymTab = new SymbolTable();
SymbolTablePtr curSymTab = globalSymTab;
std::string bracketSeq = "";

SymbolTable::SymbolTable() {
    prev = curSymTab;
    seq = bracketSeq;
    // curSymTab->childrens.push_back(this);
    // curSymTab = this;
}

void SymbolTable::exitScope() {
    bracketSeq = bracketSeq + ")";
    curSymTab = curSymTab->prev;
}


int SymbolTable::getdepth() {
    int res = 0;
    for (SymbolTablePtr i = curSymTab; i; i = i->prev) {
        res += 1;
    }
    return res;
}
std::string SymbolTable::findnameall(std::string name) {
    std::string res;
    for (SymbolTablePtr i = curSymTab; i; i = i->prev) {
        if ((res = i->findname(name)) != "") return res;
    }
    if ((res = globalSymTab->findname(name)) != "")
        return res;
    return res;
}

std::string SymbolTable::findname(std::string name) {
    if (scope.count(name)) {
        if (this == globalSymTab) return "[" + gen_var_name("global", "", name) + "]";
        return gen_var_name(cur_func_name, seq, name);
    }
    return "";
}
Type* SymbolTable::findall(std::string name) {
    Type* res;
    for (SymbolTablePtr i = curSymTab; i; i = i->prev) {
        if ((res = i->find(name))) return res;
    }
    if ((res = globalSymTab->find(name)))
        return res;

    return nullptr;
}

Type* SymbolTable::find(std::string name) {
    if (scope.count(name) == 0) {
        return nullptr;
    }
    return scope[name];
}

bool SymbolTable::insert(std::string name, Type* type) {
    if (scope.count(name)) {
        return false;
    }
    scope[name] = type;
    return true;
}

std::vector<std::string> SymbolTable::getParams() {
    std::vector<std::string> res;
    for (auto i : scope)
        res.push_back(gen_var_name(cur_func_name, seq, i.first));
    return res;
}

std::vector<std::string> SymbolTable::getAllParams() {

    if (childrens.empty()) return getParams();

    std::vector<std::string> res = getParams();
    for (auto i : childrens) {
        std::vector<std::string> temp = i->getAllParams();
        for (auto j : temp)
            res.push_back(j);
    }
    return res;
}

std::vector<std::string> SymbolTable::getParamsWithoutArgs() {

    if (childrens.empty() && prev) return getParams();
    std::vector<std::string> res;
    if (prev) std::vector<std::string> res = getParams();
    for (auto i : childrens) {
        std::vector<std::string> temp = i->getAllParams();
        for (auto j : temp)
            res.push_back(j);
    }
    return res;
}
bool FuncTable::findFunc(std::string name) {
    if (table.count(name) == 0) return false;
    else return true;
}
FuncType* FuncTable::getFuncType(std::string name) {
    if (!findFunc(name)) return nullptr;
    return table[name];
}

bool FuncTable::insertFunc(std::string name, FuncType *funcType, SymbolTable *field) {
    if (!findFunc(name)) table[name] = funcType, fieldtable[name] = field;
    else {
        return false;
    }
    return true;
}

SymbolTable *FuncTable::getFuncField(std::string name) {
    if (findFunc(name)) return fieldtable[name];
    return nullptr;
}

bool FuncTable::insertFunc(std::string name) {
    if (!findFunc(name)) {
        curSymTab = nullptr;
        bracketSeq = "";
        table[name] = new FuncType();
        curSymTab = fieldtable[name] = new SymbolTable();
    }
    else {
       // raise_error("function '" + name + "' has been declared before.");
        return false;
    }
    return true;
}

