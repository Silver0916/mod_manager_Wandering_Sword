cmake_minimum_required(VERSION 3.16)

project(mod_installer_wandering_sword)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(mod_installer 
    src/main.cpp
    src/path_finder.cpp
    src/mod_installer.cpp
    )

find_path(MINIZ_INCLUDE_DIR miniz.h)
find_library(MINIZ_LIBRARY miniz)

target_include_directories(mod_installer PRIVATE ${MINIZ_INCLUDE_DIR})
target_link_libraries(mod_installer PRIVATE ${MINIZ_LIBRARY})