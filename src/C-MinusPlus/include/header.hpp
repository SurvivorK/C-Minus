#ifndef utils_hpp
#define utils_hpp

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <map>

extern int print_cnt;
extern int error_cnt;
extern std::vector<std::string> error_msg;
extern std::ofstream osa, osi;
extern std::string cur_func_name;
extern int if_block_stack[1000];
extern int if_top;
extern int if_blockid;
extern int while_block_stack[1000];
extern int while_top;
extern int while_blockid;
#define cur_if_id if_block_stack[if_top]
#define cur_while_id while_block_stack[while_top]

template <class DestType, class SrcType>
const DestType* check(const SrcType* src, std::string errormsg);

template <class DestType, class SrcType>
DestType * Cast(SrcType* src);

std::string gen_var_name(std::string funcname, std::string depth, std::string varname);

void raise_error(int x, int y, std::string msg);
void print_in_asm(std::ofstream &os, std::string inst, std::string param = "", std::string ends = "\n");

void print_in_inc(std::ofstream &os, std::string inst, std::string param = "");
#endif