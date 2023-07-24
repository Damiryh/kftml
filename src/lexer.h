#pragma once
#include <vector>
#include "token.h"

namespace kftm {
    class Lexer {
        const std::string &source;
        std::string::const_iterator ch;
        std::vector<Token> &tokens;
        Position currentPos;

        void tokenizeWord();
        void tokenizeNumber();
        void tokenizeSymbols();

    public:
        Lexer(const std::string &source, std::vector<Token> &tokens);
        void tokenize();
    };
}
