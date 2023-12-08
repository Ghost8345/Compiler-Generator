//
// Created by usef on 12/2/2023.
//

#include "DFA.h"

DFA::DFA(NFA &nfa) : nfa(std::move(nfa)) {}

State *DFA::getStartState() {
    return startState;
}

DFA::DFA(State *startState) {
    std::unordered_set<char> alphabet = getAlphabet(startState);
    this->startState = convertToDFA(startState, alphabet);
}

State* DFA::convertToDFA(State* nfaStartState, std::unordered_set<char> alphabet) {   
    std::stack<std::unordered_set<State*>> unmarked;
    std::unordered_map<std::unordered_set<State*>, State*, StatePtrSetHash, StatePtrSetEquality> mapping;
    
    std::unordered_set<State*> startStates = epsilonClosure(nfaStartState);
    State* dfaStartState = new State(startStates);
    mapping[startStates] = dfaStartState;
    unmarked.push(startStates);
    
    while (!unmarked.empty()) {
        std::unordered_set<State*> T = unmarked.top(); unmarked.pop();
        
        for (char a: alphabet) {
            if (a == EPSILON) continue;

            std::unordered_set<State*> U = epsilonClosure(move(T,a));

            if (U.empty()) continue;

            if (!mapping.contains(U)) {
                unmarked.push(U);
                mapping[U] = new State(U);
            }
            
            mapping[T]->addTransition(Transition(a, mapping[U]));
        }
    }
    
    return dfaStartState;
}


std::unordered_set<char> getAlphabet(State* startState) {
    std::stack<State*> frontier;
    std::unordered_set<char> symbols;
    std::unordered_set<State*> visited;

    frontier.push(startState);
    while (!frontier.empty()) {
        State* state = frontier.top(); frontier.pop();
        visited.insert(state);

        for (Transition transition: state->transitions) {
            symbols.insert(transition.getInput());

            if (!visited.contains(transition.getNextState())) {
                frontier.push(transition.getNextState());
            }
        }
    }

    return symbols;
}

std::unordered_set<State*> epsilonClosure(State* state) {
    std::unordered_set<State*> states;
    if (state == nullptr) return states;

    states.insert(state);
    return epsilonClosure(states);
}

std::unordered_set<State*> epsilonClosure(const std::unordered_set<State*>& states) {
    std::unordered_set<State*> output;
    if (states.empty()) return output;
    
    std::stack<State*> frontier;
    for (State* state: states) 
        frontier.push(state);
    
    while (!frontier.empty()) {
        State* state = frontier.top(); frontier.pop();
        
        if (output.contains(state))
            continue;

        for (Transition transition: state->transitions) {
            if (transition.getInput() == EPSILON) {
                frontier.push(transition.getNextState());
            }
        }
        
        output.insert(state);
    }
    
    return output;
}


std::unordered_set<State*> move(const std::unordered_set<State*>& states, char symbol) {
    std::unordered_set<State*> nextStates;

    for (State* state: states) {
        for (Transition transition: state->transitions) {
            if (transition.getInput() == symbol) {
                nextStates.insert(transition.getNextState());
            }
        }
    }

    return nextStates;
}