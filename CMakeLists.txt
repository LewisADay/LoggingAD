cmake_minimum_required(VERSION 3.29)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(PROJECT_NAME "LoggingAD")
set(LOGGINGAD_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(LOGGINGAD_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include PARENT_SCOPE)
set(LOGGINGAD_LIBRARY_NAME ${PROJECT_NAME})
set(LOGGINGAD_LIBRARY_NAME ${PROJECT_NAME} PARENT_SCOPE)

project(${PROJECT_NAME})
add_library(${LOGGINGAD_LIBRARY_NAME})

add_subdirectory("source")
add_subdirectory("include")
add_subdirectory("vendor")

set(BUILD_EXAMPLES ON)

if (BUILD_EXAMPLES)
	add_subdirectory("examples")
endif()