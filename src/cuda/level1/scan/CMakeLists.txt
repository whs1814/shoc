#
add_executable(Scan
  Scan.cu
  )

if(${ENABLE_MPI})
  add_executable(tpScan
    tpScan.cpp
    tpScanLaunchKernel.cu
    )
endif()
