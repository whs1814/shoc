#
link_libraries(
  cublas
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
