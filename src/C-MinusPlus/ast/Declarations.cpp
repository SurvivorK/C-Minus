//
// Created by Stellaris on 2021/6/17.
//

#include "Declarations.hpp"

Declarations::Declarations() {
    childrens = NodeBaseList {};
}
//Declarations::Declarations(NodeBasePtr type) {
//    childrens.push_back(type);
//}
Declarations::Declarations(NodeBasePtr type, NodeBasePtr declarator) {
    childrens.push_back(type);
    childrens.push_back(declarator);
}
std::string Declarations::code() const {
    std::string res = childrens[0]->code() + " " + childrens[1]->code();
}

bool Declarations::analysis() {
    //SymbolTable* st = ftable.getFuncField(cur_func_name);
    std::string name = getName();
    if (ftable.findFunc(name)) {
        raise_error(col, line, "Function " + name + "()" + " has been declared!");
        return false;
    }
//    if (st->findall(name)) {
//        raise_error("Variable " + name + " has been declared!");
//        return false;
//    }
    if (curSymTab->insert(name, getType())){
       return true;
    }
    else {
        raise_error(col, line, "Varaiable " + name + " has been declared!");
        return false;
    }
}

std::string Declarations::getName() {
    return dynamic_cast<DirectDeclarator*>(childrens[1])->getName();
}

Type *Declarations::getType() {
    return dynamic_cast<Type*>(childrens[0]);
}
//DeclaratorListPtr Declarations::getDeclaratorList() const{
//    DeclaratorListPtr res;
//    if (childrens.size() > 1) {
//        res = dynamic_cast<DeclaratorListPtr>(childrens[1]);
//        if (res) return res;
//        else throw "must be a declarator list";
//    }
//    else return nullptr;
//}

//std::string Declarations::code() const {
//    std::string res = "";
//    res = childrens[0]->code() + " " ;
//    if (getDeclaratorList()) {
//        res = res + getDeclaratorList()->code();
//    }
//    res = res + "\n";
//    return res;
//
//}

DeclarationList::DeclarationList() {
    childrens = NodeBaseList{};
}
DeclarationList::DeclarationList(NodeBasePtr list) {
    childrens.push_back(list);
}
std::string DeclarationList::code() const {
    std::string res = "";
    for (int i = 0; i < childrens.size(); i++) {
        if (i > 0) res = res + "; ";
        res = res + childrens[i]->code();
    }
    return res;
}

void DeclarationList::genPcode() {

}

std::vector<std::string> DeclarationList::getDeclaratorList() const {
    std::vector<std::string> res;
    for (auto i : childrens) {
        res.push_back(i->childrens[1]->code());
    }
    return res;
}
