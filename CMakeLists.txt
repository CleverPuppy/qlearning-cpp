cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "-std=c++14")

INCLUDE_DIRECTORIES(
    $(PROJECT_SOURCE_DIR))

set(SRC
    ${PROJECT_SOURCE_DIR}/qlearning.cpp
)

project(q-learning)
add_executable(${PROJECT_NAME} "main.cpp")
