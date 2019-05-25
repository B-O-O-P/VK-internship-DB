cmake_minimum_required(VERSION 3.01)
project(VkDB)

set(CMAKE_CXX_STANDARD 17)

add_executable(VkDB main.cpp VectorIntersectionTests.cpp VectorIntersectionTests.h VectorIntersection.cpp VectorIntersection.h)