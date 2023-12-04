//
// Created by usef on 12/4/2023.
//

#ifndef COMPILER_STGENERATOR_H
#define COMPILER_STGENERATOR_H

#include "../DFAConverter/DFA.h"
#include "STRow.h"

class STGenerator {
private:
    DFA dfa;
    int currentCharIdx = 0;
    int lastMatchIdx = -1;
    std::string currentToken;
    std::string lastMatchedTokenType;
    std::vector<STRow> symbolTable;

    void reset();
    void tokenUnlocked();


public:
    explicit STGenerator(DFA &dfa);
    void execute(const std::string& scriptFilePath);


};

#endif //COMPILER_STGENERATOR_H
