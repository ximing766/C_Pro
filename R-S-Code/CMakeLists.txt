cmake_minimum_required(VERSION 3.30)
project(app C)

set(CMAKE_C_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR}/inc)

aux_source_directory(./src SRC_LIST)
#set(SRC_LIST
#        ./src/berlekamp.c
#        ./src/crcgen.c
#        ./src/fec.c
#        ./src/galois.c
#        ./src/rs.c
#)

#add_executable(example example.c ${SRC_LIST})
#set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_library(RSCode SHARED ${SRC_LIST})
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)