#include <iostream>
#include <cstring>
#include <stdexcept>

#include "../include/render.h"


using namespace canvas;

int main ( void )
{
	configFile setup = configFileReader::getConfigs("entrada.txt");

	size_t setupCanvasWidth       { stoul(setup["canvasWidth"]) };
	size_t setupCanvasHeight      { stoul(setup["canvasHeight"]) };
	size_t setupMazeRows          { stoul(setup["mazeRows"]) };
	size_t setupMazeCols          { stoul(setup["mazeCols"]) };

	//constructors
	Canvas cnv { setupCanvasWidth, setupCanvasHeight }; //!< The canvas where the maze should be drawed.
	Maze   mze { setupMazeRows, setupMazeCols };   //!< The maze to be drawed.

	mze.removeWall( 1, 1, Maze::Direction::TOP );
	mze.removeOpositeWall( 1, 1, Maze::Direction::LEFT );

	Render renderer ( cnv, mze, setup );

	renderer.info();

	renderer.draw ( mze.buffer() );
	renderer.makePNG ( setup["output"] );

	return 0;
}
