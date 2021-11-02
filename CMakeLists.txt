cmake_minimum_required(VERSION 3.2)

set(myproject "pomodoro")
project(${myproject})

# Specificam standardul
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(my_files src/hello.cpp headers/hello.hpp)

add_library(lib STATIC ${my_files})

add_executable(${myproject} src/main.cpp)

target_link_libraries(${myproject} PUBLIC lib)


target_include_directories(${myproject} 
 PRIVATE src INTERFACE
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/headers>
	$<INSTALL_INTERFACE:headers>)