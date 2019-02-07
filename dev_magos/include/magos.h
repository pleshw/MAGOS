#ifndef PLESHW_MAGOS
#define PLESHW_MAGOS

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include "canvas.h"
#include "maze.h"
#include "builder.h"
#include "solver.h"
#include "render.h"
#include "configFileReader/configFileReader.h"

class MAGOS{

	public:
		MAGOS( configFile _entries )
		: setup   { _entries },
		  canvas  { Canvas{ stoul(setup["canvasWidth"]), stoul(setup["canvasHeight"]) } },
		  maze    { Maze{ stoul(setup["mazeRows"]), stoul(setup["mazeCols"]) } }
		{ /* VOID */ }

	public:
		/// Build and renderize a maze as png images in /[outputBuilding]
		void build( void );
		/// Solve and renderize a maze as png in [/outputSolver]
		void solve( void );

	private:
		configFile setup;
		Canvas canvas;
		Maze maze;
};


#endif