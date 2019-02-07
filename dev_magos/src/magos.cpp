#include "../include/magos.h"

/// Build and renderize a maze as png images in /[outputBuilding]
void MAGOS::build( void )
{
	Builder builder { maze };

	Render render { canvas, maze, setup };

	size_t counter { 0 };
	size_t seed_counter { 0 };

	while( !builder.isPerfect() ) 
	{
		srand (time(NULL) + seed_counter++);
		if ( builder.brickBreak( builder.getRandomX(), builder.getRandomY(), builder.getRandomDirection() ) )
		{
			render.draw ( builder.buffer() );
			render.makePNG ( std::string( setup["outputBuilding"] + std::to_string(counter++) ) );
		} else if ( builder.brickBreak( builder.findSingleCell(), builder.getRandomDirection() ) )
		{
			render.draw ( builder.buffer() );
			render.makePNG ( std::string( setup["outputBuilding"] + std::to_string(counter++) ) );
		}
		// In the last's 10% cells the aproach to building change
		if ( (maze.cols()*maze.rows() - counter) < (1/10)*(maze.rows()*maze.cols()) )
		{
			for (size_t i = 0; i < maze.rows(); ++i)
			{
				for (size_t j = 0; j < maze.cols(); ++j)
				{
					if ( builder.brickBreak( i, j, builder.getRandomDirection() ) )
					{
						render.draw ( builder.buffer() );
						render.makePNG ( std::string( setup["outputBuilding"] + std::to_string(counter++) ) );
					}
				}
			}
		}
	}

	maze = builder.getMaze();
}


/// Solve and renderize a maze as png in [/outputSolver]
void MAGOS::solve( void )
{
	size_t counter { 0 };

	Render render { canvas, maze, setup };

	Solver solver { maze, stoul(setup["startFlagIndex"]), stoul(setup["endFlagIndex"]) };

	while( !solver.solved() ) 
	{
		solver.nextMove();
		render.draw ( solver.buffer() );
		render.makePNG ( std::string( setup["outputSolver"] + std::to_string(counter++) ) );
	}
}