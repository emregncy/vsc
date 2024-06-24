cmake_minimum_required(VERSION 3.9)
cmake_policy(SET CMP0077 NEW)
cmake_policy(SET CMP0079 NEW)

# Set version
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    execute_process(COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/version.sh VERSION ${INCREMENT_VERSION}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        OUTPUT_VARIABLE CUSTOM_VERSION)
else()
    set(CMAKE_BUILD_TYPE Debug)
    set(CUSTOM_VERSION 0.0.0)
endif()

# Project information
project(Chess VERSION ${CUSTOM_VERSION} DESCRIPTION "A chess game with C++")

# CMake options
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 20)
# GNU standard installation directories
include(GNUInstallDirs)


set(DEP_INCLUDE_DIRS)

set(DEP_LIBRARIES)

# Source files

set(SOURCES
    src/main.cpp
)

set(HEADERS
)
# Target definitions

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${version_file} src/main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC include)
target_include_directories(${PROJECT_NAME} PRIVATE src)
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_BINARY_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC ${DEP_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} PUBLIC ${DEP_LIBRARIES})

# Install

install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} # bin
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} # lib
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}) # include

