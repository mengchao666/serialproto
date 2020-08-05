cmake_minimum_required(VERSION 2.8)
project(SerialProto)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SAMPLE_SRC SAMPLE)

file(GLOB INTERFACE_SRC_FILES
     Interface/*.cpp
     Interface/*.h
     Interface/*.c
     Interface/*.h)

if (SAMPLE_SRC STREQUAL SAMPLE)
file(GLOB SAMPLE_SRC_FILES
     Sample/*.cpp
     Sample/*.h
     Sample/*.c
     Sample/*.h)
else ()
file(GLOB SAMPLE_SRC_FILES
     ZSX_Sample/*.cpp
     ZSX_Sample/*.h
     ZSX_Sample/*.c
     ZSX_Sample/*.h)
endif ()

file(GLOB TESTS_SRC_FILES
     Tests/*.cpp
     Tests/*.h
     Tests/*.c
     Tests/*.h)

add_executable(SerialProto
               ${INTERFACE_SRC_FILES}
               ${SAMPLE_SRC_FILES}
               ${TESTS_SRC_FILES})

add_subdirectory(googletest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

target_link_libraries(SerialProto gtest gtest_main)