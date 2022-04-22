#
set_source_files_properties(
  fftlib.cu
  PROPERTIES LANGUAGE HIP)

add_library(fftlib-obj OBJECT
  fftlib.cu
  )

add_executable(FFT
  FFT.cpp
  )

target_link_libraries(FFT fftlib-obj)

if(${ENABLE_MPI})
install(TARGETS FFT
        RUNTIME DESTINATION bin/EP/CUDA
        )
else()
install(TARGETS FFT
        RUNTIME DESTINATION bin/Serial/CUDA
	)
endif()
