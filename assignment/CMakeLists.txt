cmake_minimum_required(VERSION 4.0)
project(7_2_assignment)

set(CMAKE_CXX_STANDARD 20)

add_executable(7_2_assignment main.cpp
        ItemTracker.cpp
        ItemTracker.h)

add_custom_command(TARGET 7_2_assignment POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_CURRENT_SOURCE_DIR}/CS210_Project_Three_Input_File.txt
        $<TARGET_FILE_DIR:7_2_assignment>/CS210_Project_Three_Input_File.txt)
