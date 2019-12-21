cmake_minimum_required(VERSION 3.10)

# set the project name
project(fs)


file(GLOB fs_SRC
	"*.h"
	"*.cpp"
)
# add the executable
add_executable(fs  ${fs_SRC})
include_directories(${PROJECT_SOURCE_DIR})
set(CMAKE_CXX_STANDARD 20)
#dont show the buggy header guard
set(CMAKE_CXX_FLAGS "-std=c++2a -Wno-extra-tokens")
