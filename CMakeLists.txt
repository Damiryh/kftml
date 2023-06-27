cmake_minimum_required(VERSION 3.17)
project(kftml LANGUAGES CXX)

add_executable(${PROJECT_NAME}
	"src/position.cpp"
	"src/token.cpp"
	"src/main.cpp"
)
