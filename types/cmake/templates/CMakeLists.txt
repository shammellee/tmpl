cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 1)
set(PROJECT_VERSION_PATCH 0)
set(PROJECT_VERSION
	${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH})

project(TMPL_CMAKE_NAME VERSION ${PROJECT_VERSION})

# Create Config.h from Config.h.in after expand variables in Config.h.in
configure_file(
	Config.h.in
	Config.h
)

set(CMAKE_VERBOSE_MAKEFILE off)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY lib)

include_directories(${PROJECT_SOURCE_DIR})
add_subdirectory(lib/mylibrary)

set(MY_SOURCES
  src/main.c
  src/alpha.c
  src/bravo.c
)

add_executable(${PROJECT_NAME} ${MY_SOURCES})
target_link_libraries(${PROJECT_NAME} mylib)

target_include_directories(
	${PROJECT_NAME}
	PUBLIC
	"${PROJECT_BINARY_DIR}"
)

message(STATUS "Project built!")

