cmake_minimum_required(VERSION 3.10)
project(ohri)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SOURCES
  main.cpp
  features.cpp
  math.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
