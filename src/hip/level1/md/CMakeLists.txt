#
set_source_files_properties(
  MD.cu
  PROPERTIES LANGUAGE HIP)

add_executable(MD
  MD.cu
  )
