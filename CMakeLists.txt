cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED, ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin/)
add_compile_options(--config ../.vscode/clang.cfg)

get_filename_component(ProjectId ${CMAKE_CURRENT_LIST_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId} C CXX)

find_package(Boost COMPONENTS program_options REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

MESSAGE(STATUS "CMAKE_C_COMPILER = ${CMAKE_C_COMPILER}.")
MESSAGE(STATUS "CMAKE_CXX_COMPILER = ${CMAKE_CXX_COMPILER}.")
MESSAGE(STATUS "")
MESSAGE(STATUS "Boost_DIR = ${Boost_DIR}.")
MESSAGE(STATUS "Boost_INCLUDE_DIRS = ${Boost_INCLUDE_DIRS}.")
MESSAGE(STATUS "Boost_LIBRARIES = ${Boost_LIBRARIES}.")
MESSAGE(STATUS "Boost_LIB_VERSION = ${Boost_LIB_VERSION}.")

# Echo
file(GLOB_RECURSE ECHO_SRC src/echo/*.cpp)
add_executable(echo ${ECHO_SRC})
target_link_libraries(echo ${Boost_LIBRARIES})
target_include_directories(echo PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/echo PUBLIC ${Boost_INCLUDE_DIR})