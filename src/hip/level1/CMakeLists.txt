
add_subdirectory(bfs)
add_subdirectory(fft)
add_subdirectory(gemm)        #hipblas
#add_subdirectory(md)          #Texture
add_subdirectory(md5hash)
#add_subdirectory(neuralnet)   #hipblas
add_subdirectory(sort)
#add_subdirectory(spmv)        #Texture
add_subdirectory(stencil2d)
add_subdirectory(triad)
if(${ENABLE_MPI})
  add_subdirectory(reduction)
  add_subdirectory(scan)
endif()
