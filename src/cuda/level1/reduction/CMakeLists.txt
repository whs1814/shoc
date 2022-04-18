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
