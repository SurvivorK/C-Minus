#include "../include/NodeBase.hpp"
#include <stdio.h>
#include <sstream>
#include <algorithm>
#include "Expression.hpp"
NodeBase* cur_node;
void NodeBase::printTree(int depth) const {
    for (int i = 0; i < depth; i++) std::cout << "\t";
    std::cout << "[" << typeid(*this).name() << "]";
    for (int i = 0; i < childrens.size(); i++) if(childrens[i]) {
        puts("");
        childrens[i]->printTree(depth + 1);
    }
}

std::string NodeBase::generateID() const {
    const void *ptr = reinterpret_cast<const void *>(this);
    std::stringstream ss;
    ss << "ID" << ptr;
    return ss.str();
}

std::string NodeBase::generateLabel() const {
    std::stringstream ss;
    ss << "<";
    ss << typeid(*this).name();
    if (childrens.empty())
        ss << "<font color='red'><b><br/>" << code() << "</b></font>";
    if (dynamic_cast<const Operators*>(this)) {
        const Operators* res = dynamic_cast<const Operators*>(this);
        ss << "<font color='red'><b><br/>" << "\"OP\"" << "</b></font>";
    }
    ss << ">";
    return ss.str();
}

void NodeBase::generateGraph(std::ostream &os) const {
    // std::cerr << generateLabel() << std::endl;
    os << generateID() << " [label=" << generateLabel() << "]" << std::endl;
    for (int i = 0; i < childrens.size(); i++) if (childrens[i]) {
        os << generateID() << "->" << childrens[i]->generateID() << ";" << std::endl;
        childrens[i]->generateGraph(os);
    }
}

void NodeBase::writeDot(std::string filename) const {
    std::ofstream file(filename, std::ios::out | std::ios::trunc);
    file << "digraph AST { \n";
    generateGraph(file);
    file << "\n}";
    file.close();
}

NodeBase::~NodeBase() {
    for (int i = 0; i < childrens.size(); i++) 
        delete childrens[i];
}

void NodeBase::writeAsm() {
    osa = std::ofstream("./bin/a.asm", std::ios::out | std::ios::trunc);
    osi = std::ofstream("./bin/a.inc", std::ios::out | std::ios::trunc);
    genPcode();
}

bool NodeBase::analysis() {
    bool flag = true;
    for (auto i : childrens)
        flag = i->analysis() && flag;
    return flag;
}

void NodeBase::genPcode() {
    for (auto i: childrens)
        i->genPcode();
}

//bool NodeBase::genSymbol() {
//
//}

