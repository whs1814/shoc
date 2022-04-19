#
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

#target_include_directories(BusSpeedDownload PUBLIC
#  ${CMAKE_CURRENT_SOURCE_DIR}
#  ${CUDA_COMMON_SRC_DIR}
#  $ENV{CUDA_PATinclude
#  )

#target_link_libraries(BusSpeedDownload
#  ShOCCommon
#  cudart
#  )
#if(${ENABLE_MPI})
#  add_subdirectory(epmpi)
#endif()
