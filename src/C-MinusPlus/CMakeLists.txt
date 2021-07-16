cmake_minimum_required(VERSION 3.10)
project(C_MinusPlus)

set(CMAKE_CXX_STANDARD 11)
add_compile_options(-Wno-deprecated-register -g -O0)
find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

set(LEXER_OUT lexer/lexer.cpp)
set(PARSER_OUT parser/parser.tab.cpp)

flex_target(LEXER lexer/lexer.l ${LEXER_OUT})
bison_target(PARSER parser/parser.y ${PARSER_OUT} DEFINES_FILE parser/parser.tab.h COMPILE_FLAGS "-d -v -t --debug")

set(INCLUDE include/)
aux_source_directory(./ast ast_src)
aux_source_directory(semantic sym_src)

add_executable(C_MinusPlus  main.cpp ${FLEX_LEXER_OUTPUTS} ${BISON_PARSER_OUTPUTS} ${ast_src}  ${sym_src} )
target_include_directories(C_MinusPlus PRIVATE ${CMAKE_CURRENT_BINARY_DIR} ${INCLUDE} "./parser" )
