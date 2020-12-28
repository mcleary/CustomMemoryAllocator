cmake_minimum_required(VERSION 3.12)

project(CustomAllocator)

add_library(CustomAllocatorLib SHARED "lib.h" "lib.cpp")
target_compile_definitions(CustomAllocatorLib PRIVATE "LIB_EXPORT=1")

add_executable(CustomAllocator "main.cpp")
target_link_libraries(CustomAllocator PRIVATE CustomAllocatorLib)
