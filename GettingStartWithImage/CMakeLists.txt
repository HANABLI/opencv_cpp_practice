# CMackeLists.txt for ImageAsMatrix
#
# © 2024 by Hatem Nabli


cmake_minimum_required(VERSION 3.8)
set(this ImageAsMatrix)
#SET(OpenCV_DIR "C:\\OpenCV\\x64\\vc17\\lib\\")
#find_package( OpenCV REQUIRED )

set(Headers 
    include/GettingStartWithImage/ImageAsMatrix.hpp
)

set(Sources 
    src/ImageAsMatrix.cpp
)


# TARGET_LINK_LIBRARIES(${Headers} ${OpenCV_LIBS} )
add_library(${this} STATIC ${Sources} ${Headers} )
set_target_properties(${this} PROPERTIES 
    FOLDER Libraries
)

#include_directories( ${OpenCV_INCLUDE_DIRS})
target_include_directories(${this} PUBLIC include)

add_subdirectory(test)
