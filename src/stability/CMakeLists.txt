#
enable_language(CUDA)
set(CUDA_SRC_DIR        ${SHOC_SRC_DIR}/cuda)
set(CUDA_COMMON_SRC_DIR ${CUDA_SRC_DIR}/common)

if(${ENABLE_MPI})
  set(CMAKE_CXX_COMPILER  ${MPI_CXX_COMPILER})
  add_compile_options(-DPARALLEL)
  include_directories(${PROJECT_SOURCE_DIR}/src/mpi/common)
endif()

include_directories(${CUDA_COMMON_SRC_DIR})
include_directories($ENV{CUDA_PATH}/include)

link_directories(${PROJECT_BINARY_DIR}/src/common)
link_directories($ENV{CUDA_PATH}/lib64)
link_libraries(
  ShOCCommon
  cudart
  fftlib-obj
  main-obj
  )

add_executable(Stability
  Stability.cpp
  )

if(${ENABLE_MPI})
install(TARGETS Stability
        RUNTIME DESTINATION bin/EP/CUDA
        )
else()
install(TARGETS Stability
        RUNTIME DESTINATION bin/Serial/CUDA
	)
endif()
