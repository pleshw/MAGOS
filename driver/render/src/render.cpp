#include "../include/render.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../include/stb_image_write.h"


using namespace canvas;


/// Draw the maze on canvas
void Render::info ( void )
{
	std::cout << std::endl << "S E T U P {" 
			  << std::endl << "    Canvas Width         "  << canvasWidth   << "px"
			  << std::endl << "    Canvas Height        "  << canvasHeight  << "px"
			  << std::endl << "    Canvas Top Padding   "  << canvasPaddingTop << "px"
			  << std::endl << "    Canvas Left Padding  "  << canvasPaddingLeft << "px"
			  << std::endl << "    Canvas Free Area     "  << innerSpaceVertical*innerSpaceHorizontal << "px"			  
			  << std::endl << "    Maze Rows            "  << mazeRows
			  << std::endl << "    Maze Cols            "  << mazeCols
			  << std::endl << "    Wall Thickness       "  << wallThickness << "px"
			  << std::endl << "    Wall Width           "  << wallWidth     << "px"
			  << std::endl << "    Wall Height          "  << wallHeight    << "px"
			  << std::endl << "    Cell Area            "  << cellArea      << "px"
			  << std::endl << "}"
			  << std::endl << std::endl;
}

void Render::draw ( cell_t *buffer )
{
	canvas.clear( background );
	canvas.thickness( wallThickness );
	size_t horizontal_pos_x; // Store the position x of horizontal line in a cell
	size_t horizontal_pos_y; // Store the position y of horizontal line in a cell
	size_t vertical_pos_x; // Store the position x of vertical line in a cell
	size_t vertical_pos_y; // Store the position y of vertical line in a cell

	for( size_t y(0); y < mazeRows; y++ )
	{
		for( size_t x(0); x < mazeCols; x++ )
		{
			horizontal_pos_x = (origin_x + (wallWidth*x));
			horizontal_pos_y = (origin_y + (wallHeight*y));

			vertical_pos_x   = ( origin_x + ((x+1)*wallWidth) );
			vertical_pos_y   = horizontal_pos_y;

			if( (buffer[ (y*mazeCols) + x ] & 1) == 1 ) // ( any byte with bit 1 active )& 0001 == 1 
				 //top wall
				canvas.hLine( horizontal_pos_x, horizontal_pos_y, (wallWidth+wallThickness), wallColor );
			if( (buffer[ (y*mazeCols) + x ] & 2) == 2 )
				 //right wall
				canvas.vLine( vertical_pos_x, vertical_pos_y, (wallHeight+wallThickness), wallColor );
		}
	}
	canvas.vLine( origin_x, origin_y, mazeHeight, wallColor ); //drawing left wall
	canvas.hLine( origin_x, lastRowPosition, mazeWidth+wallThickness, wallColor ); //drawing bottom wall
}

void Render::makePNG ( std::string src )
{
	// Invocando a função de gravação da biblioteca STB para gravar PNG.
    stbi_write_png_compression_level = 0;    // defaults to 8; set to higher for more compression
    stbi_write_png( 
            src.c_str(),               // file name
            canvasWidth, canvasHeight, // image dimensions
            3,                         // # of channels per pixel
            canvas.buffer(),           // the pixels
            canvasWidth*3
    ); 
}