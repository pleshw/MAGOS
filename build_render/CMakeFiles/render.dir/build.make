# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/MAGOS/dev_render

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/MAGOS/build_render

# Include any dependencies generated for this target.
include CMakeFiles/render.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/render.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/render.dir/flags.make

CMakeFiles/render.dir/root/MAGOS/dev_canvas/src/canvas.cpp.o: CMakeFiles/render.dir/flags.make
CMakeFiles/render.dir/root/MAGOS/dev_canvas/src/canvas.cpp.o: /root/MAGOS/dev_canvas/src/canvas.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/MAGOS/build_render/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/render.dir/root/MAGOS/dev_canvas/src/canvas.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/render.dir/root/MAGOS/dev_canvas/src/canvas.cpp.o -c /root/MAGOS/dev_canvas/src/canvas.cpp

CMakeFiles/render.dir/root/MAGOS/dev_canvas/src/canvas.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/render.dir/root/MAGOS/dev_canvas/src/canvas.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/MAGOS/dev_canvas/src/canvas.cpp > CMakeFiles/render.dir/root/MAGOS/dev_canvas/src/canvas.cpp.i

CMakeFiles/render.dir/root/MAGOS/dev_canvas/src/canvas.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/render.dir/root/MAGOS/dev_canvas/src/canvas.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/MAGOS/dev_canvas/src/canvas.cpp -o CMakeFiles/render.dir/root/MAGOS/dev_canvas/src/canvas.cpp.s

CMakeFiles/render.dir/root/MAGOS/dev_canvas/src/canvas.cpp.o.requires:

.PHONY : CMakeFiles/render.dir/root/MAGOS/dev_canvas/src/canvas.cpp.o.requires

CMakeFiles/render.dir/root/MAGOS/dev_canvas/src/canvas.cpp.o.provides: CMakeFiles/render.dir/root/MAGOS/dev_canvas/src/canvas.cpp.o.requires
	$(MAKE) -f CMakeFiles/render.dir/build.make CMakeFiles/render.dir/root/MAGOS/dev_canvas/src/canvas.cpp.o.provides.build
.PHONY : CMakeFiles/render.dir/root/MAGOS/dev_canvas/src/canvas.cpp.o.provides

CMakeFiles/render.dir/root/MAGOS/dev_canvas/src/canvas.cpp.o.provides.build: CMakeFiles/render.dir/root/MAGOS/dev_canvas/src/canvas.cpp.o


CMakeFiles/render.dir/root/MAGOS/dev_maze/src/maze.cpp.o: CMakeFiles/render.dir/flags.make
CMakeFiles/render.dir/root/MAGOS/dev_maze/src/maze.cpp.o: /root/MAGOS/dev_maze/src/maze.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/MAGOS/build_render/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/render.dir/root/MAGOS/dev_maze/src/maze.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/render.dir/root/MAGOS/dev_maze/src/maze.cpp.o -c /root/MAGOS/dev_maze/src/maze.cpp

CMakeFiles/render.dir/root/MAGOS/dev_maze/src/maze.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/render.dir/root/MAGOS/dev_maze/src/maze.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/MAGOS/dev_maze/src/maze.cpp > CMakeFiles/render.dir/root/MAGOS/dev_maze/src/maze.cpp.i

CMakeFiles/render.dir/root/MAGOS/dev_maze/src/maze.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/render.dir/root/MAGOS/dev_maze/src/maze.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/MAGOS/dev_maze/src/maze.cpp -o CMakeFiles/render.dir/root/MAGOS/dev_maze/src/maze.cpp.s

CMakeFiles/render.dir/root/MAGOS/dev_maze/src/maze.cpp.o.requires:

.PHONY : CMakeFiles/render.dir/root/MAGOS/dev_maze/src/maze.cpp.o.requires

CMakeFiles/render.dir/root/MAGOS/dev_maze/src/maze.cpp.o.provides: CMakeFiles/render.dir/root/MAGOS/dev_maze/src/maze.cpp.o.requires
	$(MAKE) -f CMakeFiles/render.dir/build.make CMakeFiles/render.dir/root/MAGOS/dev_maze/src/maze.cpp.o.provides.build
.PHONY : CMakeFiles/render.dir/root/MAGOS/dev_maze/src/maze.cpp.o.provides

CMakeFiles/render.dir/root/MAGOS/dev_maze/src/maze.cpp.o.provides.build: CMakeFiles/render.dir/root/MAGOS/dev_maze/src/maze.cpp.o


CMakeFiles/render.dir/root/MAGOS/libs/configFileReader/configFileReader.cpp.o: CMakeFiles/render.dir/flags.make
CMakeFiles/render.dir/root/MAGOS/libs/configFileReader/configFileReader.cpp.o: /root/MAGOS/libs/configFileReader/configFileReader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/MAGOS/build_render/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/render.dir/root/MAGOS/libs/configFileReader/configFileReader.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/render.dir/root/MAGOS/libs/configFileReader/configFileReader.cpp.o -c /root/MAGOS/libs/configFileReader/configFileReader.cpp

CMakeFiles/render.dir/root/MAGOS/libs/configFileReader/configFileReader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/render.dir/root/MAGOS/libs/configFileReader/configFileReader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/MAGOS/libs/configFileReader/configFileReader.cpp > CMakeFiles/render.dir/root/MAGOS/libs/configFileReader/configFileReader.cpp.i

CMakeFiles/render.dir/root/MAGOS/libs/configFileReader/configFileReader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/render.dir/root/MAGOS/libs/configFileReader/configFileReader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/MAGOS/libs/configFileReader/configFileReader.cpp -o CMakeFiles/render.dir/root/MAGOS/libs/configFileReader/configFileReader.cpp.s

CMakeFiles/render.dir/root/MAGOS/libs/configFileReader/configFileReader.cpp.o.requires:

.PHONY : CMakeFiles/render.dir/root/MAGOS/libs/configFileReader/configFileReader.cpp.o.requires

CMakeFiles/render.dir/root/MAGOS/libs/configFileReader/configFileReader.cpp.o.provides: CMakeFiles/render.dir/root/MAGOS/libs/configFileReader/configFileReader.cpp.o.requires
	$(MAKE) -f CMakeFiles/render.dir/build.make CMakeFiles/render.dir/root/MAGOS/libs/configFileReader/configFileReader.cpp.o.provides.build
.PHONY : CMakeFiles/render.dir/root/MAGOS/libs/configFileReader/configFileReader.cpp.o.provides

CMakeFiles/render.dir/root/MAGOS/libs/configFileReader/configFileReader.cpp.o.provides.build: CMakeFiles/render.dir/root/MAGOS/libs/configFileReader/configFileReader.cpp.o


CMakeFiles/render.dir/src/driver_render.cpp.o: CMakeFiles/render.dir/flags.make
CMakeFiles/render.dir/src/driver_render.cpp.o: /root/MAGOS/dev_render/src/driver_render.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/MAGOS/build_render/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/render.dir/src/driver_render.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/render.dir/src/driver_render.cpp.o -c /root/MAGOS/dev_render/src/driver_render.cpp

CMakeFiles/render.dir/src/driver_render.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/render.dir/src/driver_render.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/MAGOS/dev_render/src/driver_render.cpp > CMakeFiles/render.dir/src/driver_render.cpp.i

CMakeFiles/render.dir/src/driver_render.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/render.dir/src/driver_render.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/MAGOS/dev_render/src/driver_render.cpp -o CMakeFiles/render.dir/src/driver_render.cpp.s

CMakeFiles/render.dir/src/driver_render.cpp.o.requires:

.PHONY : CMakeFiles/render.dir/src/driver_render.cpp.o.requires

CMakeFiles/render.dir/src/driver_render.cpp.o.provides: CMakeFiles/render.dir/src/driver_render.cpp.o.requires
	$(MAKE) -f CMakeFiles/render.dir/build.make CMakeFiles/render.dir/src/driver_render.cpp.o.provides.build
.PHONY : CMakeFiles/render.dir/src/driver_render.cpp.o.provides

CMakeFiles/render.dir/src/driver_render.cpp.o.provides.build: CMakeFiles/render.dir/src/driver_render.cpp.o


CMakeFiles/render.dir/src/render.cpp.o: CMakeFiles/render.dir/flags.make
CMakeFiles/render.dir/src/render.cpp.o: /root/MAGOS/dev_render/src/render.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/MAGOS/build_render/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/render.dir/src/render.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/render.dir/src/render.cpp.o -c /root/MAGOS/dev_render/src/render.cpp

CMakeFiles/render.dir/src/render.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/render.dir/src/render.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/MAGOS/dev_render/src/render.cpp > CMakeFiles/render.dir/src/render.cpp.i

CMakeFiles/render.dir/src/render.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/render.dir/src/render.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/MAGOS/dev_render/src/render.cpp -o CMakeFiles/render.dir/src/render.cpp.s

CMakeFiles/render.dir/src/render.cpp.o.requires:

.PHONY : CMakeFiles/render.dir/src/render.cpp.o.requires

CMakeFiles/render.dir/src/render.cpp.o.provides: CMakeFiles/render.dir/src/render.cpp.o.requires
	$(MAKE) -f CMakeFiles/render.dir/build.make CMakeFiles/render.dir/src/render.cpp.o.provides.build
.PHONY : CMakeFiles/render.dir/src/render.cpp.o.provides

CMakeFiles/render.dir/src/render.cpp.o.provides.build: CMakeFiles/render.dir/src/render.cpp.o


# Object files for target render
render_OBJECTS = \
"CMakeFiles/render.dir/root/MAGOS/dev_canvas/src/canvas.cpp.o" \
"CMakeFiles/render.dir/root/MAGOS/dev_maze/src/maze.cpp.o" \
"CMakeFiles/render.dir/root/MAGOS/libs/configFileReader/configFileReader.cpp.o" \
"CMakeFiles/render.dir/src/driver_render.cpp.o" \
"CMakeFiles/render.dir/src/render.cpp.o"

# External object files for target render
render_EXTERNAL_OBJECTS =

render: CMakeFiles/render.dir/root/MAGOS/dev_canvas/src/canvas.cpp.o
render: CMakeFiles/render.dir/root/MAGOS/dev_maze/src/maze.cpp.o
render: CMakeFiles/render.dir/root/MAGOS/libs/configFileReader/configFileReader.cpp.o
render: CMakeFiles/render.dir/src/driver_render.cpp.o
render: CMakeFiles/render.dir/src/render.cpp.o
render: CMakeFiles/render.dir/build.make
render: CMakeFiles/render.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/MAGOS/build_render/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable render"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/render.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/render.dir/build: render

.PHONY : CMakeFiles/render.dir/build

CMakeFiles/render.dir/requires: CMakeFiles/render.dir/root/MAGOS/dev_canvas/src/canvas.cpp.o.requires
CMakeFiles/render.dir/requires: CMakeFiles/render.dir/root/MAGOS/dev_maze/src/maze.cpp.o.requires
CMakeFiles/render.dir/requires: CMakeFiles/render.dir/root/MAGOS/libs/configFileReader/configFileReader.cpp.o.requires
CMakeFiles/render.dir/requires: CMakeFiles/render.dir/src/driver_render.cpp.o.requires
CMakeFiles/render.dir/requires: CMakeFiles/render.dir/src/render.cpp.o.requires

.PHONY : CMakeFiles/render.dir/requires

CMakeFiles/render.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/render.dir/cmake_clean.cmake
.PHONY : CMakeFiles/render.dir/clean

CMakeFiles/render.dir/depend:
	cd /root/MAGOS/build_render && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/MAGOS/dev_render /root/MAGOS/dev_render /root/MAGOS/build_render /root/MAGOS/build_render /root/MAGOS/build_render/CMakeFiles/render.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/render.dir/depend
