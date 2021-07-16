//
// Created by Stellaris on 2021/6/16.
//

#include "../include/Identifier.hpp"

Identifier::Identifier(std::string _name) : name(_name) {}

std::string Identifier::code() const {
    return name;
}

std::string Identifier::getName() const {
    return name;
}


