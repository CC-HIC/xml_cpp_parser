cmake_minimum_required(VERSION 2.8)
project(ccxml)
include(ExternalProject)
find_package(Git REQUIRED)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11")

find_library(pugixml required)
include_directories(src)
subdirs(src)
subdirs(tests)
