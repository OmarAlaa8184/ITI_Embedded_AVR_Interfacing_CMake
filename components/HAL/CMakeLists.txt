#set cmake version 

cmake_minimum_required(VERSION 3.2)

#set porject 

project(HAL C)

#set compiler
#find_program(CMAKE_C_COMPILER NAMES avr-gcc PATHS "/usr/bin/")
#set(CMAKE_C_COMPILER "avr-gcc")

set(CMAKE_C_COMPILER "/home/omar/x-tools/avr/bin/avr-gcc")


#To set all includes inside directory

set(${PROJECT_NAME}_INCLUDE_DIR 
    "${CMAKE_CURRENT_SOURCE_DIR}/HSEVENSEG/inc"
    "${CMAKE_CURRENT_SOURCE_DIR}/HLED/inc" 
    "${CMAKE_CURRENT_SOURCE_DIR}/HSWITCH/inc" 
    "${CMAKE_CURRENT_SOURCE_DIR}/../common"
    "${CMAKE_CURRENT_SOURCE_DIR}/../MCAL/MDIO/inc" 
    "${CMAKE_CURRENT_SOURCE_DIR}/../MCAL/MPORT/inc" 
    )


#To get all files .c incide directory mentioned 

file(GLOB_RECURSE ${PROJECT_NAME}_SOURCES 
  
    "${CMAKE_CURRENT_SOURCE_DIR}/HSEVENSEG/src/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/HLED/src/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/HSWITCH/src/*.c"
    )

#TO create library form this project

add_library(${PROJECT_NAME} STATIC "${${PROJECT_NAME}_SOURCES}")

#To linke the library

target_link_libraries(${PROJECT_NAME} ${MCAL_LIBS})

#TO handel the includes files

target_include_directories(${PROJECT_NAME} PUBLIC "${${PROJECT_NAME}_INCLUDE_DIR}")




