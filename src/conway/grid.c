#include <conway/grid.h>
#include <assert.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/**
 * Conway Grid
 */
struct _conway_grid
{
	/// Dimensions
	uint32_t columns, rows;
	/// Grid Buffer
	uint8_t* grid;
};

conway_grid grid_init( uint32_t columns, uint32_t rows )
{
	assert( columns != 0 );
	assert( rows 	!= 0 );

	size_t buf_size = ( ( columns * rows ) / CHAR_BIT ) + 1;

	conway_grid grid = malloc( sizeof( struct _conway_grid ) );

	grid->columns 	= columns;
	grid->rows 	= rows;
	grid->grid 	= malloc( buf_size );

	memset( grid->grid, 0, buf_size );

	return grid;
}

void grid_seed( conway_grid grid, uint32_t seed )
{
	if( seed < ( ( grid->rows * grid->columns ) / 4 ) )
	{
		seed += ( ( grid->rows * grid->columns ) / 4 );
	}

	srand( time( NULL ) );

	for( uint32_t i = 0; i < seed; i++ )
	{
		grid_set( 	grid, 
				rand() % grid->columns, 
				rand() % grid->rows,
				true );
	}
}

void grid_copy( conway_grid dest, conway_grid src )
{
	assert( dest->rows == src->rows && dest->columns == src->columns );

	size_t buf_size = ( ( src->columns * src->rows ) / CHAR_BIT ) + 1;
	memcpy( dest->grid, src->grid, buf_size );
}

bool grid_check( conway_grid grid, int32_t column, int32_t row )
{
	if( column >= grid->columns || row >= grid->rows )
	{
		return false;
	}

	uint32_t index 	= ( ( row * grid->columns ) + column ) / CHAR_BIT;
	uint8_t rem 	= ( ( row * grid->columns ) + column ) % CHAR_BIT;
	uint8_t cell 	= grid->grid[index];

	return ( cell >> rem ) & 0x01;
}

void grid_set( conway_grid grid, uint32_t column, uint32_t row, bool state )
{
	if( column >= grid->columns || row >= grid->rows )
	{
		return;
	}

	uint32_t index 		= ( ( row * grid->columns ) + column ) / CHAR_BIT;
	uint8_t rem 		= ( ( row * grid->columns ) + column ) % CHAR_BIT;
	uint8_t cell 		= grid->grid[index];
	
	if( state )
	{
		grid->grid[index] |= ( 1 << rem );	
	}
	else
	{
		grid->grid[index] &= ~( 1 << rem );
	}
}

uint32_t grid_get_rows( conway_grid grid )
{
	return grid->rows;
}

uint32_t grid_get_columns( conway_grid grid )
{
	return grid->columns;
}

conway_grid grid_free( conway_grid grid )
{
	if( grid != NULL )
	{
		free( grid->grid );
		free( grid );
	}

	return NULL;
}
