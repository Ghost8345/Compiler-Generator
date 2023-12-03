//
// Created by usef on 12/2/2023.
//

#ifndef COMPILER_DFA_H
#define COMPILER_DFA_H

#include "../NFAConverter/State.h"
#include "../NFAConverter/NFA.h"
#include <vector>

class DFA {
private:
    NFA nfa;
    State* startState;


public:
    DFA(NFA &nfa);



};

#endif //COMPILER_DFA_H
