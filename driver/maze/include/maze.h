#ifndef PLESHW_MAZE
#define PLESHW_MAZE

#include <iostream>
#include <memory>
#include <cstring>
#include <stdexcept>
#include "common.h"

using namespace canvas;
 //! Provides methods for make a grid and setup a maze.
    /*!
     * This is a class to make a grid for a maze.
     * Each cell in grid is a 8bit switch element and each bit indicate a possible state of the cell
     * For example: a cell with 1111 has all the walls up and a cell with 0111 has the top wall down 
     */

typedef unsigned char cell_t; //!< Type of a cell.
class Maze
{
public:
//=== Alias
/// Identifies each byte in a cell.
enum cell_list_identifier : cell_t { 
	TOP    = 0, //!< Top wall active.
	RIGHT  = 1, //!< Right wall active.
	BOTTOM = 2, //!< Bottom wall active.
	LEFT   = 3 //!< Left wall active.
};
/// Used identify directions
enum class Direction { TOP=0, RIGHT, BOTTOM, LEFT };

	public:
	    //=== Special members
	    /// Constructor
	    /*! Creates an grid with the requested num of cols and lines to build a maze.
	     * @note Each position on grid is called and treated as a unique cell.
	     * @param Cols Number of maze collums.
	     * @param Rows Number of maze lines.
	     */
		Maze( size_t _rows = 0, size_t _cols = 0 )
		: Rows         { _rows },
		  Cols         { _cols }, 
		  Cells        { new cell_t[ Cols * Rows ] }
		{ std::memset( Cells.get(), 255, ( Cols * Rows )); } //every cell has all wall bits on

	//=== Special members
	    /// Copy constructor.
		Maze( const Maze & );

	    /// Assignment operator.
		Maze & operator=( const Maze & );

	//=== Members
	    /// Reset the maze ( all cells states goes to 00000000 ).
		void reset ( void );

		/// Checks if the position exists.
		bool outside ( coord_type, coord_type );
	   
	    /// Get the cell state from a cell in a position of the grid.
		cell_t * cell ( coord_type, coord_type );

	    /// Change the state of a cell on the grid.
		void cell ( coord_type, coord_type , const cell_t& );

	    /// Get the state of the cell neighbor in selected direction on grid.
		cell_t * neighbor ( coord_type, coord_type , Direction );

	    /// Change the state of the cell neighbor in selected direction on grid.
		void neighbor ( coord_type, coord_type , Direction, const cell_t&  );

	    /// Remove a wall of a cell.
	    void removeWall ( cell_t*, Direction );
		void removeWall ( coord_type, coord_type , Direction );

		/// Remove the oposite wall from the neighbor cell in a direction of a selected cell.
		/*
	     * Example:
	     *
	     * ```
	     * (p.x, p.y), direction = right.
	     *  c represents the cell | n represents his neighbor | x represents the wall of cells
	     *  |
	     *  v
	     *  x x x . x x 
	     *  x c x . n x 
	     *  x x x . x x 
	     * ```
	     *  Note that the left wall from the right neighbor of the cell was removed
	     */
		void removeOpositeWall ( coord_type, coord_type, Direction );
	
	
	//=== Attribute accessors members.
	    /// Get the grid height.
		size_t rows( void ) const
			{ return Rows; }

	    /// Get the grid width.
		size_t cols( void ) const
			{ return Cols; }
	  
	    /// Get the grid cells, as an array of `unsigned char`.
		cell_t* buffer( void ) const
			{ return Cells.get(); }

private:
	size_t Rows; //!< The grid height in cells.
    size_t Cols; //!< The grid width in cells.
    std::shared_ptr< cell_t[] > Cells; //!< The cells, stored as 8bits components.
    std::unique_ptr< cell_t >   ErrorCell; //!< The cell returned when error occur.;
};

#endif