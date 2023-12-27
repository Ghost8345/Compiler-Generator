//
// Created by deffo on 24/12/23.
//

#include "ParsingTableEntry.h"

#include <utility>

ParsingTableEntry::ParsingTableEntry() = default;

ParsingTableEntry::ParsingTableEntry(std::string type) {
    if (type == "sync"){
        this->sync = true;
    } else if ( type == "epsilon"){
        this->epsilon = true;
    }
}

ParsingTableEntry::ParsingTableEntry(Production production) {
    this->production = std::move(production);
}

bool ParsingTableEntry::isSync() const {
    return this->sync;
}

bool ParsingTableEntry::isEpsilon() const {
    return this->epsilon;
}

Production ParsingTableEntry::getProduction() {
    return this->production;
}
