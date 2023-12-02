//
// Created by deffo on 02/12/23.
//

#include "NFACombiner.h"

NFACombiner::NFACombiner(std::vector<RegularExpression>& regExps) {
    this->regExps = regExps;
    State* initial = new State();
    for (const RegularExpression& regExp: regExps){
        NFA nfa = NFA();
        std::pair<State*, State*> localNFA = nfa.convertToNFA(regExp.getRegex(), regExp.getName(), regExp.getPriority());
        NFA::addEpsilonTransition(initial, localNFA.first);
    }
    this->completeNFA = initial;

}

