#
add_executable(Stencil2D
  CUDAStencil.cpp
  CommonCUDAStencilFactory.cpp
  Stencil2Dmain.cpp
  CUDAStencilFactory.cpp
  CUDAStencilKernel.cu
  )

if(${ENABLE_MPI})
install(TARGETS Stencil2D
        DESTINATION bin/TP/CUDA
        )
else()
install(TARGETS Stencil2D
        DESTINATION bin/Serial/CUDA
	)
endif()
