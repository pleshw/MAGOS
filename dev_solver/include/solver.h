#ifndef PLESHW_SOLVER
#define PLESHW_SOLVER

#include <iostream>
#include <stack>
#include <string>
#include <cstring>
#include <stdlib.h>
#include "maze.h"
#include "configFileReader/configFileReader.h"

class Solver
{
	public:
		Solver ( Maze _maze, size_t _startFlagIndex, size_t _endFlagIndex )
		: maze           { _maze },
		  startFlagIndex { _startFlagIndex },
		  endFlagIndex   { _endFlagIndex },
		  actualIndex    { _startFlagIndex }
		{ 
			maze.checkCell( startFlagIndex ); 
			previousMoves.push( startFlagIndex );
		}

	/// Check the next cell that was not tested until find the endFlag 
	/// or there's not cells to be tested.
	void nextMove ( void );

	/// Back to the last visited cell that have moves to do
	/// discarding all already tested.
	void backtrack ( void );

	bool solved ( void )
		{ return actualIndex == endFlagIndex; }
	
	cell_t * buffer ( void )
		{ return maze.buffer(); }


	//Check if can move
	bool canMove ( void );
	bool canMoveTop      ( void );
	bool canMoveRight    ( void );
	bool canMoveBottom   ( void );
	bool canMoveLeft     ( void );

	//Move
	void moveTop    ( void );
	void moveRight  ( void );
	void moveBottom ( void );
	void moveLeft   ( void );

private:
	Maze maze;
	size_t startFlagIndex;
	size_t endFlagIndex;
	size_t actualIndex;
	std::stack< size_t > previousMoves; //!< Stack cells indexes that was already visited but not discarded.
};

#endif