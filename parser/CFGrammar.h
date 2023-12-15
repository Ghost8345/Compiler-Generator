#ifndef PARSER_CFGRAMMAR_H
#define PARSER_CFGRAMMAR_H

#include "Common.h"
#include "Symbol.h"
#include "Production.h"

class CFGrammar
{
public:
    CFGrammar(std::string definition);

    NonTerminal* startSymbol;
    std::unordered_set<Terminal*> terminals;
    std::unordered_set<NonTerminal*> nonTerminals;
    std::vector<Production*> productions;

    void eliminateLeftRecursion();
    void applyLeftFactoring();
};

#endif