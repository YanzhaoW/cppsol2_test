project(cppsol2)

cmake_minimum_required(VERSION 3.24)

find_package(sol2 REQUIRED)


add_executable(main main.cpp)
target_link_libraries(main PUBLIC sol2::sol2)
