cmake_minimum_required(VERSION 3.8)
project(8_Bit_Block_Cipher)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Blocks.cpp Blocks.h)
add_executable(8_Bit_Block_Cipher ${SOURCE_FILES})