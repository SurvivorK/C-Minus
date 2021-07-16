#ifndef ast_hpp
#define ast_hpp

#include "header.hpp"
#include "NodeBase.hpp"
#include "Global.hpp"
#include "Declarators.hpp"
#include "Declarations.hpp"
#include "Identifier.hpp"
#include "Statements.hpp"
#include "Expression.hpp"
#include "Types.hpp"
#include "SymbolTable.hpp"

extern NodeBase* parseAST();
#endif 
 