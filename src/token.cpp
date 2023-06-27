#include "token.h"

using namespace kftm;

Token::Token(TokenType type, std::string value) {
	this->type = type;
	this->value = value;
}
