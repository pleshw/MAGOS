
# **MAGOS PROJECT**

***EVERY CONFIGURATION SHOULD BE AT  `setup.txt` .***

***THE ORDER OF ANY CONFIGURATION DOESN'T MATTER BUT ALL OF THEM NEED TO BE SETTED IN THIS VERSION.***

***ON SETUP FILE EACH CONFIG NEEDS TO BE FOLLOWED BY ':' AND THE FIRST VALUE NEXT TO IT IS THE VALUE OF THAT CONFIGURATION.***

**INVALID CONFIGURATION RESULT IN SEGMENTATION FAULT OR INFINITE TRIALS OF SETTING UP VARIABLES.**
> **Note:** Invalid configurations is any config that makes drawing impossible. Ex: canvasWidth: -1.



**MAKE: `../MAGOS/build_magos` and `make`.**



## DEFAULT CONFIGS
> *Remember - When change the number of rows and cols in a maze change the start and ending flag indexes. Invalid margins will result in fail.*

* Canvas setup
	* **canvasWidth**: Width of the canvas and each image in pixels
	* **canvasHeight**: Height of the canvas and each image in pixels
	* **canvasPaddingTop**: Margin ( top and bottom ) between canvas and its elements
	* **canvasPaddingLeft**: Margin ( left and right ) between canvas and its elements

* Maze design setup
	* **mazeRows**: Total of maze rows.
	* **mazeCols**: Total of maze cols.
	* **startFlagIndex**: Start position index of maze.
	* **endFlagIndex**: End position index of maze.

* Outputs
	* **outputBuilding**: Output file for building.
	* **outputSolver**: Output file for solving.

* Maze design
	* **startFlagMargin**: Margin from start cell to the painted box that represents it.
	* **endFlagMargin**: Margin from end cell to the painted box that represents it.
	* **checkingFlagMargin**: Margin from the actual `on checking` cell to the painted box that represents it.
	* **visitedFlagMargin**: Margin from visited cells to the painted box that represents it.
	* **discardedFlagMargin**: Margin from discarded cells to the painted box that represents it.
	* **wallThickness**: Thickness of the line that make maze walls.