#
add_executable(MD
  MD.cu
  )

if(${ENABLE_MPI})
install(TARGETS MD
        DESTINATION bin/EP/CUDA
        )
else()
install(TARGETS MD
        DESTINATION bin/Serial/CUDA
	)
endif()
