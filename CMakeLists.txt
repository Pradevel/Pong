cmake_minimum_required(VERSION 3.23)
project(Pong)

set(CMAKE_CXX_STANDARD 14)

add_executable(Pong main.cpp Lexer/Lexer.cpp Lexer/Lexer.h Lexer/Token/Token.cpp Lexer/Token/Token.h)
