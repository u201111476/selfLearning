cmake_minimum_required(VERSION 3.5)
set(target selfLearning)
project(${target})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../bin)
link_directories(${PROJECT_SOURCE_DIR}/../libs/wjutils)

message(STATUS ${PROJECT_SOURCE_DIR})
message(STATUS ${PROJECT_BINARY_DIR})
include_directories(${PROJECT_SOURCE_DIR}/../libs/wjutils/include)
file(GLOB SRC_LIST
"*.cpp")

file(GLOB HEADER_LIST
"*.h")

add_executable(${target} ${SRC_LIST} ${HEADER_LIST})
target_link_libraries(${target} wjutils)