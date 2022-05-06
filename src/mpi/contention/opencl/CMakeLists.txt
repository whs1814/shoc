#
link_libraries(BusSpeedDownload-obj)
link_directories(${OpenCL_LIBRARY})
add_executable(BusCont
  OCLDriver.cpp
  )

install(TARGETS BusCont
        RUNTIME DESTINATION bin/EP/OpenCL
        )
