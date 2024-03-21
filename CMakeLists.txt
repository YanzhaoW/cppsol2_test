cmake_minimum_required(VERSION 3.25)

project(cppsol2)

find_package(sol2 REQUIRED)
find_package(fmt REQUIRED)

add_executable(main main.cpp)
target_link_libraries(main PUBLIC sol2::sol2 fmt::fmt)
