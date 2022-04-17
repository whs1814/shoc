#
set_source_files_properties(
  Triad.cu
  PROPERTIES LANGUAGE HIP)

add_executable(Triad
  Triad.cu
  )
