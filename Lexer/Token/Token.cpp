//
// Created by Pratyush on 9/24/2022.
//

#include <string>
#include "Token.h"


std::string tokenToString(const LexToken& token) {
    return("Token{" + token.data + ", " + std::to_string(token.size) + ", " + std::to_string((token.type)) + ", " + (token.pos) + "}\n");
}


LexToken::LexToken(std::string data, int size, std::string pos, TokenType type) {
    this->data = data;
    this->size = size;
    this->type = type;
    this->pos = pos;
}
