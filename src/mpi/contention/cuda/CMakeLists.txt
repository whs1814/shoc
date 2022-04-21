#
enable_language(CUDA)
link_libraries(BusSpeedDownload-obj)
add_executable(BusCont
  CUDADriver.cpp
  )

install(TARGETS BusCont
        RUNTIME DESTINATION bin/EP/CUDA
        )
