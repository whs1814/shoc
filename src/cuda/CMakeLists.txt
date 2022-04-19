#
enable_language(CUDA)
message(STATUS "CUDA Compiler is: " ${CMAKE_CUDA_COMPILER})
set(CUDA_SRC_DIR        ${SHOC_SRC_DIR}/cuda)
set(CUDA_COMMON_SRC_DIR ${CUDA_SRC_DIR}/common)

if(${ENABLE_MPI})
  set(CMAKE_CXX_COMPILER  ${MPI_CXX_COMPILER})
  add_compile_options(-DPARALLEL)
  include_directories(${PROJECT_SOURCE_DIR}/src/mpi/common)
endif()

include_directories(${CUDA_COMMON_SRC_DIR})
include_directories($ENV{CUDA_PATH}/include)
set(SHOC_CUDA_COMMON_MAIN_SRC
  ${CUDA_COMMON_SRC_DIR}/main.cpp
  )

add_library(main-obj OBJECT
  ${SHOC_CUDA_COMMON_MAIN_SRC}
  )

link_directories(${PROJECT_BINARY_DIR}/src/common)
link_directories($ENV{CUDA_PATH}/lib64)
link_libraries(
  ShOCCommon
  cudart
  main-obj
  )

#add_subdirectory(common)
add_subdirectory(level0)
add_subdirectory(level1)
add_subdirectory(level2)

