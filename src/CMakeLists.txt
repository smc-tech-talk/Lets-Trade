cmake_minimum_required(VERSION 3.19.2)
project(lets-trade)

# add_subdirectory(<MORE FOLDERS>)
set(SOURCE_FILES main.cpp)

add_executable(lets-trade ${SOURCE_FILES})

# For Visual Studio
add_custom_command(
        TARGET lets-trade POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_SOURCE_DIR}/src/companies.csv
                ${CMAKE_CURRENT_BINARY_DIR}/Debug/companies.csv)

# For IOS
add_custom_command(
        TARGET lets-trade POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_SOURCE_DIR}/src/companies.csv
                ${CMAKE_CURRENT_BINARY_DIR}/companies.csv)
