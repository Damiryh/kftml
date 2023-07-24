#include <iostream>
#include <assert.h>
#include "position.h"
#include "token.h"
#include "lexer.h"

void message(std::string msg) { std::cout << msg << " " << std::flush; }
void title(std::string t) { std::cout << t << std::endl; }
void OK() { std::cout << "OK!" << std::endl; }
void line() { std::cout << "====================================================" << std::endl; }

void test_position()
{
    title("Test class Position:");
    kftm::Position pos_1, pos_2("path", 123, 456, 789);

    message("Position()... ");
    assert(pos_1.path == "");
    assert(pos_1.line == 1);
    assert(pos_1.column == 1);
    assert(pos_1.pos == 0);
    OK();

    message("Position(path, line, column, pos)... ");
    assert(pos_2.path == "path");
    assert(pos_2.line == 123);
    assert(pos_2.column == 456);
    assert(pos_2.pos == 789);
    OK();

    message("void next()... ");
    pos_1.next();
    assert(pos_1.line == 1);
    assert(pos_1.column == 2);
    assert(pos_1.pos == 1);
    OK();

    message("void next(step)... ");
    const unsigned int N = 154;
    pos_1.next(N);
    assert(pos_1.line == 1);
    assert(pos_1.column == N + 2);
    assert(pos_1.pos == N + 1);
    OK();

    message("void newLine()... ");
    pos_1.newLine();
    assert(pos_1.line == 2);
    assert(pos_1.column == 1);
    assert(pos_1.pos == N + 2);
    OK();

    line();
}

void test_token()
{
    title("Test class Token:");
    kftm::Token token_1(kftm::Position("src", 2, 3, 5), kftm::TokenType::IDENTIFIER, "ident");

    message("Constructor(pos, type, value),");
    message("Position getPos()...");
    assert(token_1.getPos().pos == 5);
    OK();

    message("Constructor(pos, type, value),");
    message("TokenType getType()...");
    assert(token_1.getType() == kftm::TokenType::IDENTIFIER);
    OK();

    message("Constructor(pos, type, value),");
    message("string getValue()...");
    assert(token_1.getValue() == "ident");
    OK();

    line();
}

void assert_token(kftm::Token tkn, kftm::TokenType type, std::string val, unsigned int pos) {
    message("@ Token");
    message(tkn.getValue());
    assert(tkn.getType() == type);
    assert(tkn.getValue() == val);
    assert(tkn.getPos().pos == pos);
    OK();
}

void test_lexer()
{
    title("Test class Lexer:");

    std::string source = "id1 id2 12 32.5";
    std::vector<kftm::Token> tokens;
    kftm::Lexer lexer_1(source, tokens);
    lexer_1.tokenize();

    title("void tokenize():");
    assert(tokens.size() == 4);

    assert_token(tokens[0], kftm::TokenType::IDENTIFIER,  "id1",  0u);
    assert_token(tokens[1], kftm::TokenType::IDENTIFIER,  "id2",  4u);
    assert_token(tokens[2],     kftm::TokenType::NUMBER,   "12",  8u);
    assert_token(tokens[3],     kftm::TokenType::NUMBER, "32.5", 11u);

    tokens.clear();
    source = "(x *2.3+ 8)";
    kftm::Lexer lexer_2(source, tokens);
    lexer_2.tokenize();

    assert_token(tokens[0],     kftm::TokenType::SYMBOL,   "(", 0);
    assert_token(tokens[1], kftm::TokenType::IDENTIFIER,   "x", 1);
    assert_token(tokens[2],     kftm::TokenType::SYMBOL,   "*", 3);
    assert_token(tokens[3],     kftm::TokenType::NUMBER, "2.3", 4);
    assert_token(tokens[4],     kftm::TokenType::SYMBOL,   "+", 7);
    assert_token(tokens[5],     kftm::TokenType::NUMBER,   "8", 9);
    assert_token(tokens[6],     kftm::TokenType::SYMBOL,  ")", 10);

    line();
}

void manual_test_lexer()
{
    title("Manual lexer test:");
    std::string source;
    std::vector<kftm::Token> tokens;
    kftm::Lexer lexer_1(source, tokens);

    std::cout << "test> ";
    std::getline(std::cin, source);
    if (source == "") {
        message("Skipped.");
        OK();
        line();
        return;
    }

    lexer_1.tokenize();

    for (auto token: tokens) {
        std::cout
            << "["
            << token.getPos().pos << ":"
            << token.getPos().line << ","
            << token.getPos().column << "]\t\t"
            << token.getType() << "\t"
            << token.getValue() << std::endl;
    }

    OK();

    line();
}

int main(int argc, char **argv)
{
    title("---- KFTML TESTS ----");
    line();

    test_position();
    test_token();
    test_lexer();

    manual_test_lexer();

    title("Done!");
    return 0;
}
