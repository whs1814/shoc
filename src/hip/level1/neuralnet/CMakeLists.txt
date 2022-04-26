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
        DESTINATION bin/EP/HIP
        )
else()
install(TARGETS NeuralNet
        DESTINATION bin/Serial/HIP
	)
endif()
