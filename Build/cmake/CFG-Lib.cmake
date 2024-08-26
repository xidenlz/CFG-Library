include(FetchContent)

message(STATUS "CFG-Lib")
FetchContent_Declare(
    json
    GIT_REPOSITORY "https://github.com/xidenlz/CFG-Library"
    GIT_TAG CFG-Lib
    GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(json)
