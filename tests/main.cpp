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

void test_lexer()
{
    title("Test class Lexer:");

    std::string source = "id1 id2 12 32.5";
    std::vector<kftm::Token> tokens;
    kftm::Lexer lexer_1(source, tokens);
    lexer_1.tokenize();

    message("void tokenize()...");
    assert(tokens.size() == 4);

    assert(tokens[0].getType() == kftm::TokenType::IDENTIFIER);
    assert(tokens[0].getValue() == "id1");
    assert(tokens[0].getPos().pos == 0);

    assert(tokens[1].getType() == kftm::TokenType::IDENTIFIER);
    assert(tokens[1].getValue() == "id2");
    assert(tokens[1].getPos().pos == 4);

    assert(tokens[2].getType() == kftm::TokenType::NUMBER);
    assert(tokens[2].getValue() == "12");
    assert(tokens[2].getPos().pos == 8);

    assert(tokens[3].getType() == kftm::TokenType::NUMBER);
    assert(tokens[3].getValue() == "32.5");
    assert(tokens[3].getPos().pos == 11);
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

    title("Done!");
    return 0;
}
