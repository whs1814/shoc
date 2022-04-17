#
set_source_files_properties(
  Sort.cu
  sort_kernel.cu
  PROPERTIES LANGUAGE HIP)

add_executable(Sort
  Sort.cu
  sort_kernel.cu
  )
