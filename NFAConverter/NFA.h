//
// Created by deffo on 01/12/23.
//

#ifndef COMPILER_NFA_H
#define COMPILER_NFA_H


#include "../RulesParser/RegularExpression.h"
#include "State.h"
#include <stack>

class NFA {
    private:
        RegularExpression regExp;
        State* startState;
        std::stack<std::stack<State*>> nfaStack;
        bool insideBrackets;

    public:
        NFA(RegularExpression &regExp);
        void addEpsilonTransition(State* from, State* to);
        void addSymbolTransition(State* from, char symbol, State* to);
        void concatenate();
        void disjunction();
        void kleeneClosure();
        void positiveClosure();
        void rebaseStacks();
        State* convertToNFA(const std::string& regex);


};


#endif //COMPILER_NFA_H
