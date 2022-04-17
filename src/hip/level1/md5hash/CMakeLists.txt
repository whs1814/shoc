#
set_source_files_properties(
  MD5Hash.cu
  PROPERTIES LANGUAGE HIP)

add_executable(MD5Hash
  MD5Hash.cu
  )
