#
set_source_files_properties(
  MD.cu
  PROPERTIES LANGUAGE HIP)

add_executable(MD
  MD.cu
  )

if(${ENABLE_MPI})
install(TARGETS MD
        DESTINATION bin/EP/HIP
        )
else()
install(TARGETS MD
        DESTINATION bin/Serial/HIP
	)
endif()
