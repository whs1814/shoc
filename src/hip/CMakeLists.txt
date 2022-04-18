#
cmake_minimum_required(VERSION 3.21)
enable_language(HIP)
#message(STATUS "HIP Compiler is: " ${CMAKE_HIP_COMPILER})
set(CMAKE_HIP_COMPILER "hipcc")
set(HIP_SRC_DIR         ${SHOC_SRC_DIR}/hip)
set(HIP_COMMON_SRC_DIR  ${HIP_SRC_DIR}/common)

if(${ENABLE_MPI})
  set(CMAKE_CXX_COMPILER  ${MPI_CXX_COMPILER})
  add_compile_options(-DPARALLEL)
  add_compile_options(-D__HIP_PLATFORM_AMD__)
  include_directories(${PROJECT_SOURCE_DIR}/src/mpi/common)
  link_libraries(mpi)
else()
  set(CMAKE_CXX_COMPILER  "hipcc")
endif()

include_directories(${HIP_COMMON_SRC_DIR})
include_directories($ENV{HIP_PATH}/include)
set(SHOC_HIP_COMMON_MAIN_SRC
  ${HIP_COMMON_SRC_DIR}/main.cpp
  )

add_library(main-obj OBJECT
  ${SHOC_HIP_COMMON_MAIN_SRC}
  )

link_directories(${PROJECT_BINARY_DIR}/src/common)
link_libraries(
  ShOCCommon
  amdhip64
  main-obj
  )

add_subdirectory(level0)
add_subdirectory(level1)
add_subdirectory(level2)

