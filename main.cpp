#include <iostream>
#include <unordered_map>
#include "RulesParser/RulesConverter.h"
#include "NFAConverter/NFACombiner.h"
#include "DFAConverter/DFA.h"
#include "SymbolTableGenerator/STGenerator.h"

int main(int argc, char *argv[]) {

    if (argc != 2){
        std::cerr << "Wrong number of parameter (One argument required: Rules File Path)" << "\n";
        return -1;
    }

    RulesConverter rulesConverter(argv[1]);
    int statusCode = rulesConverter.parseFile();
    if (statusCode == -1){
        std::cerr << "Badly Formatted Rules File" << "\n";
        return -1;
    }

    std::vector<RegularExpression> regularExpressions = rulesConverter.getRegularExpressions();

    for (const RegularExpression& regExp : regularExpressions) {
        std::cout << regExp.toString() << "\n";
    }

    // Regular expressions conversion to NFA
    NFACombiner nfaCombiner(regularExpressions);
    std::unordered_map<std::pair<State*, char>, std::vector<State*>, PairHash, PairEqual> table = nfaCombiner.extractTableRepresentation();
    State* nfaComplete = nfaCombiner.getCompleteNfa();

    std::cout << nfaComplete->transitions.size() << '\n';

    DFA dfa(nfaComplete);
    STGenerator stg(dfa);
    while (true){
        std::cout << "Enter the file path: ";
        std::string scriptFilePath;
        std::getline(std::cin, scriptFilePath);
        if (scriptFilePath=="$")
            break;
        stg.execute(scriptFilePath);
    }
    return 0;
}