######### CMake Version ###################################
cmake_minimum_required(VERSION 2.8.11)
###########################################################


######### Info ############################################
message( STATUS ">> CMAKE_C_COMPILER:     " ${CMAKE_C_COMPILER} )
message( STATUS ">> CMAKE_CXX_COMPILER:   " ${CMAKE_CXX_COMPILER} )
###########################################################


######### Project Name ####################################
project( exceptions )
set( EXECUTABLE_NAME run )
###########################################################


######### Have the binary placed into the source head #####
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR} )
### Output paths for multi-config builds (e.g. msvc)
foreach( OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES} )
    string( TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG )
    set( CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_SOURCE_DIR} )
    # set( CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${youroutputdirectory} )
    # set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${youroutputdirectory} )
endforeach( OUTPUTCONFIG CMAKE_CONFIGURATION_TYPES )
###########################################################


######### Prevent messing up the source tree ##############
set( CMAKE_DISABLE_SOURCE_CHANGES  ON )
set( CMAKE_DISABLE_IN_SOURCE_BUILD ON )
###########################################################


###########################################################
set(SOURCE_FILES
    src/API.cpp
    src/detail/Library.cpp
    src/detail/Exception.cpp
)

set(HEADER_FILES
    include/API.hpp
    include/detail/Library.hpp
    include/detail/Exception.hpp
)

add_executable( ${EXECUTABLE_NAME} main.cpp ${SOURCE_FILES} )

target_link_libraries( ${EXECUTABLE_NAME} ${CUDA_LIBRARIES})

target_include_directories( ${EXECUTABLE_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories( ${EXECUTABLE_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/thirdparty)

set_target_properties( ${EXECUTABLE_NAME} PROPERTIES
    CXX_STANDARD          11
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS        OFF )
###########################################################