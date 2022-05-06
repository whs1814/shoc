#
link_libraries(BusSpeedDownload-obj)
link_directories(${OpenCL_LIBRARY})
add_executable(MTBusCont
  OCLDriver.cpp
  )

install(TARGETS MTBusCont
        RUNTIME DESTINATION bin/EP/OpenCL
        )
