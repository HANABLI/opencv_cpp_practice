# This is the CMackeLists.txt for BasicImageOperations cours
#
# © 2024 by Hatem Nabli

cmake_minimum_required(VERSION 3.8)
# SPECIFY YOUR PROJECT NAME
# PROJECT(Project_Name)


# # ENABLE C++11
# SET(CMAKE_CXX_STANDARD 11)
# SET(CMAKE_CXX_STANDARD_REQUIRED TRUE)


# # MAKE SURE OPENCV IS INSTALLED CORRECTLY
# find_package( OpenCV REQUIRED )


# MACRO TO COMPILE CPP FILES
# Do Not Edit
MACRO(add_example name)
  ADD_EXECUTABLE(${name} ${name}.cpp)
  TARGET_LINK_LIBRARIES(${name} ${OpenCV_LIBS} )
ENDMACRO()


# COMPILE CPP FILES USING THIS LINE
######## EDIT THE FILE NAMES ########
add_example(CreateImage)
#add_example(sampleCode2) and so on