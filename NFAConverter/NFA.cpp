//
// Created by deffo on 01/12/23.
//

#include "NFA.h"

NFA::NFA(RegularExpression &regExp) {
    this->regExp = regExp;
    this->startState = new State();
    this->insideBrackets = false;
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
    if(nfaStack.size() == 2){ return;}

    State* end2 = nfaStack.top().top();
    nfaStack.pop();
    State* start2 = nfaStack.top().top();
    nfaStack.top().pop();

    State* end1 = nfaStack.top().top();
    nfaStack.top().pop();
    State* start1 = nfaStack.top().top();
    nfaStack.top().pop();

    addEpsilonTransition(end1, start2);
    nfaStack.top().push(start1);
    nfaStack.top().push(end2);
}
void NFA::disjunction() {
    State* end2 = nfaStack.top().top();
    nfaStack.top().pop();
    State* start2 = nfaStack.top().top();
    nfaStack.top().pop();

    State* end1 = nfaStack.top().top();
    nfaStack.top().pop();
    State* start1 = nfaStack.top().top();
    nfaStack.top().pop();

    State* initial = new State();  // New initial state
    addEpsilonTransition(initial, start1);
    addEpsilonTransition(initial, start2);
    State* final = new State(); // New final state
    addEpsilonTransition(end1, final);
    addEpsilonTransition(end2, final);
    nfaStack.top().push(initial);
    nfaStack.top().push(final);
}

void NFA::kleeneClosure(){
    State* end = nfaStack.top().top();
    nfaStack.top().pop();
    State* start = nfaStack.top().top();
    nfaStack.top().pop();

    State* initial = new State(); // New initial state
    State* final = new State(); // New final state
    addEpsilonTransition(initial, start);
    addEpsilonTransition(end, final);
    addEpsilonTransition(initial, final);
    addEpsilonTransition(final, initial);
    nfaStack.top().push(initial);
    nfaStack.top().push(final);
}

void NFA::rebaseStacks(){
    State* bracketsEnd = nfaStack.top().top();
    nfaStack.top().pop();
    State* bracketsStart = nfaStack.top().top();
    nfaStack.top().pop();

    nfaStack.pop();     // pop the brackets stack
    nfaStack.top().push(bracketsStart);
    nfaStack.top().push(bracketsEnd);
    concatenate();
}
void NFA::positiveClosure(){
    State* end = nfaStack.top().top();
    nfaStack.top().pop();
    State* start = nfaStack.top().top();
    nfaStack.top().pop();

    State* initial = new State(); // New initial state
    State* final = new State(); // New final state
    addEpsilonTransition(initial, start);
    addEpsilonTransition(end, final);
    addEpsilonTransition(final, initial);
    nfaStack.top().push(initial);
    nfaStack.top().push(final);
}
State* NFA::convertToNFA(const std::string& regex) {
    std::stack<State*> initialStack;
    nfaStack.push(initialStack);
    for (int i = 0; i < regex.size(); i++) {
        char symbol = regex[i];
        if (symbol == '|') {        //left for m5m5a
            disjunction();
        } else if (symbol == '(') {
            std::stack<State*> bracketsStack;
            nfaStack.push(bracketsStack);
        } else if (symbol == ')') {
            if (regex[i+1] == '*'){
                kleeneClosure();
            } else if (regex[i+1] == '+') {
                positiveClosure();
            }
            rebaseStacks();
        }else{
            State* start = new State();
            State* end = new State();
            addSymbolTransition(start, symbol, end);
            nfaStack.top().push(start);
            nfaStack.top().push(end);
            concatenate();
        }
    }

    State* NFAEnd = nfaStack.top().top();
    NFAEnd->isFinal = true;
    nfaStack.top().pop();
    State* NFAStart = nfaStack.top().top();

    return NFAStart;
}

