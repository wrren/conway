#ifndef CONWAY_GRID_H
#define CONWAY_GRID_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/// Conway Grid Handle
typedef struct _conway_grid* conway_grid;

/**
 * Initialize a grid with the specified dimensions
 * @param  columns Number of columns in the grid
 * @param  rows    Number of rows in the grid
 * @return         Grid Handle
 */
conway_grid grid_init( uint32_t columns, uint32_t rows );

/**
 * Seed the grid with a random distribution of set cells
 * @param grid  Grid to be seeded
 * @param seed 	Seed Value
 */
void grid_seed( conway_grid grid, uint32_t seed );

/**
 * Copy the grid state from \a src to \a dest
 * @param dest Destination Grid
 * @param src  Source Grid
 */
void grid_copy( conway_grid dest, conway_grid src );

/**
 * Check whether the given row and column is set
 * @param  grid   Grid to check
 * @param  column Column Index
 * @param  row    Row Index
 * @return        true - If the given grid index is set, false otherwise
 */
bool grid_check( conway_grid grid, int32_t column, int32_t row );

/**
 * Set the state of the given grid coordinate
 * @param grid   Grid to be modified
 * @param column Column Index
 * @param row    Row Index
 * @param state  New Coordinate State
 */
void grid_set( conway_grid grid, uint32_t column, uint32_t row, bool state );

/**
 * Get the number of rows in the provied grid
 * @param  grid Grid Handle
 * @return      Number of Rows in Grid
 */
uint32_t grid_get_rows( conway_grid grid );

/**
 * Get the number of columns in the provied grid
 * @param  grid Grid Handle
 * @return      Number of Columns in Grid
 */
uint32_t grid_get_columns( conway_grid grid );

/**
 * Free a Conway Grid Handle
 * @param  grid Grid Handle
 * @return      NULL
 */
conway_grid grid_free( conway_grid grid );

#ifdef __cplusplus
}
#endif

#endif // CONWAY_GRID_H