#pragma once
#include <string>
#include <set>
#include "position.h"

namespace kftm {
    enum TokenType {
        IDENTIFIER,
        NUMBER,
        SYMBOL,
    };

    const std::set<char> SYMBOLS {
        '(', ')', '{', '}',
        '+', '-', '*', '/'
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
