//
// Created by usef on 12/4/2023.
//

#include "STGenerator.h"
#include <fstream>
#include <iostream>
#include <utility>
#include <sstream>

STGenerator::STGenerator(DFA &dfa) : dfa(std::move(dfa)) {}

LAOutput STGenerator::execute(const std::string& scriptFilePath){
    std::vector<LATrace> trace;
    std::vector<STRow> symbolTable;
    std::vector<SyntaxError> errors;
    newInputReset();
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
                tokenUnlocked(symbolTable);
            }
        }else if (foundMatch()){
            lastMatchIdx = currentCharIdx;
            lastMatchedTokenType = currentState->tokenName;
        }
        currentCharIdx ++;
    }
    LAOutput lao = LAOutput(symbolTable, errors, trace);
    std::cout << lao;
    return lao;
}

void STGenerator::newTokenReset() {
    getStartState();
    lastMatchedTokenType = "";
    tokenStartIdx = lastMatchIdx+1;
    lastMatchIdx = -1;
}

void STGenerator::newInputReset() {
    input = "";
    newTokenReset();
}

void STGenerator::tokenUnlocked(std::vector<STRow> symbolTable) {
    STRow strow(input.substr(tokenStartIdx,lastMatchIdx+1),lastMatchedTokenType);
    symbolTable.push_back(strow);
    newTokenReset();
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

void STGenerator::getStartState(){
    currentState = dfa.getStartState();
}






