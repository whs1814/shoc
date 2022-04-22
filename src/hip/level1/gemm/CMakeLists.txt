#
set_source_files_properties(
  GEMM.cpp
  PROPERTIES LANGUAGE HIP)

link_libraries(
  hipblas
  )

add_executable(GEMM
  GEMM.cpp
  )

if(${ENABLE_MPI})
install(TARGETS GEMM
        RUNTIME DESTINATION bin/EP/CUDA
        )
else()
install(TARGETS GEMM
        RUNTIME DESTINATION bin/Serial/CUDA
	)
endif()
