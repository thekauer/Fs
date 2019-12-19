cmake_minimum_required(VERSION 3.10)

# set the project name
project(fs)

# add the executable
add_executable(fs main.cpp compiler.cpp errcodes.cpp hashed_string.cpp lex.cpp main.cpp parser.cpp sources.cpp)

set(CMAKE_CXX_STANDARD 20)
#dont show the buggy header guard
set(CMAKE_CXX_FLAGS "-Wno-extra-tokens")