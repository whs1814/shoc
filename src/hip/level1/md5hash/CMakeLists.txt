#
set_source_files_properties(
  MD5Hash.cu
  PROPERTIES LANGUAGE HIP)

add_executable(MD5Hash
  MD5Hash.cu
  )

if(${ENABLE_MPI})
install(TARGETS MD5Hash
        DESTINATION bin/EP/CUDA
        )
else()
install(TARGETS MD5Hash
        DESTINATION bin/Serial/CUDA
	)
endif()
