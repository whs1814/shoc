#
add_executable(Scan
  Scan.cu
  )

add_executable(tpScan
  tpScan.cpp
  tpScanLaunchKernel.cu
  )
