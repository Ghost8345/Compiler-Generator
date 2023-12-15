#ifndef PARSER_H
#define PARSER_H

#include "Common.h"
#include "CFGrammar.h"
#include "SyntaxTree.h"
#include "Token.h"


class Parser {
private:
    CFGrammar grammar;
    // TODO: might need hash and compare functions for this map (not sure)
    std::unordered_map<std::pair<Symbol*,Terminal>,Production*> parseTable;
    std::unordered_set<NonTerminal*, std::unordered_set<Terminal*>> firstSet;
    std::unordered_set<NonTerminal*, std::unordered_set<Terminal*>> followSet;
    
    std::unordered_set<Terminal*> first(std::vector<Symbol*> symbols);
    std::unordered_set<Terminal*> follow(std::vector<Symbol*> symbols);
    
    void computeFirstSet();
    void computeFollowSet();
    void constructParseTable();
public:
    Parser(CFGrammar& grammar);
    SyntaxTree parse(std::vector<Token>& input);
};

#endif