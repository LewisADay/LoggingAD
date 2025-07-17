# LoggingAD

## Summary
LoggingAD is a "for fun" personal logging library for some of my (LAD - You may now see where the name comes from) other projects.

## Usage

LoggingAD is a CMake project, and may be built as such. When included in a parent CMakeLists via add_subdirectory, LoggingAD provides the following CMake macros LOGGINGAD_INCLUDE_DIR and LOGGINGAD_LIBRARY_NAME, these are convenient for example to pass to target_include_directories, and target_link_libraries respectively.

Recommended approach is as follows

```CMake
MyProject/CMakeLists.txt
...
add_subdirectory("LoggingAD")
target_link_libraries("MyProject" PRIVATE ${LOGGINGAD_LIBRARY_NAME})
target_include_directories("MyProject" PRIVATE ${LOGGINGAD_INCLUDE_DIR})
...
```

## Available functionality

- Logging to arbitrary ostreams
- File output supported
- Scope timing for profiling etc.
