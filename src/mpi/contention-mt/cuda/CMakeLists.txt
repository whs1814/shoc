#
enable_language(CUDA)
link_libraries(BusSpeedDownload-obj)
add_executable(MTBusCont
  CUDADriver.cpp
  )

install(TARGETS MTBusCont
        RUNTIME DESTINATION bin/EP/CUDA
        )
