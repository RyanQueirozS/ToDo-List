cmake_minimum_required(VERSION 3.27.7)

#----------------------------------------------
# Detecting Operating System
#----------------------------------------------
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
  target_compile_definitions(ostest PUBLIC "LINUX_OS")
endif()
if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
  target_compile_definitions(ostest PUBLIC "MACOS_OS")
endif()
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
  target_compile_definitions(ostest PUBLIC "WINDOWS_OS")
endif()

project(todoc)

set(CMAKE_CXX_STANDART 20)

add_executable(${PROJECT_NAME} src/main.cpp)

# handeling dependecies
add_subdirectory(include)

# handeling main packages
add_subdirectory(lib)
add_subdirectory(src)

target_link_libraries(${PROJECT_NAME} PRIVATE lib src include)
