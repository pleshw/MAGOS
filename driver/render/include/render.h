#ifndef PLESHW_RENDER
#define PLESHW_RENDER

#include <iostream>
#include <string>
#include <cstring>
#include "common.h"
#include "canvas.h"
#include "maze.h"
#include "configFileReader/configFileReader.h"

class Render
{
	public:
		Render ( Canvas& _c,  Maze& _m, configFile& _entries )
		: canvas               { _c },
		  canvasWidth          { _c.width() },
		  canvasHeight         { _c.height() },
		  canvasPaddingTop     { stoul( _entries["canvasPaddingTop"] ) },
		  canvasPaddingLeft    { stoul( _entries["canvasPaddingLeft"] ) },
		  mazeRows             { _m.rows() },
		  mazeCols             { _m.cols() },
		  wallThickness        { stoul( _entries["wallThickness"] ) },
		//canvas properties
			  innerSpaceVertical   { (canvasHeight - ( canvasPaddingTop*2 )) },
			  innerSpaceHorizontal { (canvasWidth  - ( canvasPaddingLeft*2 )) },
			  centerVertical       { (canvasHeight - ( canvasPaddingTop*2 ))/2 },
			  centerHorizontal     { (canvasWidth - ( canvasPaddingLeft*2 ))/2 },
			  background           { LIGHT_GREY },
		//maze properties
			  wallWidth  { innerSpaceHorizontal/mazeCols },
			  wallHeight { innerSpaceVertical/mazeRows },
			  mazeWidth  { wallWidth*mazeCols },
			  mazeHeight { wallHeight*mazeRows },
			  cellArea   { wallWidth*wallHeight },
			  wallColor  { BLACK },
		//maze usual
			  origin_x { canvasPaddingLeft - (wallThickness/2) },
			  origin_y { canvasPaddingTop - (wallThickness/2) },
			  lastColPosition { (wallWidth*mazeCols) + origin_x },
			  lastRowPosition { (wallHeight*mazeRows) + origin_y }
		{ canvas.clear( background ); canvas.thickness( wallThickness ); }

		/// Show info about the class via console
		void info ( void );
		/// Get the maze buffer then draw it on canvas.
		void draw ( cell_t *_m );
		/// Make a png image of the canvas on selected source
		void makePNG ( std::string src );



private:
	//source data
	Canvas canvas;
	size_t canvasWidth; //!< Canvas width in pixels.
	size_t canvasHeight; //!< Canvas height in pixels.
	size_t canvasPaddingTop; //!< Canvas padding top-bottom in pixels.
	size_t canvasPaddingLeft; //!< Canvas padding left-right in pixels.
	size_t mazeRows; //!< Number of rows on maze.
	size_t mazeCols; //!< Number of cols on maze.
	size_t wallThickness; //!< Thickness of each wall.
	//canvas properties
	size_t innerSpaceVertical; //!< Vertical space inner canvas considering the padding.
	size_t innerSpaceHorizontal; //!< Horizontal space inner canvas considering the padding.
	size_t centerVertical; //!< Vertical center position in pixels of the canvas considering the padding.
	size_t centerHorizontal; //!< Horizontal center position in pixels of the canvas considering the padding.
	Color  background; //!< Color of background of the canvas.
	//maze properties
	size_t wallWidth; //!< Size of each wall in pixels.
	size_t wallHeight; //!< Size of each wall in pixels.
	size_t mazeWidth; //!< Maze width in pixels.
	size_t mazeHeight; //!< Maze height in pixels.
	size_t cellArea; //!< The area of each cell in pixels.
	Color  wallColor; //!< Color of each cell wall.
	//maze usual
	size_t origin_x;  //!< The pixel position where maze starts to be drawed.
	size_t origin_y; //!< The pixel position where maze starts to be drawed.
	size_t lastColPosition; //!< The pixel position of the last horizontal pixel in the maze.
	size_t lastRowPosition; //!< The pixel position of the last vertical pixel in the maze.
};

#endif