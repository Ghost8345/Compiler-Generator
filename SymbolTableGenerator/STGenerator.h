//
// Created by usef on 12/4/2023.
//

#ifndef COMPILER_STGENERATOR_H
#define COMPILER_STGENERATOR_H

#include "../DFAConverter/DFA.h"
#include "STRow.h"
#include "SyntaxError.h"

class STGenerator {
private:
    DFA dfa;
    int currentCharIdx = 0;
    int lastMatchIdx = -1;
    int tokenStartIdx = 0;
    std::string input;
    std::string lastMatchedTokenType;
    State* currentState{};

    void readScriptFile(const std::string& filepath);
    void newInputReset();
    void newTokenReset();
    void tokenUnlocked();
    void getStartState();
    [[nodiscard]] bool noMatchesFoundYet() const;
    [[nodiscard]] bool reachedDeadEnd();
    [[nodiscard]] bool foundMatch();


public:
    explicit STGenerator(DFA &dfa);
    void execute(const std::string& scriptFilePath);
};

#endif //COMPILER_STGENERATOR_H
