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
CMAKE_SOURCE_DIR = /root/MAGOS/dev_magos

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/MAGOS/build_magos

# Include any dependencies generated for this target.
include CMakeFiles/MAGOS.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MAGOS.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MAGOS.dir/flags.make

CMakeFiles/MAGOS.dir/root/MAGOS/dev_canvas/src/canvas.cpp.o: CMakeFiles/MAGOS.dir/flags.make
CMakeFiles/MAGOS.dir/root/MAGOS/dev_canvas/src/canvas.cpp.o: /root/MAGOS/dev_canvas/src/canvas.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/MAGOS/build_magos/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MAGOS.dir/root/MAGOS/dev_canvas/src/canvas.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MAGOS.dir/root/MAGOS/dev_canvas/src/canvas.cpp.o -c /root/MAGOS/dev_canvas/src/canvas.cpp

CMakeFiles/MAGOS.dir/root/MAGOS/dev_canvas/src/canvas.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MAGOS.dir/root/MAGOS/dev_canvas/src/canvas.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/MAGOS/dev_canvas/src/canvas.cpp > CMakeFiles/MAGOS.dir/root/MAGOS/dev_canvas/src/canvas.cpp.i

CMakeFiles/MAGOS.dir/root/MAGOS/dev_canvas/src/canvas.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MAGOS.dir/root/MAGOS/dev_canvas/src/canvas.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/MAGOS/dev_canvas/src/canvas.cpp -o CMakeFiles/MAGOS.dir/root/MAGOS/dev_canvas/src/canvas.cpp.s

CMakeFiles/MAGOS.dir/root/MAGOS/dev_canvas/src/canvas.cpp.o.requires:

.PHONY : CMakeFiles/MAGOS.dir/root/MAGOS/dev_canvas/src/canvas.cpp.o.requires

CMakeFiles/MAGOS.dir/root/MAGOS/dev_canvas/src/canvas.cpp.o.provides: CMakeFiles/MAGOS.dir/root/MAGOS/dev_canvas/src/canvas.cpp.o.requires
	$(MAKE) -f CMakeFiles/MAGOS.dir/build.make CMakeFiles/MAGOS.dir/root/MAGOS/dev_canvas/src/canvas.cpp.o.provides.build
.PHONY : CMakeFiles/MAGOS.dir/root/MAGOS/dev_canvas/src/canvas.cpp.o.provides

CMakeFiles/MAGOS.dir/root/MAGOS/dev_canvas/src/canvas.cpp.o.provides.build: CMakeFiles/MAGOS.dir/root/MAGOS/dev_canvas/src/canvas.cpp.o


CMakeFiles/MAGOS.dir/root/MAGOS/dev_maze/src/maze.cpp.o: CMakeFiles/MAGOS.dir/flags.make
CMakeFiles/MAGOS.dir/root/MAGOS/dev_maze/src/maze.cpp.o: /root/MAGOS/dev_maze/src/maze.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/MAGOS/build_magos/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/MAGOS.dir/root/MAGOS/dev_maze/src/maze.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MAGOS.dir/root/MAGOS/dev_maze/src/maze.cpp.o -c /root/MAGOS/dev_maze/src/maze.cpp

CMakeFiles/MAGOS.dir/root/MAGOS/dev_maze/src/maze.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MAGOS.dir/root/MAGOS/dev_maze/src/maze.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/MAGOS/dev_maze/src/maze.cpp > CMakeFiles/MAGOS.dir/root/MAGOS/dev_maze/src/maze.cpp.i

CMakeFiles/MAGOS.dir/root/MAGOS/dev_maze/src/maze.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MAGOS.dir/root/MAGOS/dev_maze/src/maze.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/MAGOS/dev_maze/src/maze.cpp -o CMakeFiles/MAGOS.dir/root/MAGOS/dev_maze/src/maze.cpp.s

CMakeFiles/MAGOS.dir/root/MAGOS/dev_maze/src/maze.cpp.o.requires:

.PHONY : CMakeFiles/MAGOS.dir/root/MAGOS/dev_maze/src/maze.cpp.o.requires

CMakeFiles/MAGOS.dir/root/MAGOS/dev_maze/src/maze.cpp.o.provides: CMakeFiles/MAGOS.dir/root/MAGOS/dev_maze/src/maze.cpp.o.requires
	$(MAKE) -f CMakeFiles/MAGOS.dir/build.make CMakeFiles/MAGOS.dir/root/MAGOS/dev_maze/src/maze.cpp.o.provides.build
.PHONY : CMakeFiles/MAGOS.dir/root/MAGOS/dev_maze/src/maze.cpp.o.provides

CMakeFiles/MAGOS.dir/root/MAGOS/dev_maze/src/maze.cpp.o.provides.build: CMakeFiles/MAGOS.dir/root/MAGOS/dev_maze/src/maze.cpp.o


CMakeFiles/MAGOS.dir/root/MAGOS/dev_render/src/render.cpp.o: CMakeFiles/MAGOS.dir/flags.make
CMakeFiles/MAGOS.dir/root/MAGOS/dev_render/src/render.cpp.o: /root/MAGOS/dev_render/src/render.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/MAGOS/build_magos/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/MAGOS.dir/root/MAGOS/dev_render/src/render.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MAGOS.dir/root/MAGOS/dev_render/src/render.cpp.o -c /root/MAGOS/dev_render/src/render.cpp

CMakeFiles/MAGOS.dir/root/MAGOS/dev_render/src/render.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MAGOS.dir/root/MAGOS/dev_render/src/render.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/MAGOS/dev_render/src/render.cpp > CMakeFiles/MAGOS.dir/root/MAGOS/dev_render/src/render.cpp.i

CMakeFiles/MAGOS.dir/root/MAGOS/dev_render/src/render.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MAGOS.dir/root/MAGOS/dev_render/src/render.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/MAGOS/dev_render/src/render.cpp -o CMakeFiles/MAGOS.dir/root/MAGOS/dev_render/src/render.cpp.s

CMakeFiles/MAGOS.dir/root/MAGOS/dev_render/src/render.cpp.o.requires:

.PHONY : CMakeFiles/MAGOS.dir/root/MAGOS/dev_render/src/render.cpp.o.requires

CMakeFiles/MAGOS.dir/root/MAGOS/dev_render/src/render.cpp.o.provides: CMakeFiles/MAGOS.dir/root/MAGOS/dev_render/src/render.cpp.o.requires
	$(MAKE) -f CMakeFiles/MAGOS.dir/build.make CMakeFiles/MAGOS.dir/root/MAGOS/dev_render/src/render.cpp.o.provides.build
.PHONY : CMakeFiles/MAGOS.dir/root/MAGOS/dev_render/src/render.cpp.o.provides

CMakeFiles/MAGOS.dir/root/MAGOS/dev_render/src/render.cpp.o.provides.build: CMakeFiles/MAGOS.dir/root/MAGOS/dev_render/src/render.cpp.o


CMakeFiles/MAGOS.dir/root/MAGOS/dev_builder/src/builder.cpp.o: CMakeFiles/MAGOS.dir/flags.make
CMakeFiles/MAGOS.dir/root/MAGOS/dev_builder/src/builder.cpp.o: /root/MAGOS/dev_builder/src/builder.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/MAGOS/build_magos/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/MAGOS.dir/root/MAGOS/dev_builder/src/builder.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MAGOS.dir/root/MAGOS/dev_builder/src/builder.cpp.o -c /root/MAGOS/dev_builder/src/builder.cpp

CMakeFiles/MAGOS.dir/root/MAGOS/dev_builder/src/builder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MAGOS.dir/root/MAGOS/dev_builder/src/builder.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/MAGOS/dev_builder/src/builder.cpp > CMakeFiles/MAGOS.dir/root/MAGOS/dev_builder/src/builder.cpp.i

CMakeFiles/MAGOS.dir/root/MAGOS/dev_builder/src/builder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MAGOS.dir/root/MAGOS/dev_builder/src/builder.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/MAGOS/dev_builder/src/builder.cpp -o CMakeFiles/MAGOS.dir/root/MAGOS/dev_builder/src/builder.cpp.s

CMakeFiles/MAGOS.dir/root/MAGOS/dev_builder/src/builder.cpp.o.requires:

.PHONY : CMakeFiles/MAGOS.dir/root/MAGOS/dev_builder/src/builder.cpp.o.requires

CMakeFiles/MAGOS.dir/root/MAGOS/dev_builder/src/builder.cpp.o.provides: CMakeFiles/MAGOS.dir/root/MAGOS/dev_builder/src/builder.cpp.o.requires
	$(MAKE) -f CMakeFiles/MAGOS.dir/build.make CMakeFiles/MAGOS.dir/root/MAGOS/dev_builder/src/builder.cpp.o.provides.build
.PHONY : CMakeFiles/MAGOS.dir/root/MAGOS/dev_builder/src/builder.cpp.o.provides

CMakeFiles/MAGOS.dir/root/MAGOS/dev_builder/src/builder.cpp.o.provides.build: CMakeFiles/MAGOS.dir/root/MAGOS/dev_builder/src/builder.cpp.o


CMakeFiles/MAGOS.dir/root/MAGOS/dev_solver/src/solver.cpp.o: CMakeFiles/MAGOS.dir/flags.make
CMakeFiles/MAGOS.dir/root/MAGOS/dev_solver/src/solver.cpp.o: /root/MAGOS/dev_solver/src/solver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/MAGOS/build_magos/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/MAGOS.dir/root/MAGOS/dev_solver/src/solver.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MAGOS.dir/root/MAGOS/dev_solver/src/solver.cpp.o -c /root/MAGOS/dev_solver/src/solver.cpp

CMakeFiles/MAGOS.dir/root/MAGOS/dev_solver/src/solver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MAGOS.dir/root/MAGOS/dev_solver/src/solver.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/MAGOS/dev_solver/src/solver.cpp > CMakeFiles/MAGOS.dir/root/MAGOS/dev_solver/src/solver.cpp.i

CMakeFiles/MAGOS.dir/root/MAGOS/dev_solver/src/solver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MAGOS.dir/root/MAGOS/dev_solver/src/solver.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/MAGOS/dev_solver/src/solver.cpp -o CMakeFiles/MAGOS.dir/root/MAGOS/dev_solver/src/solver.cpp.s

CMakeFiles/MAGOS.dir/root/MAGOS/dev_solver/src/solver.cpp.o.requires:

.PHONY : CMakeFiles/MAGOS.dir/root/MAGOS/dev_solver/src/solver.cpp.o.requires

CMakeFiles/MAGOS.dir/root/MAGOS/dev_solver/src/solver.cpp.o.provides: CMakeFiles/MAGOS.dir/root/MAGOS/dev_solver/src/solver.cpp.o.requires
	$(MAKE) -f CMakeFiles/MAGOS.dir/build.make CMakeFiles/MAGOS.dir/root/MAGOS/dev_solver/src/solver.cpp.o.provides.build
.PHONY : CMakeFiles/MAGOS.dir/root/MAGOS/dev_solver/src/solver.cpp.o.provides

CMakeFiles/MAGOS.dir/root/MAGOS/dev_solver/src/solver.cpp.o.provides.build: CMakeFiles/MAGOS.dir/root/MAGOS/dev_solver/src/solver.cpp.o


CMakeFiles/MAGOS.dir/root/MAGOS/libs/configFileReader/configFileReader.cpp.o: CMakeFiles/MAGOS.dir/flags.make
CMakeFiles/MAGOS.dir/root/MAGOS/libs/configFileReader/configFileReader.cpp.o: /root/MAGOS/libs/configFileReader/configFileReader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/MAGOS/build_magos/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/MAGOS.dir/root/MAGOS/libs/configFileReader/configFileReader.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MAGOS.dir/root/MAGOS/libs/configFileReader/configFileReader.cpp.o -c /root/MAGOS/libs/configFileReader/configFileReader.cpp

CMakeFiles/MAGOS.dir/root/MAGOS/libs/configFileReader/configFileReader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MAGOS.dir/root/MAGOS/libs/configFileReader/configFileReader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/MAGOS/libs/configFileReader/configFileReader.cpp > CMakeFiles/MAGOS.dir/root/MAGOS/libs/configFileReader/configFileReader.cpp.i

CMakeFiles/MAGOS.dir/root/MAGOS/libs/configFileReader/configFileReader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MAGOS.dir/root/MAGOS/libs/configFileReader/configFileReader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/MAGOS/libs/configFileReader/configFileReader.cpp -o CMakeFiles/MAGOS.dir/root/MAGOS/libs/configFileReader/configFileReader.cpp.s

CMakeFiles/MAGOS.dir/root/MAGOS/libs/configFileReader/configFileReader.cpp.o.requires:

.PHONY : CMakeFiles/MAGOS.dir/root/MAGOS/libs/configFileReader/configFileReader.cpp.o.requires

CMakeFiles/MAGOS.dir/root/MAGOS/libs/configFileReader/configFileReader.cpp.o.provides: CMakeFiles/MAGOS.dir/root/MAGOS/libs/configFileReader/configFileReader.cpp.o.requires
	$(MAKE) -f CMakeFiles/MAGOS.dir/build.make CMakeFiles/MAGOS.dir/root/MAGOS/libs/configFileReader/configFileReader.cpp.o.provides.build
.PHONY : CMakeFiles/MAGOS.dir/root/MAGOS/libs/configFileReader/configFileReader.cpp.o.provides

CMakeFiles/MAGOS.dir/root/MAGOS/libs/configFileReader/configFileReader.cpp.o.provides.build: CMakeFiles/MAGOS.dir/root/MAGOS/libs/configFileReader/configFileReader.cpp.o


CMakeFiles/MAGOS.dir/src/magos.cpp.o: CMakeFiles/MAGOS.dir/flags.make
CMakeFiles/MAGOS.dir/src/magos.cpp.o: /root/MAGOS/dev_magos/src/magos.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/MAGOS/build_magos/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/MAGOS.dir/src/magos.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MAGOS.dir/src/magos.cpp.o -c /root/MAGOS/dev_magos/src/magos.cpp

CMakeFiles/MAGOS.dir/src/magos.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MAGOS.dir/src/magos.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/MAGOS/dev_magos/src/magos.cpp > CMakeFiles/MAGOS.dir/src/magos.cpp.i

CMakeFiles/MAGOS.dir/src/magos.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MAGOS.dir/src/magos.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/MAGOS/dev_magos/src/magos.cpp -o CMakeFiles/MAGOS.dir/src/magos.cpp.s

CMakeFiles/MAGOS.dir/src/magos.cpp.o.requires:

.PHONY : CMakeFiles/MAGOS.dir/src/magos.cpp.o.requires

CMakeFiles/MAGOS.dir/src/magos.cpp.o.provides: CMakeFiles/MAGOS.dir/src/magos.cpp.o.requires
	$(MAKE) -f CMakeFiles/MAGOS.dir/build.make CMakeFiles/MAGOS.dir/src/magos.cpp.o.provides.build
.PHONY : CMakeFiles/MAGOS.dir/src/magos.cpp.o.provides

CMakeFiles/MAGOS.dir/src/magos.cpp.o.provides.build: CMakeFiles/MAGOS.dir/src/magos.cpp.o


CMakeFiles/MAGOS.dir/src/main.cpp.o: CMakeFiles/MAGOS.dir/flags.make
CMakeFiles/MAGOS.dir/src/main.cpp.o: /root/MAGOS/dev_magos/src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/MAGOS/build_magos/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/MAGOS.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MAGOS.dir/src/main.cpp.o -c /root/MAGOS/dev_magos/src/main.cpp

CMakeFiles/MAGOS.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MAGOS.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/MAGOS/dev_magos/src/main.cpp > CMakeFiles/MAGOS.dir/src/main.cpp.i

CMakeFiles/MAGOS.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MAGOS.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/MAGOS/dev_magos/src/main.cpp -o CMakeFiles/MAGOS.dir/src/main.cpp.s

CMakeFiles/MAGOS.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/MAGOS.dir/src/main.cpp.o.requires

CMakeFiles/MAGOS.dir/src/main.cpp.o.provides: CMakeFiles/MAGOS.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/MAGOS.dir/build.make CMakeFiles/MAGOS.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/MAGOS.dir/src/main.cpp.o.provides

CMakeFiles/MAGOS.dir/src/main.cpp.o.provides.build: CMakeFiles/MAGOS.dir/src/main.cpp.o


# Object files for target MAGOS
MAGOS_OBJECTS = \
"CMakeFiles/MAGOS.dir/root/MAGOS/dev_canvas/src/canvas.cpp.o" \
"CMakeFiles/MAGOS.dir/root/MAGOS/dev_maze/src/maze.cpp.o" \
"CMakeFiles/MAGOS.dir/root/MAGOS/dev_render/src/render.cpp.o" \
"CMakeFiles/MAGOS.dir/root/MAGOS/dev_builder/src/builder.cpp.o" \
"CMakeFiles/MAGOS.dir/root/MAGOS/dev_solver/src/solver.cpp.o" \
"CMakeFiles/MAGOS.dir/root/MAGOS/libs/configFileReader/configFileReader.cpp.o" \
"CMakeFiles/MAGOS.dir/src/magos.cpp.o" \
"CMakeFiles/MAGOS.dir/src/main.cpp.o"

# External object files for target MAGOS
MAGOS_EXTERNAL_OBJECTS =

MAGOS: CMakeFiles/MAGOS.dir/root/MAGOS/dev_canvas/src/canvas.cpp.o
MAGOS: CMakeFiles/MAGOS.dir/root/MAGOS/dev_maze/src/maze.cpp.o
MAGOS: CMakeFiles/MAGOS.dir/root/MAGOS/dev_render/src/render.cpp.o
MAGOS: CMakeFiles/MAGOS.dir/root/MAGOS/dev_builder/src/builder.cpp.o
MAGOS: CMakeFiles/MAGOS.dir/root/MAGOS/dev_solver/src/solver.cpp.o
MAGOS: CMakeFiles/MAGOS.dir/root/MAGOS/libs/configFileReader/configFileReader.cpp.o
MAGOS: CMakeFiles/MAGOS.dir/src/magos.cpp.o
MAGOS: CMakeFiles/MAGOS.dir/src/main.cpp.o
MAGOS: CMakeFiles/MAGOS.dir/build.make
MAGOS: CMakeFiles/MAGOS.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/MAGOS/build_magos/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable MAGOS"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MAGOS.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MAGOS.dir/build: MAGOS

.PHONY : CMakeFiles/MAGOS.dir/build

CMakeFiles/MAGOS.dir/requires: CMakeFiles/MAGOS.dir/root/MAGOS/dev_canvas/src/canvas.cpp.o.requires
CMakeFiles/MAGOS.dir/requires: CMakeFiles/MAGOS.dir/root/MAGOS/dev_maze/src/maze.cpp.o.requires
CMakeFiles/MAGOS.dir/requires: CMakeFiles/MAGOS.dir/root/MAGOS/dev_render/src/render.cpp.o.requires
CMakeFiles/MAGOS.dir/requires: CMakeFiles/MAGOS.dir/root/MAGOS/dev_builder/src/builder.cpp.o.requires
CMakeFiles/MAGOS.dir/requires: CMakeFiles/MAGOS.dir/root/MAGOS/dev_solver/src/solver.cpp.o.requires
CMakeFiles/MAGOS.dir/requires: CMakeFiles/MAGOS.dir/root/MAGOS/libs/configFileReader/configFileReader.cpp.o.requires
CMakeFiles/MAGOS.dir/requires: CMakeFiles/MAGOS.dir/src/magos.cpp.o.requires
CMakeFiles/MAGOS.dir/requires: CMakeFiles/MAGOS.dir/src/main.cpp.o.requires

.PHONY : CMakeFiles/MAGOS.dir/requires

CMakeFiles/MAGOS.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MAGOS.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MAGOS.dir/clean

CMakeFiles/MAGOS.dir/depend:
	cd /root/MAGOS/build_magos && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/MAGOS/dev_magos /root/MAGOS/dev_magos /root/MAGOS/build_magos /root/MAGOS/build_magos /root/MAGOS/build_magos/CMakeFiles/MAGOS.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MAGOS.dir/depend

