#
set_source_files_properties(
  Reduction.cu
  tpRedLaunchKernel.cu
  PROPERTIES LANGUAGE HIP)

add_executable(Reduction
  Reduction.cu
  )

add_executable(tpReduction
  tpReduction.cpp
  tpRedLaunchKernel.cu
  )
