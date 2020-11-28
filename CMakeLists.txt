cmake_minimum_required(VERSION 2.8)

STRING( REGEX REPLACE ".*/(.*)" "\\1" CURRENT_FOLDER ${CMAKE_CURRENT_SOURCE_DIR} ) 
PROJECT(${CURRENT_FOLDER})

add_definitions(-w)


if (WIN32)
    message("This is Windows")
    add_compile_options("/W4")
elseif(APPLE)
    message("This is Apple")
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11 -pthread")
    message("This is Windows")
elseif(UNIX)
    message("This is Linux")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11 -pthread")
endif()


include_directories(
    ${CMAKE_SOURCE_DIR}/creational
    ${CMAKE_SOURCE_DIR}/behavioral
    ${CMAKE_SOURCE_DIR}/structural
)



FILE(GLOB SRC_LIST_CPP ${PROJECT_SOURCE_DIR}/*.cpp)

AUX_SOURCE_DIRECTORY(. SRC_LIST_CPP)
ADD_EXECUTABLE(${PROJECT_NAME} ${SRC_LIST_CPP})







