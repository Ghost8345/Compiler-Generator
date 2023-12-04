//
// Created by usef on 12/4/2023.
//

#include "STRow.h"
#include <iostream>

STRow::STRow(std::string token,std::string tokenType)
        : token(std::move(token)),tokenType(std::move(tokenType)) {}

std::ostream& operator<<(std::ostream& os, const STRow& strow){
    os << strow.token << " --> " << strow.tokenType;
    return os;
}
