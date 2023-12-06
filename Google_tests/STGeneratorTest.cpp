//
// Created by usef on 12/4/2023.
//

#include "gtest/gtest.h"
#include "../SymbolTableGenerator//STGenerator.h"
#include <string>

TEST(STGeneration, WithoutCombinedStates){
    /// T1 : a?(b|c)*a
    /// T2 : b?(a|c)*b
    /// T3 : c?(a|b)*c
    std::string TOKEN_1 = "T1";
    std::string TOKEN_2 = "T2";
    std::string TOKEN_3 = "T3";
    ///Creating DFA
    //Defining States
    State A;
    State B(TOKEN_1);
    State C(TOKEN_2);
    State D(TOKEN_3);
    State E(TOKEN_1);
    State F(TOKEN_2);
    State G(TOKEN_3);
    State H;
    State I(TOKEN_1);
    State J(TOKEN_2);
    State K(TOKEN_3);
    State L;
    State M(TOKEN_1);
    State N(TOKEN_2);
    State O(TOKEN_3);
    State P;
    State Q;
    State R;
    State S;
    State T(TOKEN_1);
    State U(TOKEN_2);
    State V(TOKEN_3);








}
