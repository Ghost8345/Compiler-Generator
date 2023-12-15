#include "CFGrammar.h"
#include "Parser.h"
#include "Token.h"

int main(int argc, char *argv[]) {
    // assuming we get this from phase 1
    std::vector<Token> input;
    
    // read grammar file into a string
    std::string filePath = "";
    std::string grammarDefinition = readFile(filePath);
    
    // generate grammar
    CFGrammar cfg(grammarDefinition);
    cfg.eliminateLeftRecursion();
    cfg.applyLeftFactoring();
    
    // parse input tokens
    Parser parser(cfg);
    SyntaxTree syntaxTree = parser.parse(input);
    
    // print the syntax tree or whatever is needed
    syntaxTree.print();
}

std::string readFile(std::string filePath) {}