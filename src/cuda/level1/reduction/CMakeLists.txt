#
add_executable(Reduction
  Reduction.cu
  )

if(${ENABLE_MPI})
  add_executable(tpReduction
    tpReduction.cpp
    tpRedLaunchKernel.cu
    )
endif()

if(${ENABLE_MPI})
install(TARGETS Reduction
        DESTINATION bin/EP/CUDA
        )
install(TARGETS tpReduction
        DESTINATION bin/TP/CUDA
        )
else()
install(TARGETS Reduction
        DESTINATION bin/Serial/CUDA
	)
endif()
