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

# As cache so it may be nicely overridden by a parent CMake scope
set(LOGGINGAD_BUILD_EXAMPLES ON CACHE bool "Should we build LoggingAD's examples?")

if (LOGGINGAD_BUILD_EXAMPLES)
	add_subdirectory("examples")
endif()