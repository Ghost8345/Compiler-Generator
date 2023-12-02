//
// Created by deffo on 01/12/23.
//

#include "NFA.h"

NFA::NFA(RegularExpression &regExp) {
    this->regExp = regExp;
    this->startState = new State();
}

void NFA::addEpsilonTransition(State* from, State* to) {
    Transition transition('\0', to);
    from->addTransition(transition);
}
void NFA::addSymbolTransition(State* from, char symbol, State* to){
    Transition transition(symbol, to);
    from->addTransition(transition);
}
void NFA::concatenate(){
    
}


