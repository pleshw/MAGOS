#include <iostream>

#include "../include/maze.h"

using namespace canvas;

int main( void )
{
    //testing initialization
    Maze maze1 { 5, 5 };
    Maze maze2 { maze1 };
    Maze maze3;
    maze3 = maze2;

    //testing outside
    if (maze1.outside(-2, -3)) std::cout << std::endl << "OUT OF RANGE" << std::endl;
    //testing get cell
    cell_t celula = *maze1.cell(1, 3);
    std::cout << celula;
    //testing change cell
    maze1.cell(1, 3, 120);
    if ( celula != *maze1.cell(1, 3) ) std::cout << std::endl << "CELL CHANGED" << std::endl;
    
    return 0;
}
