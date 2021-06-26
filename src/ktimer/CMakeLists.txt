project(ktimer)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

set(TEST_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/test.cpp
)


add_executable(${PROJECT_NAME}_test
    ${TEST_FILES}
)