#
set_source_files_properties(
  S3D.cu
  PROPERTIES LANGUAGE HIP)

add_executable(S3D
  S3D.cu
  )

if(${ENABLE_MPI})
install(TARGETS S3D
        RUNTIME DESTINATION bin/EP/CUDA
        )
else()
install(TARGETS S3D
        RUNTIME DESTINATION bin/Serial/CUDA
	)
endif()
