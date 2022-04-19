#
set(CMAKE_CXX_COMPILER  ${MPI_CXX_COMPILER})
include_directories(${PROJECT_SOURCE_DIR}/src/mpi/common)
link_libraries(mpi)
add_library(mpi_contention OBJECT
  bcmain.cpp
  BusCont.cpp
)
link_libraries(
  SHOCCommonMPI
  ShOCCommon
  mpi_contention
  )

if(${ENABLE_OPENCL})
  add_subdirectory(opencl)
endif()

if(${ENABLE_CUDA})
  include_directories($ENV{CUDA_PATH}/include)
  link_directories($ENV{CUDA_PATH}/lib64)
  link_libraries(cudart)
  add_subdirectory(cuda)
endif()

if(${ENABLE_HIP})
  include_directories($ENV{HIP_PATH}/include)
  add_compile_options(-D__HIP_PLATFORM_AMD__)
  link_directories($ENV{HIP_PATH}/lib)
  link_libraries(amdhip64)
  add_subdirectory(hip)
endif()

# eof
