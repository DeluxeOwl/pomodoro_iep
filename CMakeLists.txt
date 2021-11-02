cmake_minimum_required(VERSION 3.2)

project("pomodoro")

# Specificam standardul
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# add_executable(${PROJECT_NAME} src/main.cpp myheader.hpp)
add_executable(${PROJECT_NAME} src/main.cpp)