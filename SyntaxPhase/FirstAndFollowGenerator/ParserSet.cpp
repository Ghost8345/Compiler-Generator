//
// Created by usef on 12/25/2023.
//

#include "ParserSet.h"
#include "../GrammarParser//Grammar.h"


bool ParserSet::isComputed() {
    return !set.empty();
}

void ParserSet::add(Terminal* t) {
    set.insert(t);
}

void ParserSet::addAll(const ParserSet &s) {
    set.insert(s.set.begin(),s.set.end());
}

void ParserSet::removeEpsilon() {
    set.erase(Grammar::epsilon);
}
