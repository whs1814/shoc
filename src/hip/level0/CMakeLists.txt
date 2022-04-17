#
set_source_files_properties(
  BusSpeedDownload.cu
  BusSpeedReadback.cu
  DeviceMemory.cu
  MaxFlops.cu
  PROPERTIES LANGUAGE HIP)

add_executable(BusSpeedDownload
  BusSpeedDownload.cu
  )
add_executable(BusSpeedReadback
  BusSpeedReadback.cu
  )
add_executable(DeviceMemory
  DeviceMemory.cu
  )
add_executable(MaxFlops
  MaxFlops.cu
  )
