find_package(Doxygen)

if (DOXYGEN_FOUND)

    message("WorldIMaker_SOURCE_DIR     " ${vectorD_SOURCE_DIR})
    message("WorldIMaker_BINARY_DIR     " ${vectorD_BINARY_DIR})
    message("DOXYGEN_EXECUTABLE     " ${DOXYGEN_EXECUTABLE})

    if(DOXYGEN_FOUND)
        configure_file (${WorldIMaker_SOURCE_DIR}/docs/Doxyfile-html.cmake ${WorldIMaker_BINARY_DIR}/docs/Doxyfile-html)
        add_custom_target (html ${DOXYGEN_EXECUTABLE} ${WorldIMaker_BINARY_DIR}/docs/Doxyfile-html)
    endif (DOXYGEN_FOUND)


else (DOXYGEN_FOUND)
    message("Doxygen need to be installed to generate the doxygen documentation")

endif (DOXYGEN_FOUND)