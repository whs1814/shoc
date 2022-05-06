#
set(SHOC_COMMON_OpenCL_SRCS
	OpenCLDeviceInfo.cpp
	OpenCLPlatform.cpp
	OpenCLNodePlatformContainer.cpp
	Event.cpp
	)

#set(CMAKE_CXX_COMPILER ${MPI_CXX_COMPILER})

add_library(SHOCCommonOpenCL STATIC ${SHOC_COMMON_OpenCL_SRCS})
target_include_directories(SHOCCommonOpenCL PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}
	${OpenCL_INCLUDE_DIRS}
	)

install(TARGETS SHOCCommonOpenCL
      RUNTIME DESTINATION bin
      LIBRARY DESTINATION lib
      ARCHIVE DESTINATION lib
      )

# eof
