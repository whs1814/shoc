add_library(BusSpeedDownload-obj OBJECT
  BusSpeedDownload.cpp
  )

add_executable(BusSpeedDownload)
target_link_libraries(BusSpeedDownload
  BusSpeedDownload-obj
  )

add_executable(BusSpeedReadback
  BusSpeedReadback.cpp
  )
add_executable(DeviceMemory
  DeviceMemory.cpp
  )
add_executable(MaxFlops
  MaxFlops.cpp
  )
add_executable(KernelCompile KernelCompile.cpp)
add_executable(QueueDelay QueueDelay.cpp)

if(${ENABLE_MPI})
install(TARGETS BusSpeedDownload BusSpeedReadback DeviceMemory MaxFlops KernelCompile QueueDelay
        RUNTIME DESTINATION bin/EP/OpenCL
        )
else()
install(TARGETS BusSpeedDownload BusSpeedReadback DeviceMemory MaxFlops KernelCompile QueueDelay
        RUNTIME DESTINATION bin/Serial/OpenCL
        )
endif()
