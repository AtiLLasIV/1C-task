cmake_minimum_required(VERSION 3.27)
project(1C_task)

set(CMAKE_CXX_STANDARD 20)

add_executable(1C_task main.cpp
        src/structures/Card.cpp
        src/structures/State.cpp
        src/algorithms/bfs_solitaire.cpp
        src/inputs/inputs.cpp
)
