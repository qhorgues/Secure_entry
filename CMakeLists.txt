cmake_minimum_required(VERSION 3.20)

project(Secure_entry LANGUAGES CXX VERSION 1.0.0)

# include(CTest)
# enable_testing()

include(${CMAKE_SOURCE_DIR}/cmake/option.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/CompilerWarnings.cmake)

set_option(BUILD_TEST OFF BOOL "Build test code for library")

set_choice (CMAKE_BUILD_TYPE "Debug;Release;MinSizeRel;RelWithDebInfo" "Debug" "Choose type of build")

set (SRCS
	
)

set (HEADERS
    ${CMAKE_SOURCE_DIR}/include/Secure_entry.hpp
	${CMAKE_SOURCE_DIR}/include/Secure_entry.tpp
)

if (BUILD_TEST)
    add_subdirectory(${CMAKE_SOURCE_DIR}/test)
endif()

include_directories(${CMAKE_SOURCE_DIR}/include)

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

add_library (${PROJECT_NAME} INTERFACE ${SRCS} ${HEADERS})

include(GNUInstallDirs)

foreach(header ${HEADERS})
    set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER ${header})
    install(TARGETS ${PROJECT_NAME} PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} )
endforeach()


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Quentin Horgues")
set(CPACK_DEB_COMPONENTS_INSTALL YES)
set(CPACK_DEBIAN_PACKAGE_DEPENDS "")
set(CPACK_DESKTOP_SHORTCUTS ON)
include(CPack)