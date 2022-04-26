#
set_source_files_properties(
  CUDAStencilKernel.cu
  PROPERTIES LANGUAGE HIP)

add_executable(Stencil2D
  CUDAStencil.cpp
  CommonCUDAStencilFactory.cpp
  Stencil2Dmain.cpp
  CUDAStencilFactory.cpp
  CUDAStencilKernel.cu
  )

if(${ENABLE_MPI})
install(TARGETS Stencil2D
        DESTINATION bin/TP/HIP
        )
else()
install(TARGETS Stencil2D
        DESTINATION bin/Serial/HIP
	)
endif()
