cmake_minimum_required(VERSION 3.2)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Release)
project(test)

add_subdirectory(src)

add_executable(main main.cpp)
target_link_libraries(main PUBLIC complib)










