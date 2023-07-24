#include "lexer.h"
#include <ctype.h>
#include <stdexcept>
#include <stdio.h>

using namespace kftm;

Lexer::Lexer(const std::string &source, std::vector<Token> &tokens):
    source(source), tokens(tokens) {}

void Lexer::tokenize() {
    currentPos = Position();
    ch = source.begin();

    while (ch != source.end()) {
        if (isalpha(*ch)) tokenizeWord();
        else if (isdigit(*ch)) tokenizeNumber();
        else if (SYMBOLS.count(*ch)) tokenizeSymbols();
        else if (isspace(*ch)){
            if (*ch == '\n') currentPos.newLine(); else currentPos.next(); ch++;
        } else throw std::runtime_error("Unknown symbol");
    }
}

void Lexer::tokenizeWord() {
    std::string buffer = "";
    Position start = currentPos;

    while ((isalpha(*ch) || isdigit(*ch)) && (ch != source.end())) {
        buffer.push_back(*ch++);
        currentPos.next();
    }

    tokens.push_back(Token(start, TokenType::IDENTIFIER, buffer));
}

void Lexer::tokenizeNumber() {
    std::string buffer = "";
    Position start = currentPos;

    while (isdigit(*ch) && (ch != source.end())) {
        buffer.push_back(*ch++);
        currentPos.next();
    }

    if (*ch == '.') {
        buffer.push_back(*ch++); currentPos.next();
        if (isspace(*ch)) buffer.push_back('0');

        while (isdigit(*ch) && (ch != source.end())) {
            buffer.push_back(*ch++);
            currentPos.next();
        }
    }

    if (isalpha(*ch)) throw std::runtime_error("Wrong number!");
    tokens.push_back(Token(start, TokenType::NUMBER, buffer));
}

void Lexer::tokenizeSymbols() {
    tokens.push_back(Token(currentPos, TokenType::SYMBOL, std::string(1, *ch)));
    ch++; currentPos.next();
}
