cmake_minimum_required( VERSION 3.2 )
project( tests )

link_directories( 	${CMAKE_SOURCE_DIR}/lib )

include_directories( 	${CMAKE_SOURCE_DIR}
			${CMAKE_SOURCE_DIR}/include
			${CMAKE_SOURCE_DIR}/deps/catch/include )

add_executable(		tests
 			grid.cpp )

target_link_libraries( tests conway )
set_property( TARGET tests PROPERTY C_STANDARD 11 )
set_property( TARGET tests PROPERTY CXX_STANDARD 11 )