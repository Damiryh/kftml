#include "token.h"

using namespace kftm;

Token::Token(Position pos, TokenType type, std::string value) {
    this->pos = pos;
	this->type = type;
	this->value = value;
}

TokenType Token::getType() {
    return this->type;
}

std::string Token::getValue() {
    return this->value;
}

Position Token::getPos() {
    return this->pos;
}
