cmake_minimum_required(VERSION 3.13)
project(VKDB2)

set(CMAKE_CXX_STANDARD 17)

add_executable(VKDB2 main.cpp UniqCounter.cpp UniqCounter.h Hashes.cpp Hashes.h)