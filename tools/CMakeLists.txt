
configure_file (
    "${PROJECT_SOURCE_DIR}/tools/shocdriver.in.cmake"
    "${PROJECT_SOURCE_DIR}/tools/shocdriver"
)

install(PROGRAMS shocdriver
        DESTINATION bin
	)

install(PROGRAMS driver.pl numatest.pl
        DESTINATION libexec
	)
