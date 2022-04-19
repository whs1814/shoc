#
enable_language(CUDA)
link_libraries(BusSpeedDownload-obj)
add_executable(BusCont
  CUDADriver.cpp
  )
