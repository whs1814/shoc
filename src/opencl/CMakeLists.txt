#
#enable_language(CXX)

if(${ENABLE_MPI})
  set(CMAKE_CXX_COMPILER  ${MPI_CXX_COMPILER})
  add_compile_options(-DPARALLEL)
  include_directories(${PROJECT_SOURCE_DIR}/src/mpi/common)
endif()
message(STATUS "CXX Compiler is: " ${CMAKE_CXX_COMPILER})

add_subdirectory(common)
include_directories(${SHOC_SRC_DIR}/opencl/common)
include_directories(${OpenCL_INCLUDE_DIR})

add_library(main-obj OBJECT
  ${SHOC_SRC_DIR}/opencl/common/main.cpp
  )

link_directories(${PROJECT_BINARY_DIR}/src/common)
link_directories(${OpenCL_LIBRARY})
link_libraries(
  SHOCCommonOpenCL
  ShOCCommon
  OpenCL
  main-obj
  )

## JSV - finish these subdirs
add_subdirectory(level0)
#add_subdirectory(level1)
#add_subdirectory(level2)

# eof
