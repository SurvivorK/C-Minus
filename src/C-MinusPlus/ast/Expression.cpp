//
// Created by Stellaris on 2021/6/17.
//

#include "Expression.hpp"
ExpressionList::ExpressionList() {
    childrens = NodeBaseList {};
}
ExpressionList::ExpressionList(NodeBasePtr exp) {
    childrens.push_back(exp);
}
std::string ExpressionList::code() const {
    std::string res = "";
    for (int i = 0; i < childrens.size(); i++) {
        if (i > 0) res = res + ",";
        res = res + childrens[i]->code();
    }
    res = res + ";";
    return res;
}
BinaryOperators::BinaryOperators(NodeBasePtr left, OP op, NodeBasePtr right) {
    childrens.push_back(left);
    childrens.push_back(right);
    this->op = op;
}

std::string BinaryOperators::code() const {
    return childrens[0]->code() + BinaryOperators::OPName[op] + childrens[1]->code();
}

BinaryAssignments::BinaryAssignments(NodeBasePtr left, AssignOP op, NodeBasePtr right) {
    childrens.push_back(left);
    childrens.push_back(right);
    this->op = op;
}

std::string BinaryAssignments::code() const {
    return childrens[0]->code() + BinaryAssignments::AssignOPName[op] + childrens[1]->code();
}
//
//TernaryOperator::TernaryOperator(NodeBasePtr condition, NodeBasePtr trueS, NodeBasePtr falseS) {
//    childrens.push_back(condition);
//    childrens.push_back(trueS);
//    childrens.push_back(falseS);
//}
//std::string TernaryOperator::code() const {
//    return "(" + childrens[0]->code() + ") ? " + childrens[1]->code() + " : " + childrens[2]->code();
//}

UnaryOperators::UnaryOperators(OP _op, NodeBasePtr right) {
    op = _op;
    childrens.push_back(right);
}

std::string UnaryOperators::code() const {
    return UnaryOperators::OPNAME[op] + "(" + childrens[0] ->code() + ")";
}

FunctionCall::FunctionCall(NodeBasePtr identifier) {
    childrens.push_back(identifier);
    childrens.push_back(nullptr);
}
FunctionCall::FunctionCall(NodeBasePtr identifier, NodeBasePtr params) {
    childrens.push_back(identifier);
    childrens.push_back(params);
}

std::string FunctionCall::code() const {
    std::string res = childrens[0]->code() + "(";
    if (childrens[1]) res = res + childrens[1]->code();
    res = res + ")";
    return res;
}

void FunctionCall::genPcode() {
    if (childrens[1]) childrens[1]->genPcode();
    print_in_asm(osa, "\t$" + dynamic_cast<Identifier*>(childrens[0])->getName());
}

Type FunctionCall::getType() {
    FuncType *t = ftable.getFuncType(getName());
    if (t) return *(t->retType);
    else return Type(Type::TERROR);
}
std::string FunctionCall::getName() {
    return dynamic_cast<Identifier*>(childrens[0])->getName();
}

bool FunctionCall::analysis() {
    std::string funcname = getName();
    if (funcname == "main") {
        raise_error(col, line, "can't call function 'main'");
        return false;
    }
    if (!ftable.findFunc(funcname)) {
        raise_error(col, line, "function " + funcname + " has not been declared.");
        return false;
    }
    bool flag = true;
    std::vector<Type> t;
    if (childrens[1]){
        flag = childrens[1]->analysis();
        t = dynamic_cast<ExpressionList*>(childrens[1])->getTypes();
    }
    std::vector<Type*> ft = ftable.getFuncType(getName())->paramTypes;
    if (ft.size() != t.size()) {
        raise_error(col, line, "function " + getName() + " requires " + std::to_string(ft.size()) + " arguments, but " + std::to_string(t.size()) + " provided" );
        return false;
    }
    for (int i = 0; i < ft.size(); i++) {
        if (!(*(ft[i]) == (t[i]))) {
            raise_error(col, line, "function " + getName() + " requires " + (ft[i]->code()) + " but " + (t[i].code()) + " provided");
            flag = false;
        }
    }
    return flag;
}
//
//ArrayReference::ArrayReference(NodeBasePtr left, NodeBasePtr right) {
//    childrens.push_back(left);
//    childrens.push_back(right);
//}
//
//std::string ArrayReference::code() const {
//    return childrens[0]->code() + "[" + childrens[1]->code() + "]";
//}
//
//StructReference::StructReference(NodeBasePtr exp, NodeBasePtr identifier) {
//    childrens.push_back(exp);
//    childrens.push_back(identifier);
//}
//std::string StructReference::code() const {
//    std::string res = childrens[0]->code() + "." + childrens[1]->code();
//    return res;
//}
//
//Constants::Constants(Constants::ValueType _type,std::string _value) : valueType(_type), value(_value){
//    std::cout << code();
//}

std::string Constants::code() const {
    return value;
}



//Identifier * Operators::getIdentifier() {
//    return Cast<Identifier>(childrens[0]);
//}

// Gen P code for expression list
void ExpressionList::genPcode() {
    for (auto i : childrens)
        i->genPcode();
}

bool ExpressionList::analysis() {
    bool flag = true;
    for (auto i : childrens)
        flag = i->analysis() && flag;
    return flag;
}

std::vector<Type> ExpressionList::getTypes() {
    std::vector<Type> res;
    for (auto i : childrens)
        res.push_back((dynamic_cast<Expression*>(i)->getType()));
    return res;
}

//Type ExpressionList::getType() {
//    return
//}

// Gen P code for binary operators
void BinaryOperators::genPcode() {
    for (auto i: childrens)
        i->genPcode();
    print_in_asm(osa, "\t"+ OPinst[op]);
}

bool BinaryOperators::analysis() {
    bool flag = childrens[0]->analysis();
    flag = childrens[1] -> analysis() && flag;
    Expression  *ch0 = dynamic_cast<Expression*>(childrens[0]),
                *ch1 = dynamic_cast<Expression*>(childrens[1]);
    if (ch0->getType() == ch1->getType() && ch0->getType().getType() != Type::TERROR) {
        expType = ch0->getType();
    }
    else {
        if (!(ch0->getType() == ch1->getType())) {
            raise_error(col, line, "Invalid conversion from " + ch1->getType().code() + " to " + ch0->getType().code());
        }
        flag = false;
        expType = Type::TERROR;
    }
    return flag;
}

// Gen P code for assign operators
void BinaryAssignments::genPcode() {
    childrens[1]->genPcode();
    print_in_asm(osa, "\tpop", dynamic_cast<ExpID*>(childrens[0])->getName(), "\n");

}

bool BinaryAssignments::analysis() {
    Expression *ch0 = dynamic_cast<Expression*>(childrens[0]),
               *ch1 = dynamic_cast<Expression*>(childrens[1]);
    bool flag = ch0->analysis();
    flag = ch1 -> analysis() && flag;
    if (!ch0->isLValue()) {
        raise_error(col, line, ch0->code() + " is not a left value!");
        flag = false;
    }
    if (ch0->getType() == Type::TERROR || ch1->getType() == Type::TERROR) {
        flag = false;
    }
    else if (!(ch0->getType() == ch1->getType())) {
        raise_error(col, line, "Can't assign " + ch1->getType().code() + " to " + ch0->getType().code() + ".");
        flag = false;
    }
    if (!flag) expType = Type(Type::TERROR);
    else expType = ch0->getType();
    return flag;
}

// Gen P code for unary operators
void UnaryOperators::genPcode() {
    childrens[0]->genPcode();
    print_in_asm(osa, "\t"+OPinst[op]);
}

bool UnaryOperators::analysis() {
    Expression *ch0 = dynamic_cast<Expression*>(childrens[0]);
    bool flag = ch0->analysis();
    if (!flag) {
        expType = Type(Type::TERROR);
        return flag;
    }
    if (ch0->getType().getType() != Type::INT) {
        raise_error(col, line, getOP() + " expected integer but not " + ch0->getType().code() + ".");
        expType = Type(Type::TERROR);
        return false;
    }
    expType = Type(Type::INT);
    return true;
}

// Gen P code for constants
void Constants::genPcode() {
    print_in_asm(osa, "\tpush", value);
}

Constants::Constants(Type::VARTYPE _type, std::string _value) : value(_value){
    expType = _type;
}



//
bool ExpID::analysis() {

    Type* temp;
    if ((temp = curSymTab->findall(name))) {
        expType = (*temp);
        return true;
    }
    if ((temp = globalSymTab->findall(name))) {
        expType = *temp;
        return true;
    }
    raise_error(col, line, "Variable " + name + " has not been declared!");
    expType = Type(Type::VARTYPE::TERROR);
    return false;
}

std::string ExpID::getName() {
    return curSymTab->findnameall(name);
}


PrintStmt::PrintStmt(NodeBasePtr string, NodeBasePtr args) {
    childrens.push_back(string);
    childrens.push_back(args);
}


std::string PrintStmt::code() const {
    return "print(" + childrens[0]->code() + "," + childrens[1]->code() + ")";
}

// Gen P code part
// Gen P code for print

void PrintStmt::genPcode() {
    childrens[1]->genPcode();
    print_in_asm(osa, "\tprint", childrens[0]->code());
//    print_cnt++;
//    print_in_asm(osa, "[SECTION .DATA]\n"
//                      "        STRING" + std::to_string(print_cnt) + ":   DB " + childrens[0]->code() +  ", 10, 0\n"
//                      "    [SECTION .TEXT]\n"
//                      "        PUSH DWORD STRING" + std::to_string(print_cnt) + "\n"
//                      "        CALL printf\n"
//                      "        SHL EAX, 2\n"
//                      "        ADD ESP, EAX");
}