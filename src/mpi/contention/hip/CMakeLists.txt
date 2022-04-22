#
enable_language(HIP)
link_libraries(BusSpeedDownload-obj)
add_executable(BusCont
  CUDADriver.cpp
  )

install(TARGETS BusCont
        RUNTIME DESTINATION bin/EP/CUDA
        )
