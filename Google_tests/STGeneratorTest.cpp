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
    char a = 'a';
    char b = 'b';
    char c = 'c';
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
    //Defining Transitions

    A.addTransition(Transition(a,&B));
    A.addTransition(Transition(b,&C));
    A.addTransition(Transition(c,&D));

    B.addTransition(Transition(a,&E));
    B.addTransition(Transition(b,&F));
    B.addTransition(Transition(c,&G));

    C.addTransition(Transition(a,&E));
    C.addTransition(Transition(b,&F));
    C.addTransition(Transition(c,&G));

    D.addTransition(Transition(a,&E));
    D.addTransition(Transition(b,&F));
    D.addTransition(Transition(c,&G));

    E.addTransition(Transition(a,&H));
    E.addTransition(Transition(b,&I));
    E.addTransition(Transition(c,&J));

    F.addTransition(Transition(a,&K));
    F.addTransition(Transition(b,&L));
    F.addTransition(Transition(c,&M));

    G.addTransition(Transition(a,&N));
    G.addTransition(Transition(b,&O));
    G.addTransition(Transition(c,&P));

    H.addTransition(Transition(a,&H));
    H.addTransition(Transition(b,&I));
    H.addTransition(Transition(c,&J));

    I.addTransition(Transition(a,&S));
    I.addTransition(Transition(b,&S));
    I.addTransition(Transition(c,&V));

    J.addTransition(Transition(a,&R));
    J.addTransition(Transition(b,&U));
    J.addTransition(Transition(c,&R));

    L.addTransition(Transition(a,&K));
    L.addTransition(Transition(b,&L));
    L.addTransition(Transition(c,&M));

    M.addTransition(Transition(a,&T));
    M.addTransition(Transition(b,&Q));
    M.addTransition(Transition(c,&Q));

    N.addTransition(Transition(a,&R));
    N.addTransition(Transition(b,&U));
    N.addTransition(Transition(c,&R));

    O.addTransition(Transition(a,&T));
    O.addTransition(Transition(b,&Q));
    O.addTransition(Transition(c,&Q));

    P.addTransition(Transition(a,&N));
    P.addTransition(Transition(b,&O));
    P.addTransition(Transition(c,&P));

    Q.addTransition(Transition(a,&T));
    Q.addTransition(Transition(b,&Q));
    Q.addTransition(Transition(c,&Q));

    R.addTransition(Transition(a,&R));
    R.addTransition(Transition(b,&U));
    R.addTransition(Transition(c,&R));

    S.addTransition(Transition(a,&S));
    S.addTransition(Transition(b,&S));
    S.addTransition(Transition(c,&V));

    DFA joeDFA(&A);

}
