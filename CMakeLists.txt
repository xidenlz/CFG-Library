cmake_minimum_required(VERSION 3.20.x)
project(CFG_SYS)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_GENERATOR_PLATFORM x64)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")


include(json)

set(SOURCES
    src/CFG.cpp
    src/Globals.h
    src/CFG.h
    src/nlohmann/Json.h
)

add_executable(CFG_SYS ${SOURCES})

if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Qspectre-")
endif()
