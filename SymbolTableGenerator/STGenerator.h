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
    std::vector<STRow> symbolTable;
    std::vector<SyntaxError> errors;
    State* currentState;

    void newTokenReset();
    void tokenUnlocked();
    [[nodiscard]] bool noMatchesFoundYet() const;
    bool reachedDeadEnd();
    void readScriptFile(const std::string& filepath);

public:
    explicit STGenerator(DFA &dfa);
    void execute(const std::string& scriptFilePath);
    bool foundMatch();

    void printOutput();

    void newInputReset();
};

#endif //COMPILER_STGENERATOR_H
