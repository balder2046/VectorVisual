cmake_minimum_required(VERSION 3.5)
project(VectorVisual)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
if ("${HOST}" STREQUAL "zhaolei-linux")
	set(OpenCV_DIR "/usr/share/OpenCV")
else()
	set(OpenCV_DIR "/usr/local/Cellar/opencv/2.4.12_2/share/OpenCV")  
endif()
include_directories(${OpenCV_DIR})
link_directories(${OpenCV_LIB_DIRS})

find_package(OpenCV)

set(SOURCE_FILES main.cpp VectorCanvas.cpp VectorCanvas.h)
add_executable(VectorVisual ${SOURCE_FILES})
TARGET_LINK_LIBRARIES(VectorVisual ${OpenCV_LIBS})
