#
set_source_files_properties(
  Scan.cu
  tpScanLaunchKernel.cu
  PROPERTIES LANGUAGE HIP)

add_executable(Scan
  Scan.cu
  )

if(${ENABLE_MPI})
  add_executable(tpScan
    tpScan.cpp
    tpScanLaunchKernel.cu
    )
endif()

if(${ENABLE_MPI})
install(TARGETS Scan
        DESTINATION bin/EP/CUDA
        )
install(TARGETS tpScan
        DESTINATION bin/TP/CUDA
        )
else()
install(TARGETS Scan
        DESTINATION bin/Serial/CUDA
	)
endif()
