
# **MAGOS PROJECT**

# **About**
MAGOS Provide functions, user interface and tools for visualizing the process of generation and solving of a perfect maze, created with a set of given configurations. This project work with lots of important concepts in programming such as data structures( stacks,sets lists... ), object-oriented programming, file reading, API handling, code documentation and project modules.

# ** Important**

**Every configuration should be at:  `setup.txt` .**

**The individual config order doesn't matter since my ConfigFileReader can handle it but all the setup needs to be setted.**

**On setup file each config have to be followed by the symbol ':', the very first value after that symbol is setted as the value for that configuration.**

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
