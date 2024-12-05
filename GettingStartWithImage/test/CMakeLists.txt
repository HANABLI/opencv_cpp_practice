# CMakeLists.txt for ImageAsMatrix
#
# © 2024 by Hatem Nabli

cmake_minimum_required(VERSION 3.8)
set(this ImageAsMatrixTests)

set(Sources 
    src/ImageAsMatrixTests.cpp
)

add_executable(${this} ${Sources})
set_target_properties(${this} PROPERTIES 
    FOLDER Tests
)


target_include_directories(${this} PRIVATE ..)

target_link_libraries(${this} PUBLIC
    ${OpenCV_LIBS}
    gtest_main 
    ImageAsMatrix
)

add_test(
    NAME ${this} 
    COMMAND ${this}
)