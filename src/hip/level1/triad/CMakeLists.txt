#
set_source_files_properties(
  Triad.cu
  PROPERTIES LANGUAGE HIP)

add_executable(Triad
  Triad.cu
  )

if(${ENABLE_MPI})
install(TARGETS Triad
        DESTINATION bin/EP/HIP
        )
else()
install(TARGETS Triad
        DESTINATION bin/Serial/HIP
	)
endif()
