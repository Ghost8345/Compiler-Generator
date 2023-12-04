//
// Created by usef on 12/4/2023.
//

#include "STGenerator.h"
#include <fstream>
#include <iostream>
#include <utility>
#include <sstream>

STGenerator::STGenerator(DFA &dfa) : dfa(std::move(dfa)) {
    currentState = dfa.getStartState();
}

void STGenerator::execute(const std::string& scriptFilePath){
    readScriptFile(scriptFilePath);
    while (currentCharIdx!=input.size()){
        char c = input[currentCharIdx];
        currentState = currentState->moveTo(c);
        if (reachedDeadEnd()){
            if (noMatchesFoundYet()){
                SyntaxError e(tokenStartIdx,currentCharIdx);
                errors.push_back(e);
            }else{
                currentCharIdx = lastMatchIdx;
                tokenUnlocked();
            }
        }else if (foundMatch()){
            lastMatchIdx = currentCharIdx;
            lastMatchedTokenType = currentState->tokenName;
        }
        currentCharIdx ++;
    }
}

void STGenerator::reset() {
    lastMatchedTokenType = "";
    lastMatchIdx = -1;
    tokenStartIdx = 0;
}

void STGenerator::tokenUnlocked() {
    STRow strow(input.substr(tokenStartIdx,lastMatchIdx+1),lastMatchedTokenType);
    symbolTable.push_back(strow);
    reset();
}

bool STGenerator::noMatchesFoundYet() const {
    return lastMatchIdx==-1;
}

bool STGenerator::reachedDeadEnd() {
    return currentState== nullptr;
}

void STGenerator::readScriptFile(const std::string &filepath) {
    std::ifstream file(filepath);
    if (file.is_open()) {
        std::stringstream buffer;
        buffer << file.rdbuf();
        input = buffer.str();
        file.close();
    } else {
        std::cerr << "Error opening file: " << filepath << std::endl;
    }
}

bool STGenerator::foundMatch() {
    return currentState->isFinal;
}





