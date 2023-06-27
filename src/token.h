#include <string>

namespace kftm {
	enum TokenType {
		IDENTIFIER
	};

	class Token {
		TokenType type;
		std::string value;

	public:
		Token(TokenType type, std::string value);
	};
}
