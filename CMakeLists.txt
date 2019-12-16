######################################################################################
########################### Presets CMakeList ########################################
######################################################################################

cmake_minimum_required(VERSION 3.0)
add_definitions(-std=c++11)

######################################################################################
########################### Configuration project  ####################################
######################################################################################

project(WorldIMaker)

set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})
set(CMAKE_CXX_FLAGS_DEBUG "-g")

set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

######################################################################################
################################## Project files  #####################################
######################################################################################

file(GLOB_RECURSE SOURCES_FILES src/*.cpp)
file(GLOB_RECURSE HEADER_FILES include/*.hpp)
file(GLOB_RECURSE SHADERS_FILES assets/shaders/*.glsl)

######################################################################################
################################## Dependencies  #####################################
######################################################################################

find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)
find_package(GLEW REQUIRED)

######################################################################################
###################################### Includes ######################################
######################################################################################

#### --------------- Necessary in order to run on Apple's laptop ---------------- ####
if (APPLE)
    include_directories(/usr/local/include)
endif (APPLE)

include_directories(
        ${SDL2_INCLUDE_DIRS}
        ${OPENGL_INCLUDE_DIR}
        ${GLEW_INCLUDE_DIRS}
        #libs/glimac/include
        libs
        )

set(ALL_LIBRARIES glimac ${SDL2_LIBRARIES} ${OPENGL_LIBRARIES} ${GLEW_LIBRARY})
add_subdirectory(libs/glimac)


######################################################################################
########################### Declaration of .exe  #####################################
######################################################################################

add_executable(${PROJECT_NAME} ${SOURCES_FILES} ${HEADER_FILES} ${SHADERS_FILES})
target_link_libraries(${PROJECT_NAME} ${ALL_LIBRARIES})

