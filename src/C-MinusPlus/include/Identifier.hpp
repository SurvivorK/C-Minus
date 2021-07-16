//
// Created by Stellaris on 2021/6/16.
//

#ifndef C99_COMPILER_IDENTIFIER_H
#define C99_COMPILER_IDENTIFIER_H

#include "header.hpp"
#include "NodeBase.hpp"

class Identifier;
typedef Identifier* IdentifierPtr;

class Identifier: public NodeBase {
public:
    Identifier(std::string _name);

    std::string getName() const;

    std::string code() const override;

    void genPcode() override {
        print_in_asm(osa, "\tpush " + name);
    }

private:
    std::string name;
};

#endif //C99_COMPILER_IDENTIFIER_H
