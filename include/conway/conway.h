#ifndef CONWAY_H
#define CONWAY_H

#include <conway/grid.h>

#ifdef __cplusplus
extern "C" {
#endif

/// Conway Handle
typedef struct _conway* conway;

/**
 * Initialize a conway's game of life handle that can be used to
 * drive the game.
 * @param  columns Number of columns in the grid
 * @param  rows    Number of rows in the grid
 * @param  seed    Grid seed value
 * @return         Conway Handle
 */
conway conway_init( uint32_t columns, uint32_t rows, uint32_t seed );

/**
 * Get the grid being simulated by this conway handle
 * @param  c Conway Handle
 * @return   Grid
 */
conway_grid conway_get_grid( conway c );

/**
 * Move the simulation forward
 * @param c Conway Handle
 */
void conway_tick( conway c );

/**
 * Free the resources consumed by the provided conway handle
 * @param  c Conway Handle
 * @return   NULL
 */
conway conway_free( conway c );

#ifdef __cplusplus
}
#endif

#endif // CONWAY_H