#include "../include/solver.h"

void Solver::nextMove ( void )
{
	if ( !canMove() ) //if cannot move then backtrack
	{
		backtrack();
		return;
	} 
	previousMoves.push( actualIndex ); // stack last move on previous moves
	if ( canMoveTop() )
	{
		moveTop(); 		
		return;
	}
	if ( canMoveRight() )
	{
		moveRight();	
		return;
	}
	if ( canMoveBottom() )
	{
		moveBottom();	
		return;
	}
	if ( canMoveLeft() )
	{
		moveLeft();	
		return;
	}	
}

void Solver::backtrack ( void )
{
	maze.discardCell( actualIndex );
	actualIndex = previousMoves.top();
	maze.checkCell( actualIndex );
	previousMoves.pop();
}

bool Solver::canMove ( void )
{
	return canMoveTop() or canMoveRight() or canMoveBottom() or canMoveLeft();
}

bool Solver::canMoveTop ( void )
{
	if ( maze.outside( actualIndex, Direction::TOP ) ) return false;
	if ( maze.hasBottomWall( maze.neighbor( actualIndex, Direction::TOP ) ) ) return false;
	if ( maze.wasNotTested( maze.neighbor( actualIndex, Direction::TOP ) ) ) return true;
	return false;
}

void Solver::moveTop ( void )
{
	actualIndex = maze.getNeighborIndex( previousMoves.top(), Direction::TOP ); // actual index gets next move index
	maze.visitCell( previousMoves.top() ); // mark last checked as visited.
	maze.checkCell( actualIndex ); // check actual index cell.
}

bool Solver::canMoveRight ( void )
{
	if ( maze.outside( actualIndex, Direction::RIGHT ) ) return false;
	if ( maze.hasLeftWall( maze.neighbor( actualIndex, Direction::RIGHT ) ) ) return false;
	if ( maze.wasNotTested( maze.neighbor( actualIndex, Direction::RIGHT ) ) ) return true;
	return false;
}

void Solver::moveRight ( void )
{
	actualIndex = maze.getNeighborIndex( previousMoves.top(), Direction::RIGHT ); // actual index gets next move index
	maze.visitCell( previousMoves.top() ); // mark last checked as visited.
	maze.checkCell( actualIndex ); // check actual index cell.
}

bool Solver::canMoveBottom ( void )
{
	if ( maze.outside( actualIndex, Direction::BOTTOM ) ) return false;
	if ( maze.hasTopWall( maze.neighbor( actualIndex, Direction::BOTTOM ) ) ) return false;
	if ( maze.wasNotTested( maze.neighbor( actualIndex, Direction::BOTTOM ) ) ) return true;
	return false;
}

void Solver::moveBottom ( void )
{
	actualIndex = maze.getNeighborIndex( previousMoves.top(), Direction::BOTTOM ); // actual index gets next move index
	maze.visitCell( previousMoves.top() ); // mark last checked as visited.
	maze.checkCell( actualIndex ); // check actual index cell.
}

bool Solver::canMoveLeft ( void )
{
	if ( maze.outside( actualIndex, Direction::LEFT ) ) return false;
	if ( maze.hasRightWall( maze.neighbor( actualIndex, Direction::LEFT ) ) ) return false;
	if ( maze.wasNotTested( maze.neighbor( actualIndex, Direction::LEFT ) ) ) return true;
	return false;
}

void Solver::moveLeft ( void )
{
	actualIndex = maze.getNeighborIndex( previousMoves.top(), Direction::LEFT ); // actual index gets next move index
	maze.visitCell( previousMoves.top() ); // mark last checked as visited.
	maze.checkCell( actualIndex ); // check actual index cell.
}