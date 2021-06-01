cmake_minimum_required(VERSION 3.17)
project(netflix20)

set(CMAKE_CXX_STANDARD 17)

set(PROJECT_NAME netflix20)
add_executable(${PROJECT_NAME} main.cpp VideoContent.cpp VideoContent.h Collection.cpp Collection.h Filter.cpp Filter.h ConjunctionFilter.cpp ConjunctionFilter.h DisjunctionFilter.cpp DisjunctionFilter.h)

target_include_directories(${PROJECT_NAME} PUBLIC
        submodules/json-develop/single_include)