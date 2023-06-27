#include <string>
#include "position.h"

namespace kftm {
	enum TokenType {
		IDENTIFIER
	};

	class Token {
		TokenType type;
		std::string value;
		Position pos;

	public:
		Token(TokenType type, std::string value, Position pos);

		TokenType getType();
		std::string getValue();
		Position getPos();
	};
}
