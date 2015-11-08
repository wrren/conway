#include <conway/conway.h>
#include <stdlib.h>
#include <assert.h>

struct _conway
{
	/// Grid
	conway_grid grid;
	/// Previous Grid State
	conway_grid prev;
};

conway conway_init( uint32_t columns, uint32_t rows, uint32_t seed )
{
	conway c = malloc( sizeof( struct _conway ) );
	c->grid = grid_init( columns, rows );
	c->prev = grid_init( columns, rows );

	grid_seed( c->grid, seed );

	return c;
}

bool conway_alive( conway_grid grid, int32_t column, int32_t row )
{
	uint32_t alive_count = 0;

	for( int32_t i = column - 1; i < column + 2; i++ )
	{
		for( int32_t j = row - 1; j < row + 2; j++ )
		{
			if( !( j == row && i == column ) && grid_check( grid, i, j ) )
			{
				alive_count++;
			}
		}
	}

	if( grid_check( grid, column, row ) )
	{
		if( alive_count < 2 || alive_count > 3 )
		{
			return false;
		}

		return true;
	}
	else if( alive_count == 3 )
	{
		return true;
	}

	return false;
}

conway_grid conway_get_grid( conway c )
{
	return c->grid;
}

void conway_tick( conway c )
{
	grid_copy( c->prev, c->grid );

	for( uint32_t i = 0; i < grid_get_columns( c->grid ); i++ )
	{
		for( uint32_t j = 0; j < grid_get_rows( c->grid ); j++ )
		{
			grid_set( c->grid, i, j, conway_alive( c->prev, i, j ) );
		}
	}
}

conway conway_free( conway c )
{
	assert( c != NULL );

	grid_free( c->grid );
	grid_free( c->prev );

	free( c );

	return NULL;
}