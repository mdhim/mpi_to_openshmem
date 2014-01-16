cmake_minimum_required (VERSION 2.6)

include(CMakeForceCompiler)
project (PWT)

add_subdirectory (src/pwt)
set (EXTRA_LIBS ${EXTRA_LIBS} pwt)

aux_source_directory(src SRCS)
aux_source_directory(src/apps SRCS)
include_directories(src)
include_directories(src/apps)
add_executable(pftool ${SRCS})
add_custom_target(pfcmp_link echo "creating pfcmp link ..." DEPENDS pfcmp)
add_custom_command(OUTPUT pfcmp COMMAND ${CMAKE_COMMAND} -E create_symlink ./pftool pfcmp WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
add_dependencies(pfcmp_link pftool)



# Require MPI for this project:
find_package(MPI REQUIRED)
include_directories(${MPI_INCLUDE_PATH})
set_target_properties(pftool PROPERTIES COMPILE_FLAGS "-Wall -I.. -D_GNU_SOURCE -g ${MPI_COMPILE_FLAGS}")
set_target_properties(pftool PROPERTIES LINK_FLAGS "${MPI_LINK_FLAGS}")
target_link_libraries(pftool ${MPI_LIBRARIES})
target_link_libraries(pftool ${EXTRA_LIBS})
