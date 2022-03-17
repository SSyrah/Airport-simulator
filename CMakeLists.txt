cmake_minimum_required(VERSION 3.21)
project(Airport)

set(CMAKE_CXX_STANDARD 14)

add_executable(Airport main.cpp Airport.cpp RANDOM.CPP RANDOM.H Utility.cpp Utility.h
        Extended_queue.cpp queue.cpp Header.h)
