#include "position.h"

using namespace kftm;

Position::Position(std::string path, unsigned int line, unsigned int column, unsigned int pos):
	path(path), line(line), column(column), pos(pos) {}

Position::Position(std::string path):
    path(path), line(1), column(1), pos(0) {}

Position::Position():
	path(""), line(1), column(1), pos(0) {}

void Position::next(int step) {
    column += step;
    pos += step;
}

void Position::newLine() {
    column = 1;
    line++;
    pos++;
}
