cmake_minimum_required(VERSION 3.12)
set(PROJECT_NAME PITCH_reader_demo)
project(${PROJECT_NAME})

set(TEST_FILE ${CMAKE_CURRENT_SOURCE_DIR}/resources/pitch_example_data)









message(STATUS ${TEST_FILE})
message(STATUS ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})




add_executable(${PROJECT_NAME} src/main.cpp)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_11)
add_custom_command(TARGET ${PROJECT_NAME}
                   POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_if_different "${TEST_FILE}" "$<TARGET_PATH:${PROJECT_NAME}>")
