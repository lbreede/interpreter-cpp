cmake_minimum_required(VERSION 3.10)

project(Interpreter)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/lexer
    ${CMAKE_CURRENT_SOURCE_DIR}/token
    ${CMAKE_CURRENT_SOURCE_DIR}/repl
)

add_executable(main
    main.cpp
    lexer/lexer.cpp
    token/token.cpp
    repl/repl.cpp
)