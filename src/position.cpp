#include "position.h"

using namespace kftm;

Position::Position(std::string path, unsigned int line, unsigned int column, unsigned int pos):
	path(path), line(line), column(column), pos(pos) {}

Position::Position():
	path(""), line(1), column(1), pos(0) {}
