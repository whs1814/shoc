#
set_source_files_properties(
  Spmv.cu
  PROPERTIES LANGUAGE HIP)

add_executable(Spmv
  Spmv.cu
  )

if(${ENABLE_MPI})
install(TARGETS Spmv
        DESTINATION bin/EP/HIP
        )
else()
install(TARGETS Spmv
        DESTINATION bin/Serial/HIP
	)
endif()
