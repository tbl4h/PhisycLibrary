cmake_minimum_required(VERSION 3.16)
project(PhyssicLib LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_COMPILER "/usr/bin/g++-10")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

#Build source lib.
file(GLOB_RECURSE MY_APP_SRC ${CMAKE_CURRENT_SOURCE_DIR}/sources/*.cpp)
file(GLOB_RECURSE MY_APP_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/headers/*.h)
add_library(physic_lib SHARED ${MY_APP_SRC} ${MY_APP_HEADERS})
target_include_directories(physic_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/source)
target_include_directories(physic_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/headers)
target_compile_options(physic_lib PUBLIC
  $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
  $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wfatal-errors -pedantic -fPIC -Wconversion>
)

file(GLOB_RECURSE MY_APP_TEST_SRC ${CMAKE_CURRENT_SOURCE_DIR}/test/*.cpp)
add_executable(tests ${MY_APP_TEST_SRC})
target_link_libraries(tests physic_lib)
target_link_libraries(tests ${CONAN_LIBS})