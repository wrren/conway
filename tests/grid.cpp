#define CATCH_CONFIG_MAIN

#include <conway/grid.h>
#include <catch.hpp>

TEST_CASE( "Grid State", "[grid]" )
{
	conway_grid grid = grid_init( 10, 10 );
	
	REQUIRE( grid_check( grid, 0, 0 ) == false );
	

	grid_set( grid, 0, 1, true );
	REQUIRE( grid_check( grid, 0, 1 ) == true );

	grid_set( grid, 9, 9, true );
	REQUIRE( grid_check( grid, 9, 9 ) == true );

	grid_set( grid, 0, 1, false );
	REQUIRE( grid_check( grid, 0, 1 ) == false );

	grid_free( grid );
}