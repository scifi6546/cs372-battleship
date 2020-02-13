cmake_minimum_required(VERSION 3.13)

if(UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif()
if(LINUX)
    set(CMAKE_CXX_COMPILER "/usr/bin/g++-9")
endif()
project(battleship)
add_executable(battleship test.cpp grid.cpp drawing.cpp)
find_library(NCURSES NAMES ncurses)
target_link_libraries(${PROJECT_NAME}
	${NCURSES})
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
include_directories(${PROJECT_SOURCE_DIR})


