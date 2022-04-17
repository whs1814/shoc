#
set_source_files_properties(
  QTC.cu
  PROPERTIES LANGUAGE HIP)

add_executable(QTC
  QTC.cu
  comm.cpp
  libdata.cpp
  )
