//
// Created by Meniem on 24-Dec-23.
//

#include "Grammar.h"
#include "../Common/Terminal.h"
#include <utility>
#include <unordered_map>
#include <memory>

void Grammar::standardizeNonTerminals() {
    auto terminalsSet = modifiedGrammar.getTerminals();
    auto oldNonTerminals = modifiedGrammar.getNonTerminals();
    std::unordered_map<std::string, std::shared_ptr<NonTerminal>>  nonTerminalMap;
    std::unordered_map<std::string, std::shared_ptr<Terminal>>  terminalMap;

    for (const auto& nonTerminal : oldNonTerminals){
        auto productions = nonTerminal.getProductions();
        std::vector<std::vector<std::shared_ptr<Symbol>>> newProductions;
        for (const auto& production : productions){
            std::vector<std::shared_ptr<Symbol>> newProduction;
            for (const auto& symbolName : production){
                std::shared_ptr<Symbol> symbolPtr;
                // Terminal
                if (terminalsSet.contains(symbolName)){
                    // not defined before
                    if (!terminalMap.contains(symbolName)){
                        symbolPtr = std::make_shared<Terminal>(symbolName);
                        terminalMap.insert({symbolName, std::static_pointer_cast<Terminal>(symbolPtr)});
                    }
                    // defined before
                    else {
                        symbolPtr = terminalMap.find(symbolName)->second;
                    }
                }
                // Non-Terminal
                else {
                    // not defined before
                    if (!nonTerminalMap.contains(symbolName)){
                        symbolPtr = std::make_shared<NonTerminal>(symbolName);
                        nonTerminalMap.insert({symbolName, std::static_pointer_cast<NonTerminal>(symbolPtr)});
                    }
                        // defined before
                    else {
                        symbolPtr = nonTerminalMap.find(symbolName)->second;
                    }
                }
                newProduction.push_back(symbolPtr);
            }
            newProductions.push_back(newProduction);
        }

        std::shared_ptr<NonTerminal> outerNonTerminal;
        // not defined before
        if (!nonTerminalMap.contains(nonTerminal.getName())){
            outerNonTerminal = std::make_shared<NonTerminal>(nonTerminal.getName());
            outerNonTerminal->setProductions(newProductions);
            nonTerminalMap.insert({nonTerminal.getName(), outerNonTerminal});
        }
        // defined before
        else {
            outerNonTerminal = nonTerminalMap.find(nonTerminal.getName())->second;
            outerNonTerminal->setProductions(newProductions);
        }
        standardizedNonTerminals.push_back(*outerNonTerminal);
    }
    startSymbol =  &standardizedNonTerminals[0];
}

Grammar::Grammar(GrammarConverter modifiedGrammar) : modifiedGrammar(std::move(modifiedGrammar)) {}

const std::vector<NonTerminal> &Grammar::getStandardizedNonTerminals() const {
    return standardizedNonTerminals;
}

NonTerminal *Grammar::getStartSymbol() const {
    return startSymbol;
}

