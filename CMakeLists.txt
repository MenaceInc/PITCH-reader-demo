cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
set(PROJECT_NAME PITCH_reader_demo)
project(${PROJECT_NAME})

# Setup variables for copying the example data
set(TEST_FILE ${PROJECT_SOURCE_DIR}/resources/pitch_example_data)
get_filename_component(TEST_FILENAME ${TEST_FILE} NAME)

# Setup actual target to build. Minium C++11 required
add_executable(${PROJECT_NAME} src/main.cpp)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_11)
add_custom_command(TARGET ${PROJECT_NAME}
                   POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_if_different "${TEST_FILE}" "${CMAKE_BINARY_DIR}/${TEST_FILENAME}")
