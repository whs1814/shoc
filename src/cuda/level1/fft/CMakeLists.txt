#
add_executable(FFT
  FFT.cpp
  fftlib.cu
  )

if(${ENABLE_MPI})
install(TARGETS FFT
        RUNTIME DESTINATION bin/EP/CUDA
        )
else()
install(TARGETS FFT
        RUNTIME DESTINATION bin/Serial/CUDA
	)
endif()
