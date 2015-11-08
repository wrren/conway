#include <ui/ui.h>
#include <stdlib.h>
#include <stdint.h>

#include <ncurses.h>

/// UI Handle
struct _conway_ui
{
	/// Grid Dimensions
	uint32_t columns, rows;
};

conway_ui ui_init( uint32_t columns, uint32_t rows )
{
	conway_ui ui 	= malloc( sizeof( struct _conway_ui ) );
	ui->columns 	= columns;
	ui->rows 	= rows;

	initscr();

	return ui;
}

void ui_render( conway_ui ui, conway_grid grid )
{
	for( uint32_t i = 0; i < ui->columns; i++ )
	{
		for( uint32_t j = 0; j < ui->rows; j++ )
		{
			mvaddch( j, i, grid_check( grid, i, j ) ? '*' : ' ' );
		}
	}

	refresh();
}

conway_ui ui_free( conway_ui ui )
{
	endwin();
	free( ui );
	return NULL;
}