#include <iostream>
#include <vector>
#include "Lexer/Lexer.h"

int main() {
    std::vector<LexToken> tokens = lex("aa = a + 3\n"
                                       "b = true");
    for (int i = 0; i < tokens.size(); i++) {
        std::cout << tokenToString(tokens[i]);
    }
    return 0;
}
