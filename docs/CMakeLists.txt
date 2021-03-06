# Specify a minimum required version
cmake_minimum_required(VERSION 3.9)


# Specify the tex file name
set(TEX_NAME libwrp)


# Define a LaTeX project, and specify where to find the UseLATEX commands
project(libint-wrapper NONE)		# The NONE option has to be included, since we are not using the langue c, cxx, or Fortran
include(cmake/UseLATEX.cmake)

# BUILD: Add a file to the specified project
add_latex_document(${TEX_NAME}.tex
                   BIBFILES ../../../../Documents/Archief/Bibliotheek/research_bib.bib
                   IMAGE_DIRS figures
)


# POST-BUILD: move the created .pdf-file to the top directory (copy and delete)
add_custom_command(TARGET "${TEX_NAME}_pdf" POST_BUILD
COMMAND ${CMAKE_COMMAND} -E copy "${TEX_NAME}.pdf" ..
COMMAND ${CMAKE_COMMAND} -E remove "${TEX_NAME}.pdf"
COMMENT "Moving PDF-file to top directory.")
