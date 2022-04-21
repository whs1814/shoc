#
add_executable(BFS
  BFS.cu
  bfs_kernel.cu
  ${PROJECT_SOURCE_DIR}/src/common/Graph.cpp
  )

if(${ENABLE_MPI})
install(TARGETS BFS
        DESTINATION bin/EP/CUDA
        )
else()
install(TARGETS BFS
        DESTINATION bin/Serial/CUDA
	)
endif()
