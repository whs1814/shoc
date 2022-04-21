#
add_executable(Spmv
  Spmv.cu
  )

if(${ENABLE_MPI})
install(TARGETS Spmv
        DESTINATION bin/EP/CUDA
        )
else()
install(TARGETS Spmv
        DESTINATION bin/Serial/CUDA
	)
endif()
