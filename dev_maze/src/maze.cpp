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
    std::memset( Cells.get(), 255, ( Cols * Rows ));
}

/*!
 * @throw `std::invalid_argument()` if the coordinate is located outside the grid.
 * @param p The 2D coordinate.
 * @return True if the cordinate is outside the grid, otherwise False.
 */
bool Maze::outside( size_t x, size_t y )
    { return ( (x >= Cols) ||  (y >= Rows) ); }
bool Maze::outside( size_t index )
    { return ( index >= ( Rows * Cols ) ); }

bool Maze::outside( size_t x, size_t y, Direction d )
{
    switch ( d )
    {
        case Direction::TOP: return outside( x, y-1 );
        case Direction::RIGHT: return outside( x+1, y );
        case Direction::BOTTOM: return outside( x, y+1 );
        case Direction::LEFT: return outside( x-1, y );
        default: return false;
    }
}
bool Maze::outside( size_t index, Direction d )
{
    switch ( d )
    {
        case Direction::TOP: 
            return outside( index - Cols );
        break;
        case Direction::RIGHT: 
            return outside( index + 1 );
        break;
        case Direction::BOTTOM: 
            return outside( index + Cols );
        break;
        case Direction::LEFT: 
            return outside( index - 1 );
        break;
        default: 
            return false;
        break;
    }
}


/*!
 * Call `outside` to check if the cell coordinate is located outside the grid.
 * @note If the  cell index is located outside the grid the ErrorCell is returned.
 * If outside the function will return the first cell of the grid.
 * @param p The index of the cell we want get in relation to grid.
 * @return A pointer to cell in position grid[y*cols + x].
 */
cell_t * Maze::cell( size_t index )
{
    if ( outside(index) ) return cellOutOfRange();
    return &Cells[index];
}

/*!
 * Call `outside` to check if the cell coordinate is located outside the grid.
 * @note If the  cell coordinate is located outside the grid the ErrorCell is returned.
 * If outside the function will return the first cell of the grid.
 * @param p The 2D coordinate of the cell we want get.
 * @return A pointer to cell in position (x, y).
 */
cell_t * Maze::cell( size_t x, size_t y )
{
    if ( outside(x, y) ) return cellOutOfRange();
    return &Cells[(y * Cols) + x];
}

/*!
 * @note Nothing is done if the  cell coordinate is located outside the grid.
 * @param p The 2D coordinate of the cell we want to change.
 * @param c The new byte code to represent the cell stat.
 */
void Maze::cell( size_t x, size_t y, const cell_t& c )
{
    if( outside(x, y) ) return;
   	std::memcpy( cell(x, y), &c, sizeof(cell_t) );
    //std::memcpy( &Cells[(y * Cols) + x], &c, sizeof(cell_t) );
}

/*!
 * Get a cell neighbor on grid.
 * @note If the  cell coordinate or its neighbor in the selected direction is located outside the grid the ErrorCell is returned check `cell`.
 * @param index The index of a cell on grid.
 * @param d The direction where the neighbor should be.
 * @return A pointer to neighbor in the direction of the cell in position (x,y).
 */
cell_t * Maze::neighbor( size_t index, Direction d )
{
    if (outside( index, d )) return cellOutOfRange();
    
    switch(d)
    {
        case Direction::TOP:
            return cell( index - Cols ); 

        case Direction::RIGHT:
            return cell( index + 1 ); 

        case Direction::BOTTOM:
            return cell( index + Cols ); 

        case Direction::LEFT:
            return cell( index - 1 );
        break;
    }
    return cellOutOfRange();
}

/*!
 * Get a cell neighbor on grid.
 * @note If the  cell coordinate or its neighbor in the selected direction is located outside the grid the ErrorCell is returned check `cell`.
 * @param index The index of a cell on grid.
 * @param d The direction where the neighbor should be.
 * @return A pointer to neighbor in the direction of the cell in position (x,y).
 */
cell_t * Maze::neighbor( size_t x, size_t y, Direction d )
{
    if (outside( x, y, d )) return cellOutOfRange();

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
        break;
	}
    return cellOutOfRange();
}

/*!
 * Get a cell neighbor on grid.
 * @note If the  cell coordinate or its neighbor in the selected direction is located outside the grid the ErrorCell is returned check `cell`.
 * @param index The index of a cell on grid.
 * @param d The direction where the neighbor should be.
 * @return A pointer to neighbor in the direction of the cell in position (x,y).
 */
cell_t * Maze::neighbor( cell_t * c, Direction d )
{
    switch(d)
    {
        case Direction::TOP:
            return c - Cols; 

        case Direction::RIGHT:
            return c + 1; 

        case Direction::BOTTOM:
            return c + Cols; 

        case Direction::LEFT:
            return c - 1;
        break;
    }
    return cellOutOfRange();
}

/*!
 * @note Nothing is done if the  cell coordinate is located outside the grid.
 * @param p The 2D coordinate of the cell we want to change.
 * @param c The new byte code to represent the NEIGHBOR stat.
 */
void Maze::neighbor( size_t x, size_t y, Direction d, const cell_t& c )
{
    switch(d)
    {
    	case Direction::TOP:
    		*cell(x, (y-1)) = c; 
    	break;

    	case Direction::RIGHT:
    		*cell((x+1), y) = c; 
    	break;

    	case Direction::BOTTOM:
    		*cell(x, (y+1)) = c; 
    	break;

    	// case Direction::LEFT:
        default:
    		*cell((x-1), y) = c;
    	break;
	}
}

size_t Maze::getNeighborIndex ( size_t index, Direction d )
{ 
    size_t x = index % Cols;
    size_t y = index / Cols;
    switch(d)
    {
        case Direction::TOP:
            return getCellIndex(x, (y-1));  
        break;

        case Direction::RIGHT:
            return getCellIndex((x+1), y);
        break;

        case Direction::BOTTOM:
            return getCellIndex(x, (y+1)); 
        break;

        // case Direction::LEFT:
        default:
            return getCellIndex((x-1), y);
        break;
    }  
}

size_t Maze::getNeighborIndex ( size_t x, size_t y, Direction d ) // using 2d
{ 
    switch(d)
    {
        case Direction::TOP:
            return getCellIndex(x, (y-1));  
        break;

        case Direction::RIGHT:
            return getCellIndex((x+1), y);
        break;

        case Direction::BOTTOM:
            return getCellIndex(x, (y+1)); 
        break;

        // case Direction::LEFT:
        default:
            return getCellIndex((x-1), y);
        break;
    }  
}


/*!
 * Remove a wall from a cell on grid.
 * @note IF TRY TO REMOVE WALLS 2 TIMES NOTHING HAPPEN
 * @param c The cell.
 * @param d The direction of the wall to be removed.
 */
bool Maze::removeWall( cell_t * c, Direction d )
{
    if( d == Direction::TOP && hasTopWall( c ) ) // If bit 1 is active
    { 
        *c -= 1;
        return true;
    }
    if(d == Direction::RIGHT  && hasRightWall( c ) )
    { 
        *c -= 2;
        return true;
    }
    if(d == Direction::BOTTOM  && hasBottomWall( c ) )
    { 
        *c -= 4;
        return true;
    }
    if(d == Direction::LEFT  && hasLeftWall( c ) )
    { 
        *c -= 8;
        return true;
    }
    return false;
}

/*!
 * Remove a wall from a cell on grid.
 * @note IF TRY TO REMOVE WALLS 2 TIMES NOTHING HAPPEN
 * @param c The index of the cell.
 * @param d The direction of the wall to be removed.
 */
bool Maze::removeWall( size_t index, Direction d )
{   
    if(d == Direction::TOP && hasTopWall( index ) )
    {
        *cell(index) -= 1;
        return true;
    }
    if(d == Direction::RIGHT && hasRightWall( index ) )
    {
        *cell(index) -= 2;
        return true;
    }
    if(d == Direction::BOTTOM && hasBottomWall( index ) )
    {
        *cell(index) -= 4;
        return true;
    }
    if(d == Direction::LEFT && hasLeftWall( index ) )
    {
        *cell(index) -= 8;
        return true;
    }
    return false;
}

/*!
 * Remove a wall from a cell on grid.
 * @note IF TRY TO REMOVE WALLS 2 TIMES NOTHING HAPPEN
 * @param p The 2D coordinate of the cell.
 * @param d The direction of the wall to be removed.
 */
bool Maze::removeWall( size_t x, size_t y, Direction d )
{   
    if(d == Direction::TOP && hasTopWall( x, y ) )
    {
        *cell(x, y) -= 1;
        return true;
    }
    if(d == Direction::RIGHT && hasRightWall( x, y ) )
    {
        *cell(x, y) -= 2;
        return true;
    }
    if(d == Direction::BOTTOM && hasBottomWall( x, y ) )
    {
        *cell(x, y) -= 4;
        return true;
    }
    if(d == Direction::LEFT && hasLeftWall( x, y ) )
    {
        *cell(x, y) -= 8;
        return true;
    }
    return false;
}



bool Maze::removeOpositeWall( size_t index, Direction d )
{
    if ( outside( index, d ) ) return false; // If doesn't exist cell at selected direction
  
    switch( d )
    {
        case Direction::TOP: // Remove the bottom wall from the top neighbor
            if( removeWall( neighbor( index, Direction::TOP ) , Direction::BOTTOM ) )
                return true;
        break;

        case Direction::RIGHT:
            if( removeWall( neighbor( index, Direction::RIGHT ), Direction::LEFT ) )
                return true;
        break;

        case Direction::BOTTOM:
            if( removeWall( neighbor( index, Direction::BOTTOM ), Direction::TOP ) )
                return true;
        break;

        case Direction::LEFT:
            if( removeWall( neighbor( index, Direction::LEFT ), Direction::RIGHT ) )
                return true;
        break;
    }
    return false;
}

bool Maze::removeOpositeWall( cell_t * c, Direction d )
{
    switch(d)
    {
        case Direction::TOP: // Remove the bottom wall from the top neighbor
            if( removeWall( neighbor(c, Direction::TOP), Direction::BOTTOM ) )
                return true;
        break;

        case Direction::RIGHT:
            if( removeWall( neighbor(c, Direction::RIGHT), Direction::LEFT ) )
                return true;
        break;

        case Direction::BOTTOM:
            if( removeWall( neighbor(c, Direction::BOTTOM), Direction::TOP ) )
                return true;
        break;

        case Direction::LEFT:
            if( removeWall( neighbor(c, Direction::LEFT), Direction::RIGHT ) )
                return true;
        break;
    }
    return false;
}

bool Maze::removeOpositeWall( size_t x, size_t y, Direction d )
{
    if ( outside( x, y, d ) ) return false; // If doesn't exist cell at selected direction
	
    switch(d)
    {
    	case Direction::TOP: // Remove the bottom wall from the top neighbor
    		if( removeWall( neighbor(x, y, Direction::TOP), Direction::BOTTOM ) )
                return true;
    	break;

    	case Direction::RIGHT:
    		if( removeWall( neighbor(x, y, Direction::RIGHT), Direction::LEFT ) )
                return true;
    	break;

    	case Direction::BOTTOM:
    		if( removeWall( neighbor(x, y, Direction::BOTTOM), Direction::TOP ) )
                return true;
    	break;

    	case Direction::LEFT:
    		if( removeWall( neighbor(x, y, Direction::LEFT), Direction::RIGHT ) )
                return true;
    	break;
	}
    return false;
}

/*!
 * Verify if top wall bit of a cell is on.
 */
bool Maze::hasTopWall ( cell_t *c )
    { return ( ( *c & Direction::TOP ) == Direction::TOP ); }

bool Maze::hasTopWall ( size_t index )
    { return ( ( *cell( index ) & Direction::TOP ) == Direction::TOP ); }

bool Maze::hasTopWall ( size_t x, size_t y )
    { return ( ( *cell( x, y ) & Direction::TOP ) == Direction::TOP ); }

/*!
 * Verify if right wall bit of a cell is on.
 */
bool Maze::hasRightWall ( cell_t *c )
    { return ( ( *c & Direction::RIGHT  ) == Direction::RIGHT ); }

bool Maze::hasRightWall ( size_t index )
    { return ( ( *cell( index ) & Direction::RIGHT ) == Direction::RIGHT ); }

bool Maze::hasRightWall ( size_t x, size_t y )
    { return ( ( *cell( x, y ) & Direction::RIGHT ) == Direction::RIGHT ); }


/*!
 * Verify if bottom wall bit of a cell is on.
 */
bool Maze::hasBottomWall ( cell_t *c )
    { return ( ( *c & Direction::BOTTOM  ) == Direction::BOTTOM ); }

bool Maze::hasBottomWall ( size_t index )
    { return ( ( *cell( index ) & Direction::BOTTOM ) == Direction::BOTTOM ); }

bool Maze::hasBottomWall ( size_t x, size_t y )
    { return ( ( *cell( x, y ) & Direction::BOTTOM ) == Direction::BOTTOM ); }


/*!
 * Verify if left wall bit of a cell is on.
 */
bool Maze::hasLeftWall ( cell_t *c )
    { return ( ( *c & Direction::LEFT  ) == Direction::LEFT ); }

bool Maze::hasLeftWall ( size_t index )
    { return ( ( *cell( index ) & Direction::LEFT ) == Direction::LEFT ); }

bool Maze::hasLeftWall ( size_t x, size_t y )
    { return ( ( *cell( x, y ) & Direction::LEFT ) == Direction::LEFT ); }

/*!
 * Verify if NOT_TESTED bit of a cell is on.
 */
bool Maze::wasNotTested ( cell_t *c )
    { return ( ( *c & CellBitmap::NOT_TESTED  ) == CellBitmap::NOT_TESTED ); }

bool Maze::wasNotTested ( size_t index )
    { return ( ( *cell( index ) & CellBitmap::NOT_TESTED ) == CellBitmap::NOT_TESTED ); }

bool Maze::wasNotTested ( size_t x, size_t y )
    { return ( ( *cell( x, y ) & CellBitmap::NOT_TESTED ) == CellBitmap::NOT_TESTED ); }

/*!
 * Verify if CHECKING bit of a cell is on.
 */
bool Maze::isChecking ( cell_t *c )
    { return ( ( *c & CellBitmap::CHECKING  ) == CellBitmap::CHECKING ); }

bool Maze::isChecking ( size_t index )
    { return ( ( *cell( index ) & CellBitmap::CHECKING ) == CellBitmap::CHECKING ); }

bool Maze::isChecking ( size_t x, size_t y )
    { return ( ( *cell( x, y ) & CellBitmap::CHECKING ) == CellBitmap::CHECKING ); }

/*!
 * Verify if VISITED bit of a cell is on.
 */
bool Maze::wasVisited ( cell_t *c )
    { return ( ( *c & CellBitmap::VISITED  ) == CellBitmap::VISITED ); }

bool Maze::wasVisited ( size_t index )
    { return ( ( *cell( index ) & CellBitmap::VISITED ) == CellBitmap::VISITED ); }

bool Maze::wasVisited ( size_t x, size_t y )
    { return ( ( *cell( x, y ) & CellBitmap::VISITED ) == CellBitmap::VISITED ); }

/*!
 * Verify if DISCARDED bit of a cell is on.
 */
bool Maze::wasDiscarded ( cell_t *c )
    { return ( ( *c & CellBitmap::DISCARDED  ) == CellBitmap::DISCARDED ); }

bool Maze::wasDiscarded ( size_t index )
    { return ( ( *cell( index ) & CellBitmap::DISCARDED ) == CellBitmap::DISCARDED ); }

bool Maze::wasDiscarded ( size_t x, size_t y )
    { return ( ( *cell( x, y ) & CellBitmap::DISCARDED ) == CellBitmap::DISCARDED ); }

void Maze::checkCell ( cell_t* c )
{
    *c += CellBitmap::CHECKING;
    if ( wasDiscarded( c ) )
        *c -= CellBitmap::DISCARDED;
    if ( wasNotTested( c ) )
        *c -= CellBitmap::NOT_TESTED;
    if ( wasVisited( c ) )
        *c -= CellBitmap::VISITED;
}

void Maze::checkCell ( size_t index )
{
    *cell( index ) += CellBitmap::CHECKING;
    if ( wasDiscarded( index ) )
        *cell( index ) -= CellBitmap::DISCARDED;
    if ( wasNotTested( index ) )
        *cell( index ) -= CellBitmap::NOT_TESTED;
    if ( wasVisited( index ) )
        *cell( index ) -= CellBitmap::VISITED;
}

void Maze::checkCell ( size_t x, size_t y )
{
    *cell( x, y ) += CellBitmap::CHECKING;
    if ( wasDiscarded( x, y ) )
        *cell( x, y ) -= CellBitmap::DISCARDED;
    if ( wasNotTested( x, y ) )
        *cell( x, y ) -= CellBitmap::NOT_TESTED;
    if ( wasVisited( x, y ) )
        *cell( x, y ) -= CellBitmap::VISITED;
}

void Maze::visitCell ( cell_t* c )
{
    *c += CellBitmap::VISITED;
    if ( wasDiscarded( c ) )
        *c -= CellBitmap::DISCARDED;
    if ( wasNotTested( c ) )
        *c -= CellBitmap::NOT_TESTED;
    if ( isChecking( c ) )
        *c -= CellBitmap::CHECKING;
}

void Maze::visitCell ( size_t index )
{
    *cell( index ) += CellBitmap::VISITED;
    if ( wasDiscarded( index ) )
        *cell( index ) -= CellBitmap::DISCARDED;
    if ( wasNotTested( index ) )
        *cell( index ) -= CellBitmap::NOT_TESTED;
    if ( isChecking( index ) )
        *cell( index ) -= CellBitmap::CHECKING;
}

void Maze::visitCell ( size_t x, size_t y )
{
    *cell( x, y ) += CellBitmap::VISITED;
    if ( wasDiscarded( x, y ) )
        *cell( x, y ) -= CellBitmap::DISCARDED;
    if ( wasNotTested( x, y ) )
        *cell( x, y ) -= CellBitmap::NOT_TESTED;
    if ( isChecking( x, y ) )
        *cell( x, y ) -= CellBitmap::CHECKING;
}

void Maze::discardCell ( cell_t* c )
{
    *c += CellBitmap::DISCARDED;
    if ( wasVisited( c ) )
        *c -= CellBitmap::VISITED;
    if ( wasNotTested( c ) )
        *c -= CellBitmap::NOT_TESTED;
    if ( isChecking( c ) )
        *c -= CellBitmap::CHECKING;
}

void Maze::discardCell ( size_t index )
{
    *cell( index ) += CellBitmap::DISCARDED;
    if ( wasVisited( index ) )
        *cell( index ) -= CellBitmap::VISITED;
    if ( wasNotTested( index ) )
        *cell( index ) -= CellBitmap::NOT_TESTED;
    if ( isChecking( index ) )
        *cell( index ) -= CellBitmap::CHECKING;
}

void Maze::discardCell ( size_t x, size_t y )
{
    *cell( x, y ) += CellBitmap::DISCARDED;
    if ( wasVisited( x, y ) )
        *cell( x, y ) -= CellBitmap::VISITED;
    if ( wasNotTested( x, y ) )
        *cell( x, y ) -= CellBitmap::NOT_TESTED;
    if ( isChecking( x, y ) )
        *cell( x, y ) -= CellBitmap::CHECKING;
}