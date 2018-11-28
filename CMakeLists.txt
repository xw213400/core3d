project (core3d)

cmake_minimum_required (VERSION 3.1)

add_definitions(-std=c++11)

aux_source_directory(src SRCS)

include_directories (include third_party)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)

add_executable (core3d ${SRCS})
TARGET_LINK_LIBRARIES(core3d)