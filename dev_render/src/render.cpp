#include "../include/render.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../include/stb_image_write.h"


using namespace canvas;


/// Draw the maze on canvas
void Render::info ( void )
{
	std::cout << std::endl << "_Settings {" 
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
	initCanvas();
	makeGrid( buffer );
	placeFlags();
}

void Render::makePNG ( std::string src )
{
	src += ".png";
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


void Render::initCanvas ( void )
{
	canvas.clear( background );
	canvas.thickness( wallThickness );
}


void Render::makeGrid ( cell_t * buffer )
{
	size_t horizontal_pos_x; // Store the position x of horizontal line in a cell
	size_t horizontal_pos_y; // Store the position y of horizontal line in a cell
	size_t vertical_pos_x; // Store the position x of vertical line in a cell
	size_t vertical_pos_y; // Store the position y of vertical line in a cell
	size_t index; // Store the index of each cell.
	for( size_t y(0); y < mazeRows; y++ )
	{
		for( size_t x(0); x < mazeCols; x++ )
		{
			//get the index of the cell.
			index = ( ( y*mazeCols ) + x );
			//get the horizontal pos of the cell considering the padding of canvas.
			horizontal_pos_x = ( origin_x + (wallWidth*x) );
			horizontal_pos_y = ( origin_y + (wallHeight*y) );
			//get the vertical pos of the cell considering the padding of canvas.
			vertical_pos_x   = ( origin_x + ((x+1)*wallWidth) );
			vertical_pos_y   = horizontal_pos_y;

			// draw top and right walls
			if( Maze::hasTopWall( &buffer[ index ] ) ){
				canvas.hLine( 
					horizontal_pos_x,
					horizontal_pos_y,
					(wallWidth+wallThickness),
					wallColor
				);
			}
			if( Maze::hasRightWall( &buffer[ index ] ) ){
				canvas.vLine( 
					vertical_pos_x,
					vertical_pos_y,
					(wallHeight+wallThickness),
					wallColor
				);
			}
			// highlight cells in certain conditions
			cell_t neighborhood [] = { 
				( (index - mazeCols) < mazeCols * mazeRows ) // have top wall
					? buffer[index - mazeCols] : (cell_t)0,
				( (index + 1) < mazeCols * mazeRows ) // have right wall
					? buffer[index + 1] : (cell_t)0,
				( (index + mazeCols) < mazeCols * mazeRows )// have bottom wall
					? buffer[index + mazeCols] : (cell_t)0,
				( (index - 1) < mazeCols * mazeRows )// have left wall
					? buffer[index - 1] : (cell_t)0,
			};

			highlightChecking  ( buffer[ index ], horizontal_pos_x, horizontal_pos_y );
			highlightVisited   ( buffer[ index ], horizontal_pos_x, horizontal_pos_y, neighborhood );
			highlightDiscarded ( buffer[ index ], horizontal_pos_x, horizontal_pos_y );
		}
	}
	canvas.vLine( origin_x, origin_y, mazeHeight, wallColor ); //drawing left wall
	canvas.hLine( origin_x, lastRowPosition, mazeWidth+wallThickness, wallColor ); //drawing bottom wall
}


void Render::placeFlags ( void )
{
	//get start flag horizontal pos considering the margin
	size_t startFlag_horizontal_x = ( origin_x + (wallWidth*startFlagX) );
	size_t startFlag_horizontal_y = ( origin_y + (wallHeight*startFlagY) );
	//get end flag horizontal pos considering the margin
	size_t endFlag_horizontal_x = ( origin_x + (wallWidth*endFlagX) );
	size_t endFlag_horizontal_y = ( origin_y + (wallHeight*endFlagY) );
	//draw the flags
	canvas.box( 
		startFlag_horizontal_x+wallThickness + (startFlagMargin/2),
		startFlag_horizontal_y+wallThickness + (startFlagMargin/2),
		wallWidth-wallThickness - startFlagMargin,
		wallHeight-wallThickness - startFlagMargin,
		GREEN_FLAG 
	);
	canvas.box( 
		endFlag_horizontal_x+wallThickness + (endFlagMargin/2),
		endFlag_horizontal_y+wallThickness + (endFlagMargin/2),
		wallWidth-wallThickness - endFlagMargin,
		wallHeight-wallThickness - endFlagMargin,
		RED_FLAG 
	);
}


void Render::highlightChecking ( cell_t& element, size_t& x, size_t& y )
{
	if( Maze::isChecking( &element ) ){
		canvas.box( 
			x+wallThickness + (checkingFlagMargin/2), 
			y+wallThickness + (checkingFlagMargin/2),
			wallWidth-wallThickness - checkingFlagMargin,
			wallHeight-wallThickness - checkingFlagMargin,
			checkingFlagColor 
		);
	}
}


void Render::highlightVisited ( cell_t& element, size_t& x, size_t& y, cell_t* neighborhood )
{
	if( Maze::wasVisited(&element) ){
		canvas.box(
			x+wallThickness + (visitedFlagMargin/2), 
			y+wallThickness + (visitedFlagMargin/2),
			wallWidth-wallThickness - visitedFlagMargin,
			wallHeight-wallThickness - visitedFlagMargin,
			visitedFlagColor 
		);
		if ( !Maze::hasTopWall( &element ) && !Maze::hasBottomWall( &(neighborhood[0]) ) && ( Maze::wasVisited(&(neighborhood[0])) || Maze::isChecking(&(neighborhood[0])) ) ){
				canvas.box( 
					x+wallThickness + (visitedFlagMargin/2),  // same x pos
					y, //drawing start from top of the cell
					wallWidth-wallThickness - visitedFlagMargin, // same width
					(visitedFlagMargin/2) + wallThickness, //fill the margin from top until the box
					visitedFlagColor 
				);
		}
		if ( !Maze::hasRightWall( &element ) && !Maze::hasLeftWall( &(neighborhood[1]) ) && ( Maze::wasVisited(&(neighborhood[1])) || Maze::isChecking(&(neighborhood[1])) ) ){
			canvas.box( 
				x + wallWidth - wallThickness - (visitedFlagMargin/2), //drawing start from the right of the box 
				y+wallThickness + (visitedFlagMargin/2), //drawing start from top of the visited box
				(visitedFlagMargin/2) + wallThickness,
				wallHeight-wallThickness - visitedFlagMargin,
				visitedFlagColor 
			);
		}
		if ( !Maze::hasBottomWall( &element ) && !Maze::hasTopWall( &(neighborhood[2]) ) && ( Maze::wasVisited(&(neighborhood[2])) || Maze::isChecking(&(neighborhood[2])) ) ){
			canvas.box( 
				x+wallThickness + (visitedFlagMargin/2),  // same x pos
				y-wallThickness + wallHeight - (visitedFlagMargin/2), //drawing start from bottom of the box
				wallWidth-wallThickness - visitedFlagMargin, // same width
				(visitedFlagMargin/2) + wallThickness, //fill the margin from top until the box
				visitedFlagColor 
			);
		}
		if ( !Maze::hasLeftWall( &element ) && !Maze::hasRightWall( &(neighborhood[3]) ) && ( Maze::wasVisited(&(neighborhood[3])) || Maze::isChecking(&(neighborhood[3])) ) ){
			canvas.box( 
				x, //drawing start from the left of the cell 
				y+wallThickness + (visitedFlagMargin/2), //drawing start from top of the visited box
				(visitedFlagMargin/2) + wallThickness,
				wallHeight-wallThickness - visitedFlagMargin,
				visitedFlagColor 
			);
		}
	}

}


void Render::highlightDiscarded ( cell_t& element, size_t& x, size_t& y )
{
	if( Maze::wasDiscarded( &element ) ){
		canvas.box( 
			x+wallThickness + (discardedFlagMargin/2), 
			y+wallThickness + (discardedFlagMargin/2), 
			wallWidth-wallThickness - discardedFlagMargin, 
			wallHeight-wallThickness - discardedFlagMargin, 
			discardedFlagColor 
		);
	}
}