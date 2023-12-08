//
// Created by usef on 12/2/2023.
//

#ifndef COMPILER_DFA_H
#define COMPILER_DFA_H

#include "../NFAConverter/State.h"
#include "../NFAConverter/NFACombiner.h"
#include "../NFAConverter/NFA.h"
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <functional>

#define EPSILON '\0'

typedef std::unordered_map<std::pair<State*, char>, State*, PairHash, PairEqual> TransitionTable;

class DFA {
private:
    State* startState{};
    State* convertToDFA(State* nfaStartState, const std::unordered_set<char>& alphabet);
public:
    TransitionTable transitionTable;
    explicit DFA(State* startState);
    State* getStartState();
};

std::unordered_set<char> getAlphabet(State* startState);
std::unordered_set<State*> epsilonClosure(State* state);
std::unordered_set<State*> epsilonClosure(const std::unordered_set<State*>& states);
std::unordered_set<State*> move(const std::unordered_set<State*>& states, char symbol);


struct StatePtrSetHash {
    template <typename T>
    std::size_t operator()(const std::unordered_set<T>& s) const {
        size_t hash = 0;
        for (const T t: s) {
            hash ^= std::hash<T>{}(t);
        }
        return hash;
    }
};

struct StatePtrSetEquality {
    template <typename T>
    std::size_t operator()(const std::unordered_set<T>& a, const std::unordered_set<T>& b) const {
        if (a.size() != b.size())
            return false;

        for (auto &e: a) {
            if (!b.contains(e)) {
                return false;
            }
        }

        return true;
    }
};

#endif //COMPILER_DFA_H
