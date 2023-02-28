#include <iostream>
#include <vector>
#include <chrono>
#include "Lexer/Lexer.h"

int main() {

    auto start = std::chrono::steady_clock::now();
    std::vector<LexToken> tokens = lex("aa = 3\n"
                                       "    aa = aa + 2\n"
                                       "    print(aa)");
    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;
    std::cout << std::chrono::duration <double, std::milli> (diff).count() << " ms" << std::endl;

    for (int i = 0; i < tokens.size(); i++) {
        std::cout << tokenToString(tokens[i]);
    }
    return 0;
}
