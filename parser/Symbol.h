#ifndef PARSER_SYMBOL_H
#define PARSER_SYMBOL_H

#include "Common.h"

class Symbol {
protected:
    Symbol(std::string n, bool t): name(n), terminal(t) {};
private:
    bool terminal;
public:
    std::string name;
    bool isTerminal() { return this->terminal; };
};

class Terminal : public Symbol {
    Terminal(std::string n) : Symbol(n, true) {}
};

class NonTerminal : public Symbol {
    NonTerminal(std::string n) : Symbol(n, false) {}
};

#endif