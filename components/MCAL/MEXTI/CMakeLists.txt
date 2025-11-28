#set cmake version 

cmake_minimum_required(VERSION 3.2)

#set porject 

project(MEXTI C)

#set compiler
#find_program(CMAKE_C_COMPILER NAMES avr-gcc PATHS "/usr/bin/")
set(CMAKE_C_COMPILER "avr-gcc")

#set(CMAKE_C_COMPILER "/home/omar/x-tools/avr/bin/avr-gcc")

#call dio cmake to genrate libarary and get the target 
#run the internal cmake


#To set all includes inside directory

set(${PROJECT_NAME}_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/inc" "${CMAKE_CURRENT_SOURCE_DIR}/../../common")


#To get all files .c incide directory mentioned 

file(GLOB_RECURSE ${PROJECT_NAME}_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c")

#TO create library form this project

add_library(${PROJECT_NAME} STATIC "${${PROJECT_NAME}_SOURCES}")

#TO handel the includes files

target_include_directories(${PROJECT_NAME} PUBLIC "${${PROJECT_NAME}_INCLUDE_DIR}")




