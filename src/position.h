#pragma once
#include <string>

namespace kftm {
    struct Position {
        std::string path;
        unsigned int line;
        unsigned int column;
        unsigned int pos;

        Position(std::string path, unsigned int line, unsigned int column, unsigned int pos);
        Position(std::string path);
        Position();

        void next(int step = 1);
        void newLine();
	};
}
