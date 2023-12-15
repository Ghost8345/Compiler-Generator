#ifndef PARSER_TOKEN_H
#define PARSER_TOKEN_H

#include "Common.h"
#include "Symbol.h"

class Token
{
public:
    Terminal terminal;
    std::string lexeme;
};

#endif