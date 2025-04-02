cmake_minimum_required(VERSION 3.10)
project(Cade_Lang)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_COMPILER "clang++")

# Source files for the main executable
file(GLOB MAIN_SOURCES "src/*.cpp")

# Main executable
add_executable(${PROJECT_NAME} ${MAIN_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE src)

# Enable testing
enable_testing()

# Find Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Test files
file(GLOB TEST_SOURCES "tests/*.cpp")

# Source files for tests, excluding main.cpp
file(GLOB LIB_SOURCES "src/*.cpp")
list(FILTER LIB_SOURCES EXCLUDE REGEX "src/main.cpp$")

# Test executable
add_executable(run_tests ${TEST_SOURCES} ${LIB_SOURCES})
target_include_directories(run_tests PRIVATE src)
target_link_libraries(run_tests ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)

# Add test
add_test(NAME CadeLangTests COMMAND run_tests)
