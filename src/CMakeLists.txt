cmake_minimum_required(VERSION 3.5)
set(target selfLearning)
project(${target})

if(CMAKE_BUILD_TYPE STREQUAL "CMAKE_BUILD_TYPE")
	message(STATUS "CMAKE_BUILD_TYPE empty!")
	set(CMAKE_BUILD_TYPE "Debug")
endif()

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
link_directories(${CMAKE_SOURCE_DIR}/libs/${CMAKE_BUILD_TYPE})

message(STATUS "PROJECT_SOURCE_DIR:" ${PROJECT_SOURCE_DIR})
message(STATUS "PROJECT_BINARY_DIR:" ${PROJECT_BINARY_DIR})
message(STATUS "CMAKE_SOURCE_DIR:" ${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/libs/wjutils/include)
file(GLOB SRC_LIST
"*.cpp")

file(GLOB HEADER_LIST
"*.h")
add_executable(${target} ${SRC_LIST} ${HEADER_LIST})
target_link_libraries(${target} wjutils)
string(REPLACE "/" "\\" CMAKE_SOURCE_DIR_WIN ${CMAKE_SOURCE_DIR})
string(REPLACE "/" "\\" EXECUTABLE_OUTPUT_PATH_WIN ${EXECUTABLE_OUTPUT_PATH})
message(STATUS "EXECUTABLE_OUTPUT_PATH_WIN:" ${EXECUTABLE_OUTPUT_PATH_WIN})
add_custom_command(TARGET ${target}
POST_BUILD
#COMMAND xcopy ${CMAKE_SOURCE_DIR_WIN}\\include\\ ${CMAKE_SOURCE_DIR_WIN}\\..\\selfLearning\\libs\\wjutils\\include\\ /e /s /y
#COMMAND copy ${LIBRARY_OUTPUT_PATH_WIN}\\${CMAKE_BUILD_TYPE}\\${targetStaticLib} ${CMAKE_SOURCE_DIR_WIN}\\..\\selfLearning\\libs\\Debug\\wjutils\\${targetStaticLib}
COMMAND copy ${CMAKE_SOURCE_DIR_WIN}\\libs\\${CMAKE_BUILD_TYPE}\\wjutils.dll ${EXECUTABLE_OUTPUT_PATH_WIN}\\${CMAKE_BUILD_TYPE}\\wjutils.dll
)