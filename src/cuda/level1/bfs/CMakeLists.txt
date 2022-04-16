#
add_executable(BFS
  BFS.cu
  bfs_kernel.cu
  ${PROJECT_SOURCE_DIR}/src/common/Graph.cpp
  )
