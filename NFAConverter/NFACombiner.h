//
// Created by deffo on 02/12/23.
//

#ifndef COMPILER_NFACOMBINER_H
#define COMPILER_NFACOMBINER_H


#include "../RulesParser/RegularExpression.h"
#include "State.h"
#include "NFA.h"

class NFACombiner {
    private:
        std::vector<RegularExpression> regExps;
        State* completeNFA;

    public:
        NFACombiner(std::vector<RegularExpression>&);
        // TODO: Get the Adjacency Matrix Array


};


#endif //COMPILER_NFACOMBINER_H
