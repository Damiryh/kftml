#include "token.h"

using namespace kftm;

Token::Token(TokenType type, std::string value, Position pos) {
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
