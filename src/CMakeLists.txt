
add_subdirectory(common)

if(${ENABLE_MPI})
	add_subdirectory(mpi)
endif()

if(${ENABLE_OPENCL})
	add_subdirectory(opencl)
endif()

if(${ENABLE_HIP})
	add_subdirectory(hip)
endif()

if(${ENABLE_CUDA})
	add_subdirectory(cuda)
	add_subdirectory(stability)
endif()

