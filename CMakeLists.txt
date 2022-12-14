cmake_minimum_required(VERSION 3.20)
project(untitled)

set(CMAKE_CXX_STANDARD 23)

add_executable(main c_plus_plus.cpp
              graph/bfs.cpp
		)
