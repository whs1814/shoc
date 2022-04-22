#
set_source_files_properties(
  MD.cu
  PROPERTIES LANGUAGE HIP)

add_executable(MD
  MD.cu
  )

if(${ENABLE_MPI})
install(TARGETS MD
        DESTINATION bin/EP/CUDA
        )
else()
install(TARGETS MD
        DESTINATION bin/Serial/CUDA
	)
endif()
