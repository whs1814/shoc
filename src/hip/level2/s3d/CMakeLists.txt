#
set_source_files_properties(
  S3D.cu
  PROPERTIES LANGUAGE HIP)

add_executable(S3D
  S3D.cu
  )
