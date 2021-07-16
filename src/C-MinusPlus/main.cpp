#include <iostream>
#include <stdio.h>
#include <fstream>
#include "parser.tab.h"
#include "ast.hpp"

extern FILE* yyin;


void printError() {
    for (auto & i : error_msg) {
        std::cout << i << std::endl;
    }
}
int main(int argc, char ** argv) {
    if (argc > 1) {
        if (!(yyin = fopen(argv[1], "r"))) {
            perror(argv[1]);
            return 1;
        }
    }
    //yydebug = 1;
    NodeBasePtr astroot = parse();
    if (astroot){
        //astroot->printTree();
        astroot->writeDot();
    }
    else {
        // cur_node->predict();
        error_cnt++;
        error_msg.push_back("Syntax error");
        printError();
        return 0;
    }
    astroot->analysis();
    if (!ftable.findFunc("main"))
        raise_error(col, row, "undefined entrance 'main'");
    printError();
    if (error_cnt == 0) {
        // std::cerr << "gen code" << std::endl;
        astroot->writeAsm();
    }
    return 0;
}