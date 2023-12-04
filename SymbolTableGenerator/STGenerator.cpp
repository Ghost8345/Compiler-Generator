//
// Created by usef on 12/4/2023.
//

#include "STGenerator.h"
#include <fstream>
#include <iostream>
#include <utility>

STGenerator::STGenerator(DFA &dfa) : dfa(std::move(dfa)) {}

void STGenerator::execute(const std::string& scriptFilePath){
    std::ifstream file(scriptFilePath);
    if (file.is_open()) {
        char c;
        while (file.get(c)) {
            currentToken += c;
        }
        file.close();
    } else {
        std::cerr << "Error: Could not open file '" << scriptFilePath << "'" << std::endl;
    }
}

void STGenerator::reset() {
    currentToken = "";
    lastMatchedTokenType = "";
    currentCharIdx = 0;
    lastMatchIdx = -1;
}

void STGenerator::tokenUnlocked() {
    STRow strow(currentToken.substr(0,lastMatchIdx+1),lastMatchedTokenType);
    symbolTable.push_back(strow);
    reset();
}



