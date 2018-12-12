cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(SampleApp)

# Add a cached variable for COMMON_SERVICES & Compiler Setting
if (NOT CONFIGURED_ONCE)

	set (CMAKE_CXX_COMPILER "/usr/bin/g++")
	set (CMAKE_C_COMPILER "/usr/bin/gcc")
	set (CMAKE_CXX_FLAGS "-std=c++1y -DQCC_OS_GROUP_POSIX -DQCC_OS_LINUX"
	CACHE STRING "Flags used by the compiler during all build types." FORCE)

	# To resolve c++ 11/14 compatibility issues
	set(CMAKE_CXX_STANDARD 14)
	set(CMAKE_CXX_STANDARD_REQUIRED ON)
	set(CMAKE_CXX_EXTENSIONS OFF)

endif()

# Only set the cache variables single time
set(CONFIGURED_ONCE TRUE CACHE INTERNAL
    "A flag showing that CMake has configured at least once.")


set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(src)
