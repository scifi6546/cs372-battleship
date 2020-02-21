cmake_minimum_required(VERSION 3.10)

if(UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif()

project(battleship)
add_executable(battleship test.cpp grid.cpp drawing.cpp UI.cpp)
find_library(NCURSES NAMES ncurses)
target_link_libraries(${PROJECT_NAME}
	${NCURSES})
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
include_directories(${PROJECT_SOURCE_DIR})


