cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_FLAGS "-std=c++98")
set (CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/build")
file(DOWNLOAD
 "https://raw.githubusercontent.com/octoblu/cmake-external-project-utils/master/external-project-utils.cmake"
 "${CMAKE_MODULE_PATH}/external-project-utils.cmake"
)

include(external-project-utils)

project (tentacle-mimic)

file(GLOB SRCS *.cpp *.hpp *.c *.h)

add_executable(mimic ${SRCS})

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.58.0 REQUIRED system)

getExternalProject("gtest" "https://googletest.googlecode.com/files/gtest-1.7.0.zip")
getExternalProject("gmock" "https://googlemock.googlecode.com/files/gmock-1.7.0.zip")
getExternalProject("arduino-mock" "https://github.com/octoblu/arduino-mock/archive/master.zip")
getExternalProject("arduino-nanopb" "https://github.com/octoblu/arduino-nanopb/archive/master.zip")
getExternalProject("tentacle-arduino" "https://github.com/octoblu/tentacle-arduino/archive/master.zip")
getExternalProject("tentacle" "https://github.com/octoblu/the-tentacle/archive/master.zip")
getExternalProject("tentacle-pseudopod" "https://github.com/octoblu/tentacle-pseudopod/archive/master.zip")

include_directories(tentacle-mimic
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

# if(Boost_FOUND)
  # add_executable(progname file1.cxx file2.cxx)
# endif()
include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(mimic ${Boost_LIBRARIES})

linkExternalProject(mimic "gtest")
linkExternalProject(mimic "gmock")
linkExternalProject(mimic "arduino-mock")
linkExternalProject(mimic "arduino-nanopb")
linkExternalProject(mimic "tentacle-arduino")
linkExternalProject(mimic "tentacle")
linkExternalProject(mimic "tentacle-pseudopod")

option(test "Build all tests." OFF)
add_definitions(-DARDUINO=101)

if (test)
  enable_testing()
  add_subdirectory(test)
endif()
