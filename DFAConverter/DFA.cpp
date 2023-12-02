//
// Created by usef on 12/2/2023.
//

#include "DFA.h"

DFA::DFA(NFA &nfa) {
    this->nfa = nfa;
    this->startState = new State();
    this->transitionTable = {};
}
