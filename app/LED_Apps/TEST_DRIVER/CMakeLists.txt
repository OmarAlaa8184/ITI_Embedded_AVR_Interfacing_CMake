#set cmake version 

cmake_minimum_required(VERSION 3.2)

#To specify cmake to not compile over os

set(CMAKE_SYSTEM_NAME Generic)


#To specify CMAKE_C_STANDARD 

set(CMAKE_C_STANDARD 11)

#set porject 

project(Test C)


#AVR MCU IS atmega32
set(MCU atmega32)
set(MCU2 m32)
set(PROGRAMMER usbasp)


# find_program(CMAKE_C_COMPILER NAME avr-gcc PATH "usr/bin/")
#setting avrdude flash flags

set(FLASH_FLAGS "-R .eeprom -R .lock -R .signature")


#To set all includes inside directory

set(${PROJECT_NAME}_INCLUDE_DIR
   "${CMAKE_CURRENT_SOURCE_DIR}" 
   "${CMAKE_CURRENT_SOURCE_DIR}/../../../components/common"
   "${CMAKE_CURRENT_SOURCE_DIR}/../../../components/MCAL/MDIO/inc"
   "${CMAKE_CURRENT_SOURCE_DIR}/../../../components/MCAL/MPORT/inc"
   "${CMAKE_CURRENT_SOURCE_DIR}/../../../components/HAL/HLED/inc"
   "${CMAKE_CURRENT_SOURCE_DIR}/../../../components/HAL/HSWITCH/inc"
   )

#To get all files .c incide directory mentioned 

file(GLOB_RECURSE ${PROJECT_NAME}_SOURCES 
      "${CMAKE_CURRENT_SOURCE_DIR}/Test.c"
      "${CMAKE_CURRENT_SOURCE_DIR}/../../../components/MCAL/MDIO/src/*.c"
      "${CMAKE_CURRENT_SOURCE_DIR}/../../../components/MCAL/MPORT/src/*.c"
      "${CMAKE_CURRENT_SOURCE_DIR}/../../../components/HAL/HLED/src/*.c"
      "${CMAKE_CURRENT_SOURCE_DIR}/../../../components/HAL/HSWITCH/src/*.c")


#call dio cmake to genrate libarary and get the target 
#run the internal cmake

set(MCAL_LIBS
MDIO
MPORT
)

set(HAL_LIBS
HAL
)

foreach(var ${MCAL_LIBS})

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/../../../components/MCAL/${var}" "${CMAKE_BINARY_DIR}/${var}/" )

endforeach()

foreach(var1 ${HAL_LIBS})

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/../../../components/${var1}" "${CMAKE_BINARY_DIR}/${var1}/" )

endforeach()

# set(CMAKE_C_COMPILER avr-gcc)

#set compiler flag after subdirectories

set(CMAKE_C_COMPILER "/usr/bin/avr-gcc")


add_compile_options(-g -Wall -Os -mmcu=${MCU})

add_link_options(-mmcu=${MCU} -Wl,--gc-sections)

#library target 

add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_SOURCES})

#To linke the library

target_link_libraries(${PROJECT_NAME} ${MCAL_LIBS})
target_link_libraries(${PROJECT_NAME} ${HAL_LIBS})

#TO handel the includes files

target_include_directories(${PROJECT_NAME} PUBLIC "${${PROJECT_NAME}_INCLUDE_DIR}")



add_custom_target(
   avr-hex
   DEPENDS ${PROJECT_NAME}
   COMMAND avr-objcopy -O ihex ${PROJECT_NAME} ${PROJECT_NAME}.hex
)


add_custom_target(
   burn
   DEPENDS avr-hex
   COMMAND avrdude -c ${PROGRAMMER} -p ${MCU2} -U flash:w:${PROJECT_NAME}.hex:i -B 1

)








