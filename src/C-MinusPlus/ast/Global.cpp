//
// Created by Stellaris on 2021/6/17.
//

#include "../include/Global.hpp"

// Gen Pcode for every function
void GlobalDeclarationList::genPcode() {
    for (auto i : childrens) {
        i->genPcode();
    }
}

// Gen Pcode for a function
void GlobalFuncDecl::genPcode()  {
    childrens[1]->genPcode();
    genVarPcode();
    childrens[2]->genPcode();
    print_in_asm(osa, "ENDFUNC@" + cur_func_name + "\n");

    print_in_inc(osi, "\n%MACRO ENDFUNC@"+ cur_func_name + " 0\n\tLEAVE\n\tRET");
    SymbolTable* ft = ftable.getFuncField(cur_func_name);
    std::vector<std::string> params = ft->getParams();

    for (auto i : params)
        print_in_inc(osi, "\t%undef " + i);

    print_in_inc(osi, "%ENDMACRO");
    print_in_inc(osi, "; ==== end function `" + cur_func_name + "`   ====\n");

}

std::string GlobalVarList::code() const {
    std::string res = "";
    for (int i = 0; i < childrens.size(); i++) {
        if (i > 0) res = res + ", ";
        res = res + childrens[i]->code();
    }
    return res;
}
GlobalVarList::GlobalVarList() {
    childrens = NodeBaseList{};
}

bool GlobalVarList::analysis() {
    bool flag = true;
    for (auto i: childrens) {
        flag = i->analysis() && flag;
    }
    return flag;
}
void GlobalVarList::genPcode() {
    for (auto i: childrens) {
        print_in_asm(osa, "var ", "global__" + dynamic_cast<Declarations*>(i)->getName());
    }
}

GlobalFuncDecl::GlobalFuncDecl(NodeBasePtr type, NodeBasePtr funcDec, NodeBasePtr compSt) {
    childrens.push_back(type);
    childrens.push_back(funcDec);
    childrens.push_back(compSt);
}
std::string GlobalFuncDecl::code() const {
    std::string res = childrens[0]->code() + childrens[1]->code() + childrens[2]->code();
    return res;
}


bool GlobalFuncDecl::analysis() {
//    Type *t = getType();
//    FunctionDeclarator* d = getDeclarator();
//    std::string funcName = d->getName();
//
//    std::vector<std::string> params = d->getParams();
//    std::vector<Type*> types = d->getTypes();
//    SymbolTable* st = new SymbolTable();
//    if (ftable.insertFunc(funcName, new FuncType(t, types), st))
//        for (int i = 0; i < params.size(); i++) {
//            st->insert(params[i], types[i]);
//        }
//    childrens[2]->analysis();
    if (childrens[1]->analysis()) {
        Type *t = getType();
        ftable.getFuncType(cur_func_name)->setRetType(t);
        childrens[2]->analysis();
        return true;
    }
    return false;

}

void GlobalFuncDecl::genVarPcode() {
        std::vector<std::string> declors = ftable.getFuncField(cur_func_name)->getParamsWithoutArgs();
        std::string inst = cur_func_name + ".var ";
        if (declors.size() > 0) {
            for (auto i : declors)
                inst = inst + i + ",";
            inst.pop_back();
            print_in_asm(osa, inst);
        }
//        char *instr;
//        print_in_inc(osi, std::string(instr));
        if (declors.size() > 0) {
            print_in_inc(osi, "%define " + cur_func_name + ".varc " + std::to_string(declors.size()));
            inst = "\n%MACRO " + cur_func_name + ".var " + cur_func_name + ".varc";
            print_in_inc(osi, std::string(inst));
            for (int i = 0; i < declors.size(); i++) {
                inst = "\t%define " + declors[i] +
                       " [EBP - 4*" + std::to_string(i + 1) + "]";
                print_in_inc(osi, inst);
            }
            print_in_inc(osi, "\tSUB ESP, 4*" + cur_func_name + ".varc");
            print_in_inc(osi, "%ENDMACRO");
        }
}

//GlobalTypeDecl::GlobalTypeDecl(NodeBasePtr type) {
//    childrens.push_back(type);
//}
//
//std::string GlobalTypeDecl::code() const {
//    return childrens[0]->code() + ';';
//}
//
//
//GlobalVarDecl::GlobalVarDecl(NodeBasePtr type, NodeBasePtr declaratorList) {
//    childrens.push_back(type);
//    childrens.push_back(declaratorList);
//}
//
//std::string GlobalVarDecl::code() const {
//    return childrens[0]->code() + childrens[1]->code();
//}
//


bool GlobalDeclarationList::analysis() {
    bool flag = true;
    for (int i = 0; i < childrens.size(); i++)
        flag = childrens[i]->analysis() && flag;
    //if (childrens[0])
    return flag;
}
