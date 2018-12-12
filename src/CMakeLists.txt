cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

file(GLOB SRC
    "*.h"
    "*.cpp"
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} )
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/common )

add_executable(SampleAsync SampleAsync.cc ${SRC})
target_link_libraries(SampleAsync pthread)

add_executable(SampleChangeThreadContext SampleChangeThreadContext.cc ${SRC})
target_link_libraries(SampleChangeThreadContext pthread)

add_executable(SampleFail SampleFail.cc ${SRC})
target_link_libraries(SampleFail pthread)

add_executable(SampleTask SampleTask.cc ${SRC})
target_link_libraries(SampleTask pthread)