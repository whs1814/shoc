#
set_source_files_properties(
  Scan.cu
  tpScanLaunchKernel.cu
  PROPERTIES LANGUAGE HIP)

add_executable(Scan
  Scan.cu
  )

add_executable(tpScan
  tpScan.cpp
  tpScanLaunchKernel.cu
  )
