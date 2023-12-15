#ifndef PARSER_SYNTAX_TREE_H
#define PARSER_SYNTAX_TREE_H

#include "Common.h"
#include "Symbol.h"

class SyntaxTreeNode
{
private:
    Symbol *symbol;
    std::vector<Symbol *> children;
};

class SyntaxTreeLeafNode : SyntaxTreeNode
{
private:
    std::string lexeme;
};

class SyntaxTree
{
private:
    SyntaxTreeNode *root;

public:
    SyntaxTree(SyntaxTreeNode *r) : root(r){};
    void print();
};

#endif