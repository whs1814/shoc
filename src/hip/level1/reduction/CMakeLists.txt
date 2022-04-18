#
set_source_files_properties(
  Reduction.cu
  tpRedLaunchKernel.cu
  PROPERTIES LANGUAGE HIP)

add_executable(Reduction
  Reduction.cu
  )

if(${ENABLE_MPI})
  add_executable(tpReduction
    tpReduction.cpp
    tpRedLaunchKernel.cu
    )
endif()
