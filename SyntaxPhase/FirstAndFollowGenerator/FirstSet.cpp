//
// Created by usef on 12/25/2023.
//

#include "FirstSet.h"
#include "../GrammarParser//Grammar.h"

bool FirstSet::hasNoEpsilon() {
    return !set.contains(Grammar::epsilon);
}

void FirstSet::addEpsilon() {
    this->add(Grammar::epsilon);
}

bool FirstSet::handleSymbol(Symbol* s) {
    if (s->isTerminal()) {
        this->add(dynamic_cast<Terminal *> (s));
        return true;
    }
    NonTerminal* nt = dynamic_cast<NonTerminal *> (s);
    this->addAll(nt->getFirstSet());
    if (nt->getFirstSet().hasNoEpsilon())
        return true;
    this->removeEpsilon();
    return false;
}