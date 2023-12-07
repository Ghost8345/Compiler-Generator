//
// Created by usef on 12/4/2023.
//

#include "SyntaxError.h"
#include <string>
#include "iostream"

SyntaxError::SyntaxError(int st,int ed) {
    this->startIdx = st;
    this->endIdx = ed;
}

std::ostream& operator<<(std::ostream& os, const SyntaxError& se){
    os << "Syntax Error in the following indices range:" << se.startIdx << " --> " << se.endIdx << "\n";
    return os;
}
