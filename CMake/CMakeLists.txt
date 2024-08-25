cmake_minimum_required(VERSION 3.5)


project(CFG_SYS)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_GENERATOR_PLATFORM x64)


include_directories(${CMAKE_CURRENT_SOURCE_DIR})  
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/nlohmann)  

set(SOURCES
    CFG.cpp
    CFG.h
    Globals.h
)

add_executable(CFG_SYS ${SOURCES})

if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Qspectre-")
endif()
