//
// Created by usef on 12/26/2023.
//

#ifndef COMPILER_FIRSTSETSGENERATOR_H
#define COMPILER_FIRSTSETSGENERATOR_H

#include "../Common/NonTerminal.h"

#include <utility>
#include "iostream"

class FirstSetsGenerator{
private:
    std::vector<NonTerminal*> nts;
    static void showFirstSet(NonTerminal* nt);
    void exec();


public:
    explicit FirstSetsGenerator(std::vector<NonTerminal*> nts);
    [[nodiscard]] std::vector<NonTerminal*> getNTsWithFirstSets();

};

#endif //COMPILER_FIRSTSETSGENERATOR_H