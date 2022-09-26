//
// Created by Pratyush on 9/24/2022.
//

#ifndef PONG_TOKEN_H
#define PONG_TOKEN_H

#include <vector>
enum TokenType {
    Num = 1,
    Str = 2,
    Bol = 3,
    Mul = 4,
    Add = 5,
    Equ = 6,
    Sub = 7,
    Div = 8,
    EOFo= 9
};

struct LexToken
{
    LexToken(std::string data, int size, int pos, TokenType type);

    std::string data;
    int size;
    int pos;
    TokenType type;


};

std::string tokenToString(const LexToken& token);

#endif //PONG_TOKEN_H
