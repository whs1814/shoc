#
add_executable(Triad
  Triad.cu
  )

if(${ENABLE_MPI})
install(TARGETS Triad
        DESTINATION bin/EP/CUDA
        )
else()
install(TARGETS Triad
        DESTINATION bin/Serial/CUDA
	)
endif()
