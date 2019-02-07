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
/// Identify directions
enum Direction : cell_t { TOP=1, RIGHT = 2, BOTTOM = 4, LEFT = 8 };

class Maze
{
public:
//=== Alias
/// Identifies each byte in a cell.
enum CellBitmap : cell_t { 
	TOP         = 1, //!< Top wall active.
	RIGHT       = 2, //!< Right wall active.
	BOTTOM      = 4, //!< Bottom wall active.
	LEFT        = 8, //!< Left wall active.
	NOT_TESTED  = 16, //!< Not tested by the solver.
	CHECKING    = 32, //!< Being checked by the solver.
	VISITED     = 64, //!< Visited by the solver.
	DISCARDED   = 128 //!< Discarded by the solver.
};


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
		  Cells        { new cell_t[ Rows * Cols ] },
		  ErrorCell    { new cell_t }
		{ 
			std::memset( Cells.get(), 31, ( Rows * Cols ));
		} //every cell has all wall bits on and the NOT_TESTED bit on

	//=== Special members
	    /// Copy constructor.
		Maze( const Maze & );

	    /// Assignment operator.
		Maze & operator=( const Maze & );

	//=== Members
	    /// Reset the maze ( all cells states goes to 00000000 ).
		void reset ( void );

		/// Checks if the position exists.
		bool outside( size_t ); // using index
		bool outside( size_t, size_t ); // using 2d
		bool outside( size_t, Direction ); // [index] checking cell at [direction] of position
		bool outside( size_t, size_t, Direction ); // [coords] checking cell at [direction] of position


	    /// Get a pointer to a cell in a position of the grid.
	    cell_t * cell ( size_t ); // using index
		cell_t * cell ( size_t, size_t ); // using 2d

	    /// Change the state of a cell on the grid.
		void cell ( size_t, size_t , const cell_t& );

		/// Get a cell index.
		size_t getCellIndex ( size_t x, size_t y ) // using 2d
			{ return (y*Cols) + x; }

	    /// Get the state of the cell neighbor in selected direction on grid.
	    cell_t * neighbor ( cell_t*, Direction ); // using cell pointer
	    cell_t * neighbor ( size_t, Direction ); // using index
		cell_t * neighbor ( size_t, size_t , Direction ); // using coords

	    /// Change the state of the cell neighbor in selected direction on grid.
		void neighbor ( size_t, size_t , Direction, const cell_t&  );

		/// Get a neighbor cell index.
		size_t getNeighborIndex ( size_t, Direction ); // using index
		size_t getNeighborIndex ( size_t, size_t, Direction ); // using 2d

	    /// Remove a wall of a cell.
	    bool removeWall ( cell_t*, Direction ); // using the cell
	    bool removeWall ( size_t, Direction ); //using the index
		bool removeWall ( size_t, size_t , Direction ); // using 2d coordinate

		/// Remove the oposite wall from the neighbor cell in a direction of a selected cell.
		/*
	     * Example:
	     *
	     * ```
	     * (c.x, c.y), direction = right.
	     *  c represents the cell | n represents his neighbor | x represents the wall of cells
	     *  |
	     *  v
	     *  x x x . x x 
	     *  x c x . n x 
	     *  x x x . x x 
	     * ```
	     *  Note that the left wall from the right neighbor of the cell was removed
	     */
		bool removeOpositeWall ( cell_t*, Direction ); // using a pointer to cell
		bool removeOpositeWall ( size_t, Direction ); // using index
		bool removeOpositeWall ( size_t, size_t, Direction ); // using 2d
	
		/*!
		 * Verify if top wall bit of a cell is on.
		 */
		static bool hasTopWall ( cell_t* ); // using cell pointer
		bool hasTopWall ( size_t ); // using index
		bool hasTopWall ( size_t, size_t ); // using coords
		/*!
		 * Verify if right wall bit of a cell is on.
		 */
		static bool hasRightWall ( cell_t* );
		bool hasRightWall ( size_t );
		bool hasRightWall ( size_t, size_t );
		/*!
		 * Verify if bottom wall bit of a cell is on.
		 */
		static bool hasBottomWall ( cell_t* );
		bool hasBottomWall ( size_t );
		bool hasBottomWall ( size_t, size_t );
		/*!
		 * Verify if left wall bit of a cell is on.
		 */
		static bool hasLeftWall ( cell_t* );
		bool hasLeftWall ( size_t );
		bool hasLeftWall ( size_t, size_t );
		/*!
		 * Verify if NOT_TESTED bit of a cell is on.
		 */
		static bool wasNotTested ( cell_t* );
		bool wasNotTested ( size_t );
		bool wasNotTested ( size_t, size_t );
		/*!
		 * Verify if CHECKING bit of a cell is on.
		 */
		static bool isChecking ( cell_t* );
		bool isChecking ( size_t );
		bool isChecking ( size_t, size_t );
		/*!
		 * Verify if VISITED bit of a cell is on.
		 */
		static bool wasVisited ( cell_t* );
		bool wasVisited ( size_t );
		bool wasVisited ( size_t, size_t );
		/*!
		 * Verify if DISCARDED bit of a cell is on.
		 */
		static bool wasDiscarded ( cell_t* );
		bool wasDiscarded ( size_t );
		bool wasDiscarded ( size_t, size_t );
		/*!
		 * Turn on the CHECKING bit of a cell.
		 */
		static void checkCell ( cell_t* );
		void checkCell ( size_t );
		void checkCell ( size_t, size_t );
		/*!
		 * Turn on the VISITED bit of a cell.
		 */
		static void visitCell ( cell_t* );
		void visitCell ( size_t );
		void visitCell ( size_t, size_t );
		/*!
		 * Turn on the DISCARDED bit of a cell.
		 */
		static void discardCell ( cell_t* );
		void discardCell ( size_t );
		void discardCell ( size_t, size_t );


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

		cell_t* cellOutOfRange () const
			{ return ErrorCell.get(); }

private:
	size_t Rows; //!< The grid height in cells.
    size_t Cols; //!< The grid width in cells.
    std::shared_ptr< cell_t[] > Cells; //!< The cells, stored as 8bits components.
    std::unique_ptr< cell_t > ErrorCell; //!< The cell returned when error occur.;
};

#endif