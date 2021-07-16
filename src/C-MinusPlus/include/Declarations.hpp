//
// Created by Stellaris on 2021/6/17.
//

#ifndef C99_COMPILER_DECLARATIONS_HPP
#define C99_COMPILER_DECLARATIONS_HPP

#include "header.hpp"
#include "NodeBase.hpp"
#include "Declarators.hpp"

class Declarations : public NodeBase{
public:
    Declarations();
    // Type specifier and Declarator List
    Declarations(NodeBasePtr type, NodeBasePtr declaratorListPtr);
    //DeclaratorListPtr getDeclaratorList() const;
    std::string code() const override;
    std::string getName();
    Type* getType();
    void genPcode() override{}
    bool analysis() override;
};

class DeclarationList;

typedef DeclarationList* DeclarationListPtr;
class DeclarationList : public Declarations{
public:
    DeclarationList(NodeBasePtr list);
    DeclarationList();

    std::string code() const override;
    std::vector<std::string> getDeclaratorList() const;
    void genPcode() override;
    bool analysis() override{
        bool flag = true;
        for (auto i : childrens) {
            flag = i->analysis() && flag;
        }
        return flag;
    }
};


#endif //C99_COMPILER_DECLARATIONS_HPP
