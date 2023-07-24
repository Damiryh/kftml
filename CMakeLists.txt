cmake_minimum_required(VERSION 3.17)
project(kftml LANGUAGES CXX)

add_executable(${PROJECT_NAME}
    "src/position.cpp"
    "src/token.cpp"
    "src/lexer.cpp"
    "src/main.cpp"
)

set(TESTS ON)

if(${TESTS})
    set(PROJECT_TEST_NAME "${PROJECT_NAME}_test")
    add_executable(${PROJECT_TEST_NAME} "tests/main.cpp")
    target_include_directories(${PROJECT_TEST_NAME}
        PUBLIC src)
    target_sources(${PROJECT_TEST_NAME}
        PRIVATE "src/position.cpp"
        PRIVATE "src/token.cpp"
        PRIVATE "src/lexer.cpp")
endif()
