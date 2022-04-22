#
set_source_files_properties(
  NeuralNet.cu
  PROPERTIES LANGUAGE HIP)

link_libraries(
  hipblas
  )

add_executable(NeuralNet
  NeuralNet.cu
  )

if(${ENABLE_MPI})
install(TARGETS NeuralNet
        DESTINATION bin/EP/CUDA
        )
else()
install(TARGETS NeuralNet
        DESTINATION bin/Serial/CUDA
	)
endif()
