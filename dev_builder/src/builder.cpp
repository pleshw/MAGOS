#include "../include/builder.h"

bool Builder::brickBreak ( size_t index, Direction d )
{
	size_t x = index % maze.cols();
	size_t y = index / maze.cols();

	if ( !canBreak ( x, y, d ) ) return false;

	cell_path_iterator L1 = findIteratorOf ( maze.cell( index ) );
	cell_path_iterator L2 = findIteratorOf ( maze.neighbor( index, d ) );

	//get the iterator of cell set
	if ( maze.getCellIndex( x, y ) > (maze.cols() * maze.rows()) ) return false;
	//get the iterator of neighbor set
	if ( maze.getNeighborIndex( x, y, d ) > (maze.cols() * maze.rows()) ) return false;

	if ( L1 == L2 ) return false; // if they make part of the same set

	if( !maze.removeWall( x, y, d ) ) // Remove the selected wall of a cell
		return false;
	if( !maze.removeOpositeWall( x, y, d ) ) // Remove its oposite wall ( from its neighbor )
		return false;

	L1->second.insert( L2->second.begin(), L2->second.end() ); //insert c2 set into c1
	Path.erase( L2 ); // deletes c2 set
	return true;
}

bool Builder::brickBreak ( size_t x, size_t y, Direction d )
{
	if ( !canBreak ( x, y, d ) ) return false;

	cell_path_iterator L1 = findIteratorOf ( maze.cell( x, y ) );
	cell_path_iterator L2 = findIteratorOf ( maze.neighbor( x, y, d ) );

	if ( maze.getCellIndex( x, y ) > (maze.cols() * maze.rows()) ) return false;
	if ( maze.getNeighborIndex( x, y, d ) > (maze.cols() * maze.rows()) ) return false;

	if ( L1 == L2 ) return false;

	if( !maze.removeWall( x, y, d ) ) // Remove the selected wall of a cell
		return false;
	if( !maze.removeOpositeWall( x, y, d ) ) // Remove its oposite wall ( from its neighbor )
		return false;

	L1->second.insert( L2->second.begin(), L2->second.end() ); //insert c2 set into c1
	Path.erase( L2 ); // deletes c2 set

	return true;
}

Direction Builder::getRandomDirection ( void )
{
	switch (rand() % 4)
	{
		case 0:
			return Direction::TOP;
		case 1:
			return Direction::RIGHT;
		case 2:
			return Direction::BOTTOM;
		case 3:
			return Direction::LEFT;
		default: 
			return Direction::LEFT;
	}
}

cell_path_iterator Builder::findIteratorOf ( size_t index )
{
	for ( cell_path_iterator it = Path.begin(); it != Path.end(); it++)
	{
		if ( it->first == index ) // when find set that contains c1 
		{	
			return it;
		}
	}
	return Path.end();
}

cell_path_iterator Builder::findIteratorOf ( cell_t* c )
{
	for ( cell_path_iterator it = Path.begin(); it != Path.end(); it++)
	{
		if ( *it->second.find(c) == c ) // when find set that contains c1 
		{	
			return it;
		}
	}
	return Path.end();
}

size_t Builder::findSingleCell ( void )
{
	for ( cell_path_iterator it = Path.begin(); it != Path.end(); ++it)
	{
		if ( it->second.size() == 1 ) // when find set that contain only one cell.
		{	
			return it->first;
		}
	}
	return 9999;
}

size_t Builder::getSingleCells ( void )
{
	size_t counter = 0;
	for ( cell_path_iterator it = Path.begin(); it != Path.end(); ++it)
	{
		if ( it->second.size() == 1 ) // when find set that contain only one cell.
		{	
			counter++;
		}
	}
	return counter;
}

bool Builder::canBreak ( size_t x, size_t y, Direction d )
{
	size_t index = (y*maze.cols()) + x;
	if ( index > (maze.cols() * maze.rows()) ) return false;
	if ( x == 0 && d == Direction::LEFT ) return false;
	if ( x == (maze.cols()-1) && d == Direction::RIGHT ) return false;
	if ( y == 0 && d == Direction::TOP ) return false;
	if ( y == (maze.rows()-1) && d == Direction::BOTTOM ) return false;
	return true;
}