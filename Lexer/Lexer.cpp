//
// Created by Pratyush on 9/23/2022.
//
#include <iostream>
#include <vector>
#include "Lexer.h"
#include "Token/Token.h"

bool isLetter(char c) {
    bool returnn;
    if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
        returnn = true;
    } else {
        returnn = false;
    }
    return returnn;
}


std::vector<LexToken> lex(std::string input) {
    long int currPosition = 0;
    std::vector<LexToken> tokens;

    while(currPosition < input.length()) {
        char c = input.at(currPosition);

        if (isLetter(c)) {
            std::string text(1, c);
            currPosition = currPosition + 1;

            while (currPosition < input.length() && isLetter(input.at(currPosition))) {
                text += input.at(currPosition);
                currPosition = currPosition + 1;
            }


            tokens.emplace_back(text, text.length(), currPosition, Str);

        } else if (std::isdigit(c)) {
            std::string text(1, c);
            currPosition = currPosition + 1;
            while (currPosition < input.length() && isLetter(input.at(currPosition))) {
                text += input.at(currPosition);
                currPosition = currPosition + 1;
            }
            tokens.emplace_back(text, text.length(), currPosition, Num);

        } else if (c == '*') {
            std::string text(1, c);
            currPosition = currPosition + 1;
            tokens.emplace_back(text, text.length(), currPosition, Mul);
        } else if (c == '/') {
            std::string text(1, c);
            currPosition = currPosition + 1;
            tokens.emplace_back(text, text.length(), currPosition, Div);
        } else if (c == '+') {
            std::string text(1, c);
            currPosition = currPosition + 1;
            tokens.emplace_back(text, text.length(), currPosition, Add);
        } else if (c == '-') {
            std::string text(1, c);
            currPosition = currPosition + 1;
            tokens.emplace_back(text, text.length(), currPosition, Sub);
        } else if (c == '=') {
            std::string text(1, c);
            currPosition = currPosition + 1;
            tokens.emplace_back(text, text.length(), currPosition, Equ);
        } else {
            currPosition = currPosition + 1;
            std::cout << "Err\n";
        }

    }
    tokens.emplace_back("EOF", 3, currPosition + 1, EOFo);
    return tokens;
}