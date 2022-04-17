#
set_source_files_properties(
  Spmv.cu
  PROPERTIES LANGUAGE HIP)

add_executable(Spmv
  Spmv.cu
  )
