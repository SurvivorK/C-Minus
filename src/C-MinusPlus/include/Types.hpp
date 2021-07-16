//
// Created by Stellaris on 2021/6/17.
//

#ifndef C99_COMPILER_TYPES_HPP
#define C99_COMPILER_TYPES_HPP

#include "header.hpp"
#include "NodeBase.hpp"

//class VarType;
//// class ArrayType;
//
//
//
//class VarType {
//public:
//    enum TYPE {Var, ARRAY};
//    enum VarTYPE {VOID, INT, FLOAT, DOUBLE, CHAR, LONG};
//    class ArrayType {
//    public:
//        VarType* arrayType;
//        int size;
//        bool operator == (const ArrayType & t)  const {
//            return size == t.size && (*arrayType) == *(t.arrayType);
//        }
//    };
//    TYPE varType;
//
//    VarTYPE ptype;
//    ArrayType* atype;
//
//    VarType(TYPE _varType, VarTYPE _ptype): varType(_varType), ptype(_ptype){}
//
//    bool operator == (const VarType & t) const {
//        if (varType != t.varType) return false;
//        switch (varType) {
//            case Var:
//                return ptype == t.ptype;
//            case ARRAY:
//                return *atype == *(t.atype);
//        }
//    }
//};



class Type;
const std::string VarTypeName[4] = {"void", "int", "string", "Type Error"};
class Type : public NodeBase{
public:
    enum VARTYPE {VOID , INT, STRING, TERROR};

    std::string code() const { return VarTypeName[type]; };
    void genPcode() override {}
    Type() {type = VARTYPE::VOID;}
    Type(const Type &t) {
        type = t.type;
    }
    Type(Type::VARTYPE _type) : type(_type) {};
    VARTYPE getType() const {return type;}
    VARTYPE type;
    bool operator == (Type const & t) const {
        return type == t.type;
    }
};

class FuncType{
public:
    Type* retType;
    int paramCnt;
    std::vector<Type*> paramTypes;
    bool operator == (const FuncType & t) const{
        return retType == (t.retType) && paramCnt == t.paramCnt && paramTypes == t.paramTypes;
    }
    FuncType(){}
    FuncType(Type* t, std::vector<Type*> types) : retType(t), paramTypes(types) {
        paramCnt = types.size();
    }
    void setRetType(Type* t) { retType = t; }
    void setParamTypes(std::vector<Type*> types) {
        paramTypes = types;
        paramCnt = types.size();
    }

};
//class StructType : public Type {
//public:
//
//    StructType(NodeBasePtr identifier, NodeBasePtr declarationlist);
//    StructType(NodeBasePtr identifier);
//
//    std::string code() const override;
//};

#endif //C99_COMPILER_TYPES_HPP
