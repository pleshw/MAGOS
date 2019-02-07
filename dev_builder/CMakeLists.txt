cmake_minimum_required(VERSION 3.5)
project (DRIVER_CANVAS VERSION 1.0.0 LANGUAGES CXX )

#=== FINDING PACKAGES ===#

#--------------------------------
# This is for old cmake versions
set (CMAKE_CXX_STANDARD 11)
#--------------------------------

#=== SETTING VARIABLES ===#
# Compiling flags
set( GCC_COMPILE_FLAGS "-Wall -Wextra -pedantic" )
#set( PREPROCESSING_FLAGS  "-D PRINT -D DEBUG -D CASE="WORST" -D ALGO="QUAD"')
set( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COMPILE_FLAGS} ${PREPROCESSING_FLAGS}" )

#Include dir
include_directories( include ../libs/ ../dev_canvas/include ../dev_maze/include ../dev_render/include ../dev_solver/include )

#=== Main App ===
#Can manually add the sources using the set command as follows:

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp")
file(GLOB MAZE "../dev_maze/src/*.cpp")
file(GLOB CANVAS "../dev_canvas/src/*.cpp")
file(GLOB RENDER "../dev_render/src/*.cpp")
file(GLOB SOLVER "../dev_solver/src/*.cpp")
file(GLOB CONFIGFILE "../libs/configFileReader/*.cpp")

add_executable(build_maze ${CANVAS} ${MAZE} ${RENDER} ${SOLVER} ${CONFIGFILE} ${SOURCES})