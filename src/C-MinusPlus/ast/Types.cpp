//
// Created by Stellaris on 2021/6/17.
//

#include "Types.hpp"




//StructType::StructType(NodeBasePtr identifier) {
//    childrens.push_back(identifier);
//    childrens.push_back(nullptr);
//}
//
//StructType::StructType(NodeBasePtr identifier, NodeBasePtr declarationlist) {
//    childrens.push_back(identifier);
//    childrens.push_back(declarationlist);
//}
//
//std::string StructType::code() const {
//    std::string res = "struct";
//    if (childrens[0]) res = res + childrens[0]->code();
//    res = res + "{";
//    if (childrens[1]) res = res + childrens[1]->code();
//    res = res + "}";
//    return res;
//}