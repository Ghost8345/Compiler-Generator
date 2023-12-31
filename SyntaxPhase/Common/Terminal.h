//
// Created by Meniem on 24-Dec-23.
//

#ifndef COMPILER_TERMINAL_H
#define COMPILER_TERMINAL_H


#include "Symbol.h"

class Terminal : public Symbol {
public:
    explicit Terminal(const std::string &name);
    friend std::ostream& operator<<(std::ostream& os, const Terminal* t);
    [[nodiscard]] bool isEpsilon();
};

#endif //COMPILER_TERMINAL_H
