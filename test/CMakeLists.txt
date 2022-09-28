cmake_minimum_required (VERSION 3.20)

project (Test_Secure_entry LANGUAGES CXX VERSION 1.0)

include (${CMAKE_SOURCE_DIR}/cmake/CompilerWarnings.cmake)
include (${CMAKE_SOURCE_DIR}/cmake/option.cmake)

set_choice (CMAKE_BUILD_TYPE "Debug;Release;MinSizeRel;RelWithDebInfo" "Debug" "Choose type of build")

set (SRCS
	main.cpp
)

set (HEADERS
)

include_directories(${CMAKE_SOURCE_DIR}/include)

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable (${PROJECT_NAME} ${SRCS} ${HEADERS})
target_link_libraries(${PROJECT_NAME} Secure_entry)
set_target_warnings(${PROJECT_NAME})