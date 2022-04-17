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
