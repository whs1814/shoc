#
enable_language(HIP)
link_libraries(BusSpeedDownload-obj)
add_executable(MTBusCont
  CUDADriver.cpp
  )

install(TARGETS MTBusCont
        RUNTIME DESTINATION bin/EP/CUDA
        )
