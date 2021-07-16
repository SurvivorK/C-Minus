//
// Created by Stellaris on 2021/6/18.
//

#include "Statements.hpp"

ForStmt::ForStmt(NodeBasePtr start, NodeBasePtr condition, NodeBasePtr step, NodeBasePtr block) {
    childrens.push_back(start);
    childrens.push_back(condition);
    childrens.push_back(step);
    childrens.push_back(block);
}

std::string ForStmt::code() const {
    std::string res = "for (";
    res = res + childrens[0]->code() + "; " + childrens[1]->code() + "; " + childrens[2]->code() + ") " + childrens[3]->code();
    return res;
}

WhileStmt::WhileStmt(NodeBasePtr condition, NodeBasePtr localblock) {
    childrens.push_back(condition);
    childrens.push_back(localblock);
}

std::string WhileStmt::code() const {
    std::string res = "while (" + childrens[0]->code() + ")" + childrens[1]->code();
    return res;
}

void WhileStmt::genPcode() {
    while_block_stack[++while_top] = ++while_blockid;
    print_in_asm(osa, "_begWhile_" + std::to_string(cur_while_id) + ":");
    if (childrens[0]) childrens[0]->genPcode();
    print_in_asm(osa, "\tjz _endWhile_" + std::to_string(cur_while_id));
    if (childrens[1]) childrens[1]->genPcode();
    print_in_asm(osa, "\tjmp _begWhile_" + std::to_string(cur_while_id) + "\n_endWhile_" + std::to_string(cur_while_id) + ":");
    while_top--;
}

bool WhileStmt::analysis() {
    while_top++;
    bool flag = childrens[0]->analysis();
    flag = childrens[1]->analysis() && flag;
    while_top--;
    return flag;
}

DoWhileStmt::DoWhileStmt(NodeBasePtr localblock, NodeBasePtr condition) {
    childrens.push_back(localblock);
    childrens.push_back(condition);
}
std::string DoWhileStmt::code() const {
    std::string res = "do" + childrens[0]->code() + childrens[1]->code();
    return res;
}

IfStmt::IfStmt(NodeBasePtr condition, NodeBasePtr trueBlock) {
    childrens.push_back(condition);
    childrens.push_back(trueBlock);
    childrens.push_back(nullptr);
}
IfStmt::IfStmt(NodeBasePtr condition, NodeBasePtr trueBlock, NodeBasePtr falseBlock) {
    childrens.push_back(condition);
    childrens.push_back(trueBlock);
    childrens.push_back(falseBlock);
}
std::string IfStmt::code() const {
    std::string res = "if (" + childrens[0]->code() + ")" + childrens[1]->code() + ";\n";
    if (childrens[2])
        res = res + "else " +  childrens[2]->code() + ";";
    return res;
}

void IfStmt::genPcode() {
    if_block_stack[++if_top] = ++if_blockid;
    print_in_asm(osa, "_begIf_" + std::to_string(cur_if_id) + ":");
    if (childrens[0]) childrens[0]->genPcode();
    print_in_asm(osa, "\tjz _elIf_" + std::to_string(cur_if_id));
    if (childrens[1]) childrens[1]->genPcode();
    print_in_asm(osa, "\tjmp _endIf_" + std::to_string(cur_if_id) + "\n_elIf_" + std::to_string(cur_if_id) + ":");
    if (childrens[2]) childrens[2]->genPcode();
    print_in_asm(osa, "_endIf_" + std::to_string(cur_if_id) + ":");
    if_top--;
}

bool IfStmt::analysis() {
    if_top++;
    bool res = childrens[0]->analysis();
    if (childrens[1]) res = childrens[1]->analysis() && res;
    if (childrens[2]) res = childrens[2]->analysis() && res;
    if_top--;
    return res;
}

ReturnStmt::ReturnStmt(NodeBasePtr exp) {
    childrens.push_back(exp);
}
std::string ReturnStmt::code() const {
    std::string res = "return " + childrens[0] ->code() + ";";
    return res;
}

void ReturnStmt::genPcode() {
    if (childrens[0]) {
        childrens[0]->genPcode();
        print_in_asm(osa, "\tret ~");
    }
    else print_in_asm(osa, "\tret");
}

ReturnStmt::ReturnStmt() {
}

StmtList::StmtList() {}
StmtList::StmtList(NodeBasePtr singleStmt) {
    childrens.push_back(singleStmt);
}
StmtList::StmtList(NodeBaseList stmts) {
    childrens = stmts;
}

std::string StmtList::code() const {
    std::string res = "";
    for (int i = 0; i < childrens.size(); i++)
        res = res + childrens[i]->code();
    return res;
}

void StmtList::genPcode() {
    for (auto i: childrens)
        if (i) i->genPcode();
}

CompStmt::CompStmt(NodeBasePtr declaration, NodeBasePtr stmtList) {
    childrens.push_back(declaration);
    childrens.push_back(stmtList);
}

std::string CompStmt::code() const {
    std::string res = "{\n";
    res = res + childrens[0]->code() + "\n";
    res = res + childrens[1]->code() + "\n";
    res = res + "}\n";
    return res;
}

void CompStmt::genPcode() {
    curSymTab = symptr;
    if (childrens[0]) childrens[0]->genPcode();
    if (childrens[1]) childrens[1]->genPcode();
    curSymTab = curSymTab->prev;
}

bool CompStmt::analysis() {

    bracketSeq = bracketSeq + "(";
    // std::cerr << bracketSeq << std::endl;
    SymbolTablePtr temp = new SymbolTable(bracketSeq);

    curSymTab->childrens.push_back(temp);
    curSymTab = temp;
    symptr = curSymTab;
    bool flag = childrens[0]->analysis();
    flag = childrens[1]->analysis() && flag;

    bracketSeq = bracketSeq + ")";
    // std::cerr << bracketSeq << std::endl;
    curSymTab = curSymTab->prev;
    return flag;
}

std::string BreakStmt::code() const {
    return "break;";
}

void BreakStmt::genPcode() {
    print_in_asm(osa, "\tjmp _endWhile_" + std::to_string(cur_while_id));
}

std::string ContinueStmt::code() const {
    return "continue;";
}

void ContinueStmt::genPcode() {
    print_in_asm(osa, "\tjmp _begWhile_" + std::to_string(cur_while_id));
}



//