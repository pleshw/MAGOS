#include "../include/maze.h"



    /*!
     * Deep copy of the canvas.
     * @param clone The object we are copying from.
     */
    Maze::Maze( const Maze &clone )
    {
        Rows = clone.rows();
        Cols  = clone.cols();
        Cells.reset( new cell_t[Rows * Cols]  );
        std::memcpy( Cells.get(), clone.Cells.get(), sizeof( cell_t )*Rows*Cols);  
    }

    /*!
     * @param source The object we are copying information from.
     * @return A reference to the `this` object.
     */
    Maze& Maze::operator=( const Maze & source )
    {
        if ( &source != this )
            std::memcpy( Cells.get(), source.Cells.get(), sizeof( cell_t )*Cols*Rows);
        return *this;
    }

    void Maze::reset( void )
    {
        std::memset( Cells.get(), 0, ( Cols * Rows ));
        // for(size_t y(0); y < Rows; y++)
        //     for(size_t x; x < Cols; x++)
        //         cell(x, y, 0);
    }

    /*!
     * @throw `std::invalid_argument()` if the coordinate is located outside the grid.
     * @param p The 2D coordinate.
     * @return True if the cordinate is outside the grid, otherwise False.
     */
    bool Maze::outside( coord_type x, coord_type y )
    {
        if(x > Cols )
        {
        	std::invalid_argument( "X Out of range" );
        	return true;
        }
        if(y > Rows )
        {
        	std::invalid_argument( "Y Out of range" );
        	return true;
        }
        return false;
    }

    /*!
     * Call `outside` to check if the cell coordinate is located outside the grid.
     * @note If the  cell coordinate is located outside the grid the ErrorCell is returned.
     * If outside the function will return the first cell of the grid.
     * @param p The 2D coordinate of the cell we want get.
     * @return A pointer to cell in position (x, y).
     */
    cell_t * Maze::cell( coord_type x, coord_type y )
    {
        if ( outside(x, y) ) return ErrorCell.get();
        return &Cells[(y * Cols) + x];
    }

    /*!
     * @note Nothing is done if the  cell coordinate is located outside the grid.
     * @param p The 2D coordinate of the cell we want to change.
     * @param c The new byte code to represent the cell stat.
     */
    void Maze::cell( coord_type x, coord_type y, const cell_t& c )
    {
        if( outside(x, y) ) return;
       	std::memcpy( cell(x, y), &c, sizeof(cell_t) );
        //std::memcpy( &Cells[(y * Cols) + x], &c, sizeof(cell_t) );
    }

    /*!
     * Get a cell neighbor on grid.
     * @note If the  cell coordinate or its neighbor in the selected direction is located outside the grid the ErrorCell is returned check `cell`.
     * @param p The 2D coordinate of the initial pixel of the line.
     * @param d The direction where the neighbor should be.
     * @return A pointer to neighbor in the direction of the cell in position (x,y).
     */
    cell_t * Maze::neighbor( coord_type x, coord_type y, Direction d )
    {
        if( outside(x,y) ) return ErrorCell.get();
    	switch(d)
        {
        	case Direction::TOP:
        		return cell(x, (y-1)); 

        	case Direction::RIGHT:
                return cell((x+1), y); 

        	case Direction::BOTTOM:
                return cell(x, (y+1)); 

        	case Direction::LEFT:
                return cell((x-1), y);
    	}
        return ErrorCell.get();
    }


    /*!
     * @note Nothing is done if the  cell coordinate is located outside the grid.
     * @param p The 2D coordinate of the cell we want to change.
     * @param c The new byte code to represent the NEIGHBOR stat.
     */
    void Maze::neighbor( coord_type x, coord_type y, Direction d, const cell_t& c )
    {
        if ( outside(x, y) ) return;
        switch(d)
        {
        	case Direction::TOP:
                if ( outside(x, y-1) ) return;
        		*cell(x, (y-1)) = c; 
        	break;

        	case Direction::RIGHT:
                if ( outside(x+1, y) ) return;
        		*cell((x+1), y) = c; 
        	break;

        	case Direction::BOTTOM:
                if ( outside(x, y+1) ) return;
        		*cell(x, (y+1)) = c; 
        	break;

        	case Direction::LEFT:
                if ( outside(x-1, y) ) return;
        		*cell((x-1), y) = c;
        	break;
    	}
    }

    /*!
     * Remove a wall from a cell on grid.
     * @note DO NOT TRY TO REMOVE WALLS 2 TIMES
     * @param p The cell.
     * @param d The direction of the wall to be removed.
     */
    void Maze::removeWall( cell_t * c, Direction d )
    {
        if(d == Direction::TOP)
            *c -= 1;
        if(d == Direction::RIGHT)
            *c -= 2;
        if(d == Direction::BOTTOM)
            *c -= 4;
        if(d == Direction::LEFT)
            *c -= 8;
    }

    /*!
     * Remove a wall from a cell on grid.
     * @note DO NOT TRY TO REMOVE WALLS 2 TIMES
     * @param p The 2D coordinate of the cell.
     * @param d The direction of the wall to be removed.
     */
    void Maze::removeWall( coord_type x, coord_type y, Direction d )
    {
        if(d == Direction::TOP)
            *cell(x, y) -= 1;
        if(d == Direction::RIGHT)
            *cell(x, y) -= 2;
        if(d == Direction::BOTTOM)
            *cell(x, y) -= 4;
        if(d == Direction::LEFT)
            *cell(x, y) -= 8;
    }



	void Maze::removeOpositeWall( coord_type x, coord_type y, Direction d )
    {
    	switch(d)
        {
        	case Direction::TOP: // Remove the bottom wall from the top neighbor
        		removeWall( neighbor(x, y, Direction::TOP), Direction::BOTTOM ); 
        	break;

        	case Direction::RIGHT:
        		removeWall( neighbor(x, y, Direction::RIGHT), Direction::LEFT ); 
        	break;

        	case Direction::BOTTOM:
        		removeWall( neighbor(x, y, Direction::BOTTOM), Direction::TOP ); 
        	break;

        	case Direction::LEFT:
        		removeWall( neighbor(y, x, Direction::LEFT), Direction::RIGHT ); 
        	break;
    	}
    }
