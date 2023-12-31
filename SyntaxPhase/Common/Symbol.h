//
// Created by Meniem on 24-Dec-23.
//

#ifndef COMPILER_SYMBOL_H
#define COMPILER_SYMBOL_H

#include <string>
#include <iostream>


class Symbol {

private:
    std::string name;
    bool terminal;
public:
    virtual ~Symbol() = default;
    friend std::ostream& operator<<(std::ostream& os, const Symbol& s);

    [[nodiscard]] const std::string &getName() const;

    [[nodiscard]] bool isTerminal() const;

protected:
    Symbol(std::string name, bool terminal);


};


#endif //COMPILER_SYMBOL_H
