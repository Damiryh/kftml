#pragma once
#include <string>
#include "position.h"

namespace kftm {
    enum TokenType {
        IDENTIFIER,
        NUMBER
    };

    class Token {
        Position pos;
        TokenType type;
        std::string value;

    public:
        Token(Position pos, TokenType type, std::string value);

		Position getPos();
		TokenType getType();
		std::string getValue();
	};
}
