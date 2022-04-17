#
set_source_files_properties(
  fftlib.cu
  PROPERTIES LANGUAGE HIP)

add_executable(FFT
  FFT.cpp
  fftlib.cu
  )
