#ifndef PLESHW_BUILDER
#define PLESHW_BUILDER

#include <iostream>
#include <map>
#include <set>
#include <list>
#include <string>
#include <cstring>
#include <time.h>
#include <stdlib.h>
#include "maze.h"
#include "configFileReader/configFileReader.h"

using cell_path_iterator = std::map< size_t, std::set< cell_t* >>::iterator;

class Builder
{
	public:
		Builder ( Maze& _m )
		: maze { _m }
		{ 
			for( size_t y(0); y < maze.rows(); ++y ){
				for( size_t x(0); x < maze.cols(); ++x ){
					Path[ (y * maze.cols()) + x ].insert( maze.cell( x, y ) );
				}
			}
		}

		/// Break a wall and its oposite on maze.
		///@return True if wall could be removed.
		//only if the cell and its neighbor have different hashs.
		bool brickBreak ( size_t, Direction ); // using index
		bool brickBreak ( size_t, size_t, Direction ); // using coords

		/// Check if there's only one element in map.
		/*!
		 * That means that the labyrinth is a perfect maze.
		!*/
		bool isPerfect ( void )
			{ return ( Path.size() == 1 ); }

		/// Return a pointer to the maze grid.
		Maze getMaze ( void )
			{ return maze; }

		/// Return a pointer to the maze grid.
		cell_t * buffer ( void ) const
			{ return maze.buffer(); }

		/// Return the number of paths.
		size_t paths ( void )
			{ return Path.size(); }

		/// Get the iterator of a cell.
		/// If iterator is not found Path.end() is returned.
		cell_path_iterator findIteratorOf ( cell_t* );
		cell_path_iterator findIteratorOf ( size_t );

		/// Get a random position for a X coord in maze range.
		coord_type getRandomX ( void )
			{ return rand() % maze.cols(); }

		/// Get a random position for a Y coord in maze range.
		coord_type getRandomY ( void )
			{ return rand() % maze.rows(); }

		/// Get a random direction.
		static Direction getRandomDirection ( void );

		size_t getSingleCells ( void );

		/// Find the index of the very first cell that do not form path's with any other
		size_t findSingleCell ( void );

		bool isPath ( cell_path_iterator, cell_path_iterator );

		bool canBreak ( size_t, size_t, Direction );

private:
	/*! A map with pointers to cells in a maze as keys.
	 * associated with a list of cells that already make a path with that one.
	!*/
	std::map< size_t, std::set< cell_t* >> Path;
	Maze maze;
};

#endif