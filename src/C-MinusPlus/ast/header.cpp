//
// Created by wcy on 6/20/21.
//
#include "../include/header.hpp"
int print_cnt = 0;
int error_cnt = 0;
std::vector<std::string> error_msg;
std::ofstream osa, osi;
std::string cur_func_name;
int if_block_stack[1000];
int if_top = 0;
int if_blockid = 0;
int while_block_stack[1000];
int while_top = 0;
int while_blockid = 0;

template <class DestType, class SrcType>
const DestType* check(const SrcType* src, std::string errormsg)
{
    const DestType* dest= dynamic_cast<const DestType*>(src);
    if (dest) { return dest; }
    else {
        error_cnt++;
        error_msg.push_back(errormsg);
        return nullptr;
    }
}

template <class DestType, class SrcType>
DestType * Cast(SrcType* src) {
    return dynamic_cast<DestType*>(src);
}

void print_in_asm(std::ofstream &os, std::string inst, std::string param, std::string ends) {
    os << (inst + " " + param + ends);
}
void print_in_inc(std::ofstream &os, std::string inst, std::string param) {
    os << (inst + " " + param) << std::endl;
}

void raise_error(int y, int x, std::string msg) {
    error_cnt++;
    std::string pos = "Syntax error: line: " + std::to_string(x) + ", col: " + std::to_string(y) + ";\n\t" + msg;
    error_msg.push_back(pos);
}

std::string gen_var_name(std::string funcname, std::string depth, std::string varname) {
    for (int i = 0; i < depth.length(); i++)
        if (depth[i] == '(') depth[i] = '1';
        else depth[i] = '2';
    // std::cerr << funcname + "_" + depth + "_" + varname << std::endl;
    return funcname + "_" + depth + "_" + varname;
}