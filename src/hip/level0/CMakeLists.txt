#
set_source_files_properties(
  BusSpeedDownload.cu
  BusSpeedReadback.cu
  DeviceMemory.cu
  MaxFlops.cu
  PROPERTIES LANGUAGE HIP)

add_library(BusSpeedDownload-obj OBJECT
  BusSpeedDownload.cu
  )

add_executable(BusSpeedDownload)
target_link_libraries(BusSpeedDownload
  BusSpeedDownload-obj
  )
#add_executable(BusSpeedDownload
#  BusSpeedDownload.cu
#  )
add_executable(BusSpeedReadback
  BusSpeedReadback.cu
  )
add_executable(DeviceMemory
  DeviceMemory.cu
  )
add_executable(MaxFlops
  MaxFlops.cu
  )

if(${ENABLE_MPI})
install(TARGETS BusSpeedDownload BusSpeedReadback DeviceMemory MaxFlops
        RUNTIME DESTINATION bin/EP/CUDA
        )
else()
install(TARGETS BusSpeedDownload BusSpeedReadback DeviceMemory MaxFlops
        RUNTIME DESTINATION bin/Serial/CUDA
	)
endif()
