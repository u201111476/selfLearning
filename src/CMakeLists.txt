cmake_minimum_required(VERSION 3.5)
set(target selfLearning)
project(${target})

if(CMAKE_BUILD_TYPE STREQUAL "CMAKE_BUILD_TYPE")
	message(STATUS "CMAKE_BUILD_TYPE empty!")
	set(CMAKE_BUILD_TYPE "Debug")
endif()

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../bin)
link_directories(${PROJECT_SOURCE_DIR}/../libs/${CMAKE_BUILD_TYPE})

message(STATUS ${PROJECT_SOURCE_DIR})
message(STATUS ${PROJECT_BINARY_DIR})
include_directories(${PROJECT_SOURCE_DIR}/../libs/wjutils/include)
file(GLOB SRC_LIST
"*.cpp")

file(GLOB HEADER_LIST
"*.h")

add_executable(${target} ${SRC_LIST} ${HEADER_LIST})
target_link_libraries(${target} wjutils)