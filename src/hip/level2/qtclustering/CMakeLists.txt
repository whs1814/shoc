#
set_source_files_properties(
  QTC.cu
  PROPERTIES LANGUAGE HIP)

add_executable(QTC
  QTC.cu
  comm.cpp
  libdata.cpp
  )

if(${ENABLE_MPI})
install(TARGETS QTC
        RUNTIME DESTINATION bin/TP/CUDA
        )
else()
install(TARGETS QTC
        RUNTIME DESTINATION bin/Serial/CUDA
	)
endif()
