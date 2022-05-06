#enable_language(CXX OpenCL)
#set_source_files_properties(
#  bfs_iiit.cl
#  bfs_uiuc_spill.cl
#  PROPERTIES LANGUAGE CXX)

add_executable(BFS
  BFS.cpp
  bfs_iiit.cl
  bfs_uiuc_spill.cl
  ${PROJECT_SOURCE_DIR}/src/common/Graph.cpp
  )

if(${ENABLE_MPI})
install(TARGETS BFS
        DESTINATION bin/EP/OpenCL
        )
else()
install(TARGETS BFS
        DESTINATION bin/Serial/OpenCL
        )
endif()
