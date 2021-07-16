//
// Created by Stellaris on 2021/6/17.
//

#include "Declarators.hpp"

DirectDeclarator::DirectDeclarator(NodeBasePtr identifier) {
    childrens.push_back(identifier);
}

NodeBasePtr DirectDeclarator::getIdentifier() const {
    return childrens[0];
}

std::string DirectDeclarator::code() const {
    return getIdentifier()->code();
}

void DirectDeclarator::genPcode() {
}

std::string DirectDeclarator::getName() {
    return dynamic_cast<Identifier*>(childrens[0])->getName();
}
//PointerDeclarator::PointerDeclarator(NodeBasePtr rhs) {
//    childrens.push_back(rhs);
//}
//
//// a pointer must point to a declarator
//DeclaratorPtr PointerDeclarator::getDeclarator() const {
//        DeclaratorPtr res = dynamic_cast<DeclaratorPtr>(childrens[0]);
//        if (res != nullptr) return res;
//        else throw "a pointer must point to a declarator";
//}
//std::string PointerDeclarator::code() const {
//    return "*" + getDeclarator()->code();
//}
//
//ArrayDeclarator::ArrayDeclarator(NodeBasePtr rhs) {
//    childrens.push_back(rhs);
//}
//
//DeclaratorPtr ArrayDeclarator::getDeclarator() const {
//        DeclaratorPtr res = dynamic_cast<DeclaratorPtr>(childrens[0]);
//        if (res != nullptr) return res;
//        else throw "a pointer must point to a declarator";
//}
//
//std::string ArrayDeclarator::code() const {
//    return getDeclarator()->code() + "[]";
//}
//
//ArraySizedDeclarator::ArraySizedDeclarator(NodeBasePtr rhs, NodeBasePtr size) {
//    childrens.push_back(rhs);
//    childrens.push_back(size);
//}
//
//DeclaratorPtr ArraySizedDeclarator::getDeclarator() const {
//        DeclaratorPtr res = dynamic_cast<DeclaratorPtr>(childrens[0]);
//        if (res != nullptr) return res;
//        else throw "a pointer must point to a declarator";
//}
//
//std::string ArraySizedDeclarator::code() const {
//    return getDeclarator()->code() + "[" + childrens[1]->code() + "]";
//}
//
//InitDeclarator::InitDeclarator(NodeBasePtr declarator, NodeBasePtr exp) {
//    childrens.push_back(declarator);
//    childrens.push_back(exp);
//}
//std::string InitDeclarator::code() const {
//    std::string res = childrens[0]->code() + " = " + childrens[1]->code();
//    return res;
//}

/**
 * Function Declarator Part
 */
FunctionDeclarator::FunctionDeclarator(NodeBasePtr identifier, NodeBasePtr params) {
    childrens.push_back(identifier);
    childrens.push_back(params);
}
FunctionDeclarator::FunctionDeclarator(NodeBasePtr identifier) {
    childrens.push_back(identifier);
    childrens.push_back(new ParameterList());
}
std::string FunctionDeclarator::code() const {
    std::string res = "";
    res = res + childrens[0]->code() + "(" + childrens[1]->code() + ")";
    return res;
}

std::string FunctionDeclarator::getName() {
    return dynamic_cast<Identifier*>(childrens[0])->getName();
}

void FunctionDeclarator::genPcode() {
    // asm file
    cur_func_name = getName();
    print_in_asm(osa, "FUNC @"+cur_func_name + ":");
    childrens[1]->genPcode();

    // inc file
    print_in_inc(osi, "; ==== begin function " + cur_func_name + "====");
    std::string inst= "\n%MACRO $" + cur_func_name
            + " 0\n\tCALL @"+ cur_func_name + "\n\tADD ESP, 4*"
            + cur_func_name + ".argc\n\tPUSH EAX\n%ENDMACRO";
    print_in_inc(osi, inst);
}

std::vector<std::string> FunctionDeclarator::getParams() {
    return dynamic_cast<ParameterList*>(childrens[2])->getParams();
}

std::vector<Type *> FunctionDeclarator::getTypes() {
    return dynamic_cast<ParameterList*>(childrens[2])->getTypes();
}

bool FunctionDeclarator::analysis() {
    cur_func_name = getName();
    if (globalSymTab->find(cur_func_name)) {
        raise_error(col, line, "a global variable '" + cur_func_name + "' has been declared before.");
        return false;
    }
    if (ftable.insertFunc(cur_func_name)) {
        // curSymTab = ftable.getFuncField(cur_func_name);
        childrens[1]->analysis();
        return true;
    }
    else {
        raise_error(col, line, "function '" + cur_func_name + "' has been declared before.");
    }
    return false;
}

/**
 * Declarator List Part
 */
DeclaratorList::DeclaratorList() {
    childrens = NodeBaseList{};
}
DeclaratorList::DeclaratorList(NodeBasePtr declarator) {
    childrens.push_back(declarator);
}
std::string DeclaratorList::code() const {
    std::string res = "";
    for (int i = 0; i < childrens.size(); i++) {
        if (i > 0) res = res + ", ";
        res = res + childrens[i]->code();
    }
    return res;
}
/**
 * Parameter Part
 */
Parameter::Parameter() {
    childrens = NodeBaseList {};
}
Parameter::Parameter(NodeBasePtr type, NodeBasePtr declarator) {
    childrens.push_back(type);
    childrens.push_back(declarator);
}

std::string Parameter::code() const {
    std::string res = "";
    res = res + childrens[0]->code() + " " + childrens[1]->code();
    return res;
}

std::string Parameter::getName() {
    return dynamic_cast<DirectDeclarator*>(childrens[1])->getName();
}

void Parameter::genPcode() {

}

Type *Parameter::getType() {
    return dynamic_cast<Type*>(childrens[0]);
}

/**
 * Parameter List
 */
ParameterList::ParameterList() {
    childrens = NodeBaseList {};
}
ParameterList::ParameterList(NodeBasePtr param) {
    childrens.push_back(param);
}
std::string ParameterList::code() const {
    std::string res = "";
    for (int i = 0; i < childrens.size(); i++) {
        if (i > 0) res = res + ", ";
        res = res + childrens[i]->code();
    }
    return res;
}

std::vector<std::string> ParameterList::getParams() {
    std::vector<std::string> res;
    for (auto i : childrens)
        res.push_back(dynamic_cast<Parameter *>(i)->getName());
    return res;
}

void ParameterList::genPcode() {
    SymbolTable *fs = ftable.getFuncField(cur_func_name);
    std::vector<std::string> res = getParams();

    if (res.size() > 0) {
        std::string varlist = "";
        for (int i = 0; i < res.size(); i++) {
            if (i > 0) varlist = varlist + ", ";
            varlist = varlist + fs->findname(res[i]);
        }
        print_in_asm(osa, "\t" + cur_func_name + ".arg ", varlist);
    }

    print_in_inc(osi, "%define " + cur_func_name + ".argc " + std::to_string(res.size()));
    std::string inst;
    if (res.size() > 0) {
        inst = "\n%MACRO "+ cur_func_name + ".arg " + cur_func_name + ".argc";
        print_in_inc(osi, inst);
        for (int i = 0; i < res.size(); i++) {
            inst = "\t%define " + fs->findname(res[i]) + " [EBP + 8 + 4*" + cur_func_name + ".argc - 4*" + std::to_string(i + 1) + "]";
            print_in_inc(osi, inst);
        }
        print_in_inc(osi, "%ENDMACRO");
    }
}

std::vector<Type *> ParameterList::getTypes() {
    std::vector<Type*> res;
    for (auto i : childrens)
        res.push_back(dynamic_cast<Parameter *>(i)->getType());
    return res;
}

bool ParameterList::analysis() {
    FuncType* ft = ftable.getFuncType(cur_func_name);
    SymbolTable *fs = ftable.getFuncField(cur_func_name);

    std::vector<Type*> types = getTypes();
    std::vector<std::string> args = getParams();
    ft->setParamTypes(types);
    bool flag = true;
    for (int i = 0; i < args.size(); i++) {
        if (!fs->insert(args[i], types[i])){
            raise_error(col, line, "Variable '" + args[i] + "' has been declared!");
            flag = false;
        }
    }
    return flag;
}

