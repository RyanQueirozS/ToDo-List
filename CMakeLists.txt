cmake_minimum_required(VERSION 3.27.7)

project(todoc)

set(CMAKE_CXX_STANDART 14)

add_executable(${PROJECT_NAME} src/main.cpp)

# handeling dependecies
add_subdirectory(include)

# handeling main packages
add_subdirectory(lib)
add_subdirectory(src)

target_link_libraries(${PROJECT_NAME} PRIVATE lib src include)
