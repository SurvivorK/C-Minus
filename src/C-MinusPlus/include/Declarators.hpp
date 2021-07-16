//
// Created by Stellaris on 2021/6/17.
//

#ifndef C99_COMPILER_DECLARATORS_HPP
#define C99_COMPILER_DECLARATORS_HPP

#include "header.hpp"
#include "NodeBase.hpp"
#include "Identifier.hpp"
#include "Types.hpp"
#include "SymbolTable.hpp"
class Declarator;

class InitDeclarator;

class PointerDeclarator;

typedef Declarator* DeclaratorPtr;

class Declarator : public NodeBase{
public:
    virtual std::string code() const = 0;
    void genPcode() = 0;
    // virtual std::string getIdentifierName() const = 0;

};
/**
 * For a ordinary declarator
 * Single identifier
 */
class DirectDeclarator : public Declarator {
public:
    DirectDeclarator(NodeBasePtr identifier);
    NodeBasePtr getIdentifier() const;
    std::string getName();
    std::string code() const override;
    void genPcode() override;
    void predict() override {
        raise_error(col, line, "';' is needed");
    }
};
//class PointerDeclarator : public Declarator {
//public:
//    PointerDeclarator(NodeBasePtr subDeclarator);
//
//    DeclaratorPtr getDeclarator() const;
//    std::string code() const override;
//};
//
//class ArrayDeclarator : public Declarator {
//public:
//    ArrayDeclarator(NodeBasePtr subDeclarator);
//    DeclaratorPtr getDeclarator() const;
//    std::string code() const override;
//};
///**
// * array declarator with unemitable size
// * begin with identifier  a[][][]
// */
//class ArraySizedDeclarator : public Declarator {
//public:
//    ArraySizedDeclarator(NodeBasePtr subDeclarator, NodeBasePtr size);
//    DeclaratorPtr getDeclarator() const;
//    std::string code() const override;
//
//};
//class InitDeclarator : public Declarator {
//public:
//    InitDeclarator(NodeBasePtr declarator, NodeBasePtr exp);
//    std::string code() const override;
//};
/**
 * Declarator of function
 * begin with identifier f(params)
 */
class FunctionDeclarator : public Declarator {
public:
    FunctionDeclarator(NodeBasePtr identifier, NodeBasePtr params);
    FunctionDeclarator(NodeBasePtr identifier);

    std::string getName();
    std::vector<std::string> getParams();
    std::vector<Type*> getTypes();
    bool analysis() override;
    void genPcode() override;
    std::string code() const override;

};

class DeclaratorList;
typedef DeclaratorList* DeclaratorListPtr;

class DeclaratorList : public Declarator {
public:
    DeclaratorList();
    DeclaratorList(NodeBasePtr declarator);
    std::string code() const override;
};
class Parameter;
typedef Parameter* ParameterPtr;

/**
 * Parameter
 * type declarator
 * int a
 */
class Parameter : public Declarator {
public:
    Parameter();
    Parameter(NodeBasePtr type, NodeBasePtr declarator);

    std::string getName() ;
    Type* getType();
    std::string code() const override;
    void genPcode() override;
};

/**
 * List of parameter
 * such as int a, int b, int c....
 */
class ParameterList : public Parameter {
public:
    ParameterList();
    ParameterList(NodeBasePtr param);

    std::vector<std::string> getParams();
    std::vector<Type*> getTypes();
    std::string code() const override;
    void genPcode() override;
    bool analysis() override;
};
#endif //C99_COMPILER_DECLARATORS_HPP
