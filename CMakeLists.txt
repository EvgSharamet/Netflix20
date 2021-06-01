cmake_minimum_required(VERSION 3.16)
project(netflix20)

set(CMAKE_CXX_STANDARD 17)
set(PROJECT_NAME netflix20)

set(sources
        main.cpp
        VideoContent.cpp
        MediaCollection.cpp
        ConjunctionFilter.cpp
        DisjunctionFilter.cpp)

set(include
        VideoContent.h
        MediaCollection.h
        ConjunctionFilter.h
        DisjunctionFilter.h)

add_executable(${PROJECT_NAME}
        ${include}
        ${sources})

target_include_directories(${PROJECT_NAME} PUBLIC
        submodules/json-develop/single_include)