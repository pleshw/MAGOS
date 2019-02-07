#ifndef PLESHW_RENDER
#define PLESHW_RENDER

#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include "common.h"
#include "canvas.h"
#include "maze.h"
#include "configFileReader/configFileReader.h"

using namespace canvas;


// Scheme renderScheme;
// renderScheme["BLACK"] = Color{0,0,0}; //!< Black.
// renderScheme["WHITE"]         = Color{255,255,255}; //!< White.
// renderScheme["DARK_GREEN"]    = Color{0,100,0}    ; //!< Dark green.
// renderScheme["GREEN"]         = Color{0,250,0}    ; //!< Green.
// renderScheme["GREEN_FLAG"]    = Color{103,178,103}; //!< Green flag.
// renderScheme["RED"]           = Color{255,0,0}    ; //!< Red.
// renderScheme["RED_FLAG"]      = Color{149,66,244} ; //!< Red flag.
// renderScheme["CRIMSON"]       = Color{220,20,60}  ; //!< Crimson (kind of red).
// renderScheme["LIGHT_BLUE"]    = Color{135,206,250}; //!< Light blue.
// renderScheme["LIGHT_GREY"]    = Color{210,210,210}; //!< Light blue.
// renderScheme["DEEP_SKY_BLUE"] = Color{0,191,255}  ; //!< Deep blue.
// renderScheme["DODGER_BLUE"]   = Color{30,144,255} ; //!< Another bluish color.
// renderScheme["STEEL_BLUE"]    = Color{70,130,180} ; //!< Yet another bluish color.
// renderScheme["YELLOW"]        = Color{255,255,0}  ; //!< Yellow.
// renderScheme["LIGHT_YELLOW"]  = Color{255,255,153}; //!< Light yellow.

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
		//Canvas properties
			  innerSpaceVertical   { (canvasHeight - ( canvasPaddingTop*2 )) },
			  innerSpaceHorizontal { (canvasWidth  - ( canvasPaddingLeft*2 )) },
			  centerVertical       { (canvasHeight - ( canvasPaddingTop*2 ))/2 },
			  centerHorizontal     { (canvasWidth - ( canvasPaddingLeft*2 ))/2 },
			  background           { LIGHT_GREY },
		//Maze properties
			  wallWidth  { innerSpaceHorizontal/mazeCols },
			  wallHeight { innerSpaceVertical/mazeRows },
			  mazeWidth  { wallWidth*mazeCols },
			  mazeHeight { wallHeight*mazeRows },
			  cellArea   { wallWidth*wallHeight },
			  wallColor  { BLACK },
		//Maze usual
			  origin_x { canvasPaddingLeft - (wallThickness/2) },
			  origin_y { canvasPaddingTop - (wallThickness/2) },
			  lastColPosition { (wallWidth*mazeCols) + origin_x },
			  lastRowPosition { (wallHeight*mazeRows) + origin_y },
		//Extras
			  startFlagIndex       { stoul( _entries["startFlagIndex"] ) },
			  endFlagIndex         { stoul( _entries["endFlagIndex"] ) },
			  startFlagX           { startFlagIndex % mazeCols },
			  endFlagX             { endFlagIndex % mazeCols },
			  startFlagY           { startFlagIndex / mazeCols },
			  endFlagY             { endFlagIndex / mazeCols },
			  startFlagMargin      { stoul( _entries["startFlagMargin"] ) },
			  endFlagMargin        { stoul( _entries["endFlagMargin"] ) },
			  checkingFlagColor    { YELLOW /*ColorScheme[ _entries["checkingFlagColor"] ] */ },
			  visitedFlagColor     { DODGER_BLUE /*ColorScheme[ _entries["visitedFlagColor"] ]  */},
			  discardedFlagColor   { CRIMSON /*ColorScheme[ _entries["discardedFlagColor"] ] */ },
			  checkingFlagMargin   { stoul( _entries["checkingFlagMargin"]) },
			  visitedFlagMargin    { stoul( _entries["visitedFlagMargin"]) },
			  discardedFlagMargin  { stoul( _entries["discardedFlagMargin"]) }
		{ canvas.clear( background ); canvas.thickness( wallThickness ); }

		/// Show info about the class via console
		void info ( void );

		/// Get a maze buffer then draw it on canvas.
		/*!
		 *@note The buffer SHOULD have the same number of cols and rows of the used on constructor
		 */
		void draw ( cell_t* );
		/// Make a png image of the canvas on selected source
		void makePNG ( std::string src );

		/// Clear canvas and make the setup to drawing on it.
		void initCanvas ( void );

		/// Draw the grid on canvas.
		void makeGrid ( cell_t* );

		/// Place the flags on canvas.
		void placeFlags ( void );

		/// Highlight the cell actually being checked.
		void highlightChecking ( cell_t&, size_t&, size_t& );

		/// Highlight all the visited cells.
		/// @note If is wanted that the visited cells visually look like a path then set the index. 
		void highlightVisited ( cell_t&, size_t&, size_t&, cell_t* );

		/// Highlight all the discarded cells.
		void highlightDiscarded ( cell_t&, size_t&, size_t& );

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
	//Extras
	size_t startFlagIndex; //!< The index of the cell which will be the start point of solver.
	size_t endFlagIndex; //!< The index of the cell which will be the goal of solver.
	size_t startFlagX; //!< The X coord of the start flag.
	size_t endFlagX; //!< The X coord of the goal flag.
	size_t startFlagY; //!< The Y coord of the start flag.
	size_t endFlagY; //!< The Y coord of the goal flag.
	size_t startFlagMargin; //!< The margin of the flag in relation to it cell walls.
	size_t endFlagMargin; //!< The margin of the flag in relation to it cell walls.
	Color checkingFlagColor;
	Color visitedFlagColor;
	Color discardedFlagColor;
	size_t checkingFlagMargin;
	size_t visitedFlagMargin;
	size_t discardedFlagMargin;
};

#endif