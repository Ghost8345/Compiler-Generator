#ifndef PARSER_PRODUCTION_H
#define PARSER_PRODUCTION_H

#include "Common.h"
#include "Symbol.h"

class Production {
public:
    NonTerminal* lhs;
    std::vector<Symbol*> rhs;
    Production(NonTerminal* l, std::vector<Symbol*> r): lhs(l), rhs(r) {};
};

#endif