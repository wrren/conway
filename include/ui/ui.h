#ifndef CONWAY_UI_H
#define CONWAY_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#include <conway/grid.h>

/// UI Handle
typedef struct _conway_ui* conway_ui;

/**
 * Initialize the grid UI
 * @param  columns Number of grid columns to display
 * @param  rows    Number of grid rows to display
 * @return         UI Handle
 */
conway_ui ui_init( uint32_t columns, uint32_t rows );

/**
 * Render the current state of the provided grid
 * @param ui   UI Handle
 * @param grid Grid to be rendered
 */
void ui_render( conway_ui ui, conway_grid grid );

/**
 * Free any resources consumed by the UI
 * @param  ui UI Handle
 * @return    NULL
 */
conway_ui ui_free( conway_ui ui );

#ifdef __cplusplus
}
#endif

#endif // CONWAY_UI_H