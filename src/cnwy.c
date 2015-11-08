#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <unistd.h>

#include <conway/conway.h>
#include <ui/ui.h>

int main( int argc, char** argv )
{
	if( argc < 4 )
	{
		printf( "Usage:\n\tcnwy <fps> <cols> <rows>\n" );
	}

	int fps 	= atoi( argv[1] );
	int cols 	= atoi( argv[2] );
	int rows 	= atoi( argv[3] );

	float wait 	= ( 60.0 / ( double ) fps );

	conway c = conway_init( cols, rows, 1000 );
	conway_ui ui = ui_init( cols, rows );

	while( true )
	{
		conway_tick( c );
		ui_render( ui, conway_get_grid( c ) );
		sleep( wait );
	}

	return EXIT_SUCCESS;
}