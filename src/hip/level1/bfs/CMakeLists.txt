#
set_source_files_properties(
  BFS.cu
  PROPERTIES LANGUAGE HIP)

add_executable(BFS
  BFS.cu
#  bfs_kernel.cu
  ${PROJECT_SOURCE_DIR}/src/common/Graph.cpp
  )
