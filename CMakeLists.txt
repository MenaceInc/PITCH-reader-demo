cmake_minimum_required(VERSION 3.12)
set(PROJECT_NAME PITCH_reader_demo)
project(${PROJECT_NAME})

set(TEST_FILE ${CMAKE_CURRENT_SOURCE_DIR}/resources/Pitch_example_data)

add_executable(${PROJECT_NAME} src/main.cpp)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_11)
