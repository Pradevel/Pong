//
// Created by Pratyush on 9/23/2022.
//
#include <iostream>
#include <vector>
#include <algorithm>
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
    int currPosition = 0;
    int debugPosition = 0;
    std::vector<LexToken> tokens;
    int lineNum = 1;
    while(currPosition < input.length()) {
        char c = input.at(currPosition);

        if (c == '"') {
            std::string text(1, c);
            currPosition++;
            debugPosition++;
            int loopTime = 0;
            while (currPosition < input.length() && (input.at(currPosition) != '"')) {
                text += input.at(currPosition);
                currPosition++;
                loopTime++;
                debugPosition++;
            }

            tokens.emplace_back(text, text.length(), std::to_string(lineNum) + ":" + std::to_string(debugPosition - loopTime), Str);

        } else if (std::isdigit(c)) {
            std::string text(1, c);
            currPosition++;
            debugPosition++;
            int loopTime = 0;

            while (currPosition < input.length() && std::isdigit(input.at(currPosition))) {
                text += input.at(currPosition);
                currPosition++;
                debugPosition++;
                loopTime++;
            }
            tokens.emplace_back(text, text.length(), std::to_string(lineNum) + ":" + std::to_string(debugPosition - loopTime), Num);

        } else if (c == '*') {
            std::string text(1, c);
            currPosition++;
            debugPosition++;
            tokens.emplace_back(text, text.length(), std::to_string(lineNum) + ":" + std::to_string(debugPosition), Mul);
        } else if (c == '/') {
            std::string text(1, c);
            currPosition++;
            debugPosition++;
            tokens.emplace_back(text, text.length(), std::to_string(lineNum) + ":" + std::to_string(debugPosition), Div);
        } else if (c == '+') {
            std::string text(1, c);
            currPosition++;
            debugPosition++;
            tokens.emplace_back(text, text.length(), std::to_string(lineNum) + ":" + std::to_string(debugPosition), Add);
        } else if (c == '-') {
            std::string text(1, c);
            currPosition++;
            debugPosition++;
            tokens.emplace_back(text, text.length(), std::to_string(lineNum) + ":" + std::to_string(debugPosition), Sub);
        } else if (c == '=') {
            std::string text(1, c);
            currPosition++;
            debugPosition++;
            tokens.emplace_back(text, text.length(), std::to_string(lineNum) + ":" + std::to_string(debugPosition), Equ);
        } else if (c == '\n') {
            std::string text = "NL";
            currPosition++;
            debugPosition++;
            lineNum++;
            debugPosition = 1;
            tokens.emplace_back(text, text.length(), std::to_string(lineNum) + ":" + std::to_string(debugPosition), Ent);
        } else if (isLetter(c)) {
            std::string text(1, c);
            currPosition++;
            debugPosition++;
            int loopTime = 0;

            while (currPosition < input.length() && (input.at(currPosition) != ' ')) {
                text += input.at(currPosition);
                currPosition++;
                loopTime++;
                debugPosition++;
            }

            tokens.emplace_back(text, text.length(), std::to_string(lineNum) + ":" + std::to_string(debugPosition - loopTime), Ref);
        } else {

            if(c != ' ') {
                std::string text(1, c);
                currPosition++;
                int loopTime = 0;
                debugPosition++;
                while (currPosition < input.length() && (input.at(currPosition)) != ' ') {
                    text += input.at(currPosition);
                    currPosition++;
                    loopTime++;
                    debugPosition++;
                }
                std::cout << std::string("SystaxError: Unknown Instruction - '") + text + std::string("'") + "\n\t at LineL:  " + std::to_string(lineNum) + ":" + std::to_string(debugPosition - loopTime) + "\n";

            }
            currPosition++;
            debugPosition++;
        }

    }
    tokens.emplace_back("EOF", 3, std::to_string(lineNum) + ":" + std::to_string(debugPosition), EOFo);
    tokens.erase(
            std::remove_if(
                    tokens.begin(),
                    tokens.end(),
                    [](LexToken const & p) { return p.data == "\""; }
            ),
            tokens.end()
    );
    for (int i = 0; i < tokens.size(); i++) {
        if((tokens[i].type == Ref and tokens[i + 1].type == Equ) or (tokens[i].type == Ref and tokens[i + 1].type == Mul) or (tokens[i].type == Ref and tokens[i + 1].type == Add) or (tokens[i].type == Ref and tokens[i + 1].type == Sub) or (tokens[i].type == Ref and tokens[i + 1].type == Div)) {
            tokens[i].type = Var;
        }

        if(tokens[i].data == "true" or tokens[i].data == "false") {
            tokens[i].type = Bol;
        }

        if(tokens[i].type == Str) {
            tokens[i].data = tokens[i].data.substr(1, tokens[i].data.length());
        }
        if(tokens[i].data.find("(") != std::string::npos) {
            tokens[i].data = "[" + tokens[i].data.substr(0, tokens[i].data.find("(")) + ", " + tokens[i].data.substr(tokens[i].data.find("("), tokens[i].data.length()) + "]";
        }




    }
    return tokens;
}