#
set_source_files_properties(
  GEMM.cpp
  PROPERTIES LANGUAGE HIP)

link_libraries(
  hipblas
  )

add_executable(GEMM
  GEMM.cpp
  )
