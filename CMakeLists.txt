cmake_minimum_required( VERSION 3.2 )
project( conway )

include( ExternalProject )
find_package( Git REQUIRED )

# Reconfigure Output Directories
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib )
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib )
foreach( OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES} )
	string( TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG )
	set( CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_SOURCE_DIR}/bin )
	set( CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_SOURCE_DIR}/lib )
	set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_SOURCE_DIR}/lib )
endforeach( OUTPUTCONFIG CMAKE_CONFIGURATION_TYPES )

ExternalProject_Add(
	catch
	PREFIX ${CMAKE_SOURCE_DIR}/deps/catch
	GIT_REPOSITORY https://github.com/philsquared/Catch.git
	TIMEOUT 10
	UPDATE_COMMAND ${GIT_EXECUTABLE} pull
	CONFIGURE_COMMAND ""
	BUILD_COMMAND ""
	INSTALL_COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/deps/catch/src/catch/include ${CMAKE_SOURCE_DIR}/deps/catch/include
	LOG_DOWNLOAD ON
)

add_subdirectory( tests )

include_directories( ${CMAKE_SOURCE_DIR}/include )

set( CONWAY_LIB_HEADERS		include/conway/grid.h
				include/conway/conway.h )

set( CONWAY_LIB_SOURCES 	src/conway/grid.c
				src/conway/conway.c )

set( CONWAY_SOURCES 		src/cnwy.c
				include/ui/ui.h 
				src/ui/ui.c )

add_library( conway STATIC ${CONWAY_LIB_HEADERS} ${CONWAY_LIB_SOURCES} )
add_executable( cnwy ${CONWAY_HEADERS} ${CONWAY_SOURCES} )
target_link_libraries( cnwy conway ncurses )

set_property( TARGET conway PROPERTY C_STANDARD 11 )
set_property( TARGET cnwy PROPERTY C_STANDARD 11 )