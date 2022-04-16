#
add_executable(Stencil2D
  CUDAStencil.cpp
  CommonCUDAStencilFactory.cpp
  Stencil2Dmain.cpp
  CUDAStencilFactory.cpp
  CUDAStencilKernel.cu
  )
