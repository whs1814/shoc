#
add_executable(Reduction
  Reduction.cu
  )

add_executable(tpReduction
  tpReduction.cpp
  tpRedLaunchKernel.cu
  )
