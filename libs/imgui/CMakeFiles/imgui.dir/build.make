# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/brice/Documents/IMAC/projet-imaker/IMAC2-OGL-PROJET

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/brice/Documents/IMAC/projet-imaker/IMAC2-OGL-PROJET

# Include any dependencies generated for this target.
include libs/imgui/CMakeFiles/imgui.dir/depend.make

# Include the progress variables for this target.
include libs/imgui/CMakeFiles/imgui.dir/progress.make

# Include the compile flags for this target's objects.
include libs/imgui/CMakeFiles/imgui.dir/flags.make

libs/imgui/CMakeFiles/imgui.dir/src/imgui.cpp.o: libs/imgui/CMakeFiles/imgui.dir/flags.make
libs/imgui/CMakeFiles/imgui.dir/src/imgui.cpp.o: libs/imgui/src/imgui.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/brice/Documents/IMAC/projet-imaker/IMAC2-OGL-PROJET/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object libs/imgui/CMakeFiles/imgui.dir/src/imgui.cpp.o"
	cd /Users/brice/Documents/IMAC/projet-imaker/IMAC2-OGL-PROJET/libs/imgui && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/imgui.dir/src/imgui.cpp.o -c /Users/brice/Documents/IMAC/projet-imaker/IMAC2-OGL-PROJET/libs/imgui/src/imgui.cpp

libs/imgui/CMakeFiles/imgui.dir/src/imgui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/imgui.dir/src/imgui.cpp.i"
	cd /Users/brice/Documents/IMAC/projet-imaker/IMAC2-OGL-PROJET/libs/imgui && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/brice/Documents/IMAC/projet-imaker/IMAC2-OGL-PROJET/libs/imgui/src/imgui.cpp > CMakeFiles/imgui.dir/src/imgui.cpp.i

libs/imgui/CMakeFiles/imgui.dir/src/imgui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/imgui.dir/src/imgui.cpp.s"
	cd /Users/brice/Documents/IMAC/projet-imaker/IMAC2-OGL-PROJET/libs/imgui && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/brice/Documents/IMAC/projet-imaker/IMAC2-OGL-PROJET/libs/imgui/src/imgui.cpp -o CMakeFiles/imgui.dir/src/imgui.cpp.s

libs/imgui/CMakeFiles/imgui.dir/src/imgui_demo.cpp.o: libs/imgui/CMakeFiles/imgui.dir/flags.make
libs/imgui/CMakeFiles/imgui.dir/src/imgui_demo.cpp.o: libs/imgui/src/imgui_demo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/brice/Documents/IMAC/projet-imaker/IMAC2-OGL-PROJET/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object libs/imgui/CMakeFiles/imgui.dir/src/imgui_demo.cpp.o"
	cd /Users/brice/Documents/IMAC/projet-imaker/IMAC2-OGL-PROJET/libs/imgui && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/imgui.dir/src/imgui_demo.cpp.o -c /Users/brice/Documents/IMAC/projet-imaker/IMAC2-OGL-PROJET/libs/imgui/src/imgui_demo.cpp

libs/imgui/CMakeFiles/imgui.dir/src/imgui_demo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/imgui.dir/src/imgui_demo.cpp.i"
	cd /Users/brice/Documents/IMAC/projet-imaker/IMAC2-OGL-PROJET/libs/imgui && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/brice/Documents/IMAC/projet-imaker/IMAC2-OGL-PROJET/libs/imgui/src/imgui_demo.cpp > CMakeFiles/imgui.dir/src/imgui_demo.cpp.i

libs/imgui/CMakeFiles/imgui.dir/src/imgui_demo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/imgui.dir/src/imgui_demo.cpp.s"
	cd /Users/brice/Documents/IMAC/projet-imaker/IMAC2-OGL-PROJET/libs/imgui && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/brice/Documents/IMAC/projet-imaker/IMAC2-OGL-PROJET/libs/imgui/src/imgui_demo.cpp -o CMakeFiles/imgui.dir/src/imgui_demo.cpp.s

libs/imgui/CMakeFiles/imgui.dir/src/imgui_draw.cpp.o: libs/imgui/CMakeFiles/imgui.dir/flags.make
libs/imgui/CMakeFiles/imgui.dir/src/imgui_draw.cpp.o: libs/imgui/src/imgui_draw.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/brice/Documents/IMAC/projet-imaker/IMAC2-OGL-PROJET/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object libs/imgui/CMakeFiles/imgui.dir/src/imgui_draw.cpp.o"
	cd /Users/brice/Documents/IMAC/projet-imaker/IMAC2-OGL-PROJET/libs/imgui && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/imgui.dir/src/imgui_draw.cpp.o -c /Users/brice/Documents/IMAC/projet-imaker/IMAC2-OGL-PROJET/libs/imgui/src/imgui_draw.cpp

libs/imgui/CMakeFiles/imgui.dir/src/imgui_draw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/imgui.dir/src/imgui_draw.cpp.i"
	cd /Users/brice/Documents/IMAC/projet-imaker/IMAC2-OGL-PROJET/libs/imgui && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/brice/Documents/IMAC/projet-imaker/IMAC2-OGL-PROJET/libs/imgui/src/imgui_draw.cpp > CMakeFiles/imgui.dir/src/imgui_draw.cpp.i

libs/imgui/CMakeFiles/imgui.dir/src/imgui_draw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/imgui.dir/src/imgui_draw.cpp.s"
	cd /Users/brice/Documents/IMAC/projet-imaker/IMAC2-OGL-PROJET/libs/imgui && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/brice/Documents/IMAC/projet-imaker/IMAC2-OGL-PROJET/libs/imgui/src/imgui_draw.cpp -o CMakeFiles/imgui.dir/src/imgui_draw.cpp.s

libs/imgui/CMakeFiles/imgui.dir/src/imgui_impl_opengl3.cpp.o: libs/imgui/CMakeFiles/imgui.dir/flags.make
libs/imgui/CMakeFiles/imgui.dir/src/imgui_impl_opengl3.cpp.o: libs/imgui/src/imgui_impl_opengl3.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/brice/Documents/IMAC/projet-imaker/IMAC2-OGL-PROJET/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object libs/imgui/CMakeFiles/imgui.dir/src/imgui_impl_opengl3.cpp.o"
	cd /Users/brice/Documents/IMAC/projet-imaker/IMAC2-OGL-PROJET/libs/imgui && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/imgui.dir/src/imgui_impl_opengl3.cpp.o -c /Users/brice/Documents/IMAC/projet-imaker/IMAC2-OGL-PROJET/libs/imgui/src/imgui_impl_opengl3.cpp

libs/imgui/CMakeFiles/imgui.dir/src/imgui_impl_opengl3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/imgui.dir/src/imgui_impl_opengl3.cpp.i"
	cd /Users/brice/Documents/IMAC/projet-imaker/IMAC2-OGL-PROJET/libs/imgui && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/brice/Documents/IMAC/projet-imaker/IMAC2-OGL-PROJET/libs/imgui/src/imgui_impl_opengl3.cpp > CMakeFiles/imgui.dir/src/imgui_impl_opengl3.cpp.i

libs/imgui/CMakeFiles/imgui.dir/src/imgui_impl_opengl3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/imgui.dir/src/imgui_impl_opengl3.cpp.s"
	cd /Users/brice/Documents/IMAC/projet-imaker/IMAC2-OGL-PROJET/libs/imgui && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/brice/Documents/IMAC/projet-imaker/IMAC2-OGL-PROJET/libs/imgui/src/imgui_impl_opengl3.cpp -o CMakeFiles/imgui.dir/src/imgui_impl_opengl3.cpp.s

libs/imgui/CMakeFiles/imgui.dir/src/imgui_impl_sdl.cpp.o: libs/imgui/CMakeFiles/imgui.dir/flags.make
libs/imgui/CMakeFiles/imgui.dir/src/imgui_impl_sdl.cpp.o: libs/imgui/src/imgui_impl_sdl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/brice/Documents/IMAC/projet-imaker/IMAC2-OGL-PROJET/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object libs/imgui/CMakeFiles/imgui.dir/src/imgui_impl_sdl.cpp.o"
	cd /Users/brice/Documents/IMAC/projet-imaker/IMAC2-OGL-PROJET/libs/imgui && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/imgui.dir/src/imgui_impl_sdl.cpp.o -c /Users/brice/Documents/IMAC/projet-imaker/IMAC2-OGL-PROJET/libs/imgui/src/imgui_impl_sdl.cpp

libs/imgui/CMakeFiles/imgui.dir/src/imgui_impl_sdl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/imgui.dir/src/imgui_impl_sdl.cpp.i"
	cd /Users/brice/Documents/IMAC/projet-imaker/IMAC2-OGL-PROJET/libs/imgui && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/brice/Documents/IMAC/projet-imaker/IMAC2-OGL-PROJET/libs/imgui/src/imgui_impl_sdl.cpp > CMakeFiles/imgui.dir/src/imgui_impl_sdl.cpp.i

libs/imgui/CMakeFiles/imgui.dir/src/imgui_impl_sdl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/imgui.dir/src/imgui_impl_sdl.cpp.s"
	cd /Users/brice/Documents/IMAC/projet-imaker/IMAC2-OGL-PROJET/libs/imgui && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/brice/Documents/IMAC/projet-imaker/IMAC2-OGL-PROJET/libs/imgui/src/imgui_impl_sdl.cpp -o CMakeFiles/imgui.dir/src/imgui_impl_sdl.cpp.s

libs/imgui/CMakeFiles/imgui.dir/src/imgui_widgets.cpp.o: libs/imgui/CMakeFiles/imgui.dir/flags.make
libs/imgui/CMakeFiles/imgui.dir/src/imgui_widgets.cpp.o: libs/imgui/src/imgui_widgets.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/brice/Documents/IMAC/projet-imaker/IMAC2-OGL-PROJET/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object libs/imgui/CMakeFiles/imgui.dir/src/imgui_widgets.cpp.o"
	cd /Users/brice/Documents/IMAC/projet-imaker/IMAC2-OGL-PROJET/libs/imgui && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/imgui.dir/src/imgui_widgets.cpp.o -c /Users/brice/Documents/IMAC/projet-imaker/IMAC2-OGL-PROJET/libs/imgui/src/imgui_widgets.cpp

libs/imgui/CMakeFiles/imgui.dir/src/imgui_widgets.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/imgui.dir/src/imgui_widgets.cpp.i"
	cd /Users/brice/Documents/IMAC/projet-imaker/IMAC2-OGL-PROJET/libs/imgui && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/brice/Documents/IMAC/projet-imaker/IMAC2-OGL-PROJET/libs/imgui/src/imgui_widgets.cpp > CMakeFiles/imgui.dir/src/imgui_widgets.cpp.i

libs/imgui/CMakeFiles/imgui.dir/src/imgui_widgets.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/imgui.dir/src/imgui_widgets.cpp.s"
	cd /Users/brice/Documents/IMAC/projet-imaker/IMAC2-OGL-PROJET/libs/imgui && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/brice/Documents/IMAC/projet-imaker/IMAC2-OGL-PROJET/libs/imgui/src/imgui_widgets.cpp -o CMakeFiles/imgui.dir/src/imgui_widgets.cpp.s

# Object files for target imgui
imgui_OBJECTS = \
"CMakeFiles/imgui.dir/src/imgui.cpp.o" \
"CMakeFiles/imgui.dir/src/imgui_demo.cpp.o" \
"CMakeFiles/imgui.dir/src/imgui_draw.cpp.o" \
"CMakeFiles/imgui.dir/src/imgui_impl_opengl3.cpp.o" \
"CMakeFiles/imgui.dir/src/imgui_impl_sdl.cpp.o" \
"CMakeFiles/imgui.dir/src/imgui_widgets.cpp.o"

# External object files for target imgui
imgui_EXTERNAL_OBJECTS =

libs/imgui/libimgui.a: libs/imgui/CMakeFiles/imgui.dir/src/imgui.cpp.o
libs/imgui/libimgui.a: libs/imgui/CMakeFiles/imgui.dir/src/imgui_demo.cpp.o
libs/imgui/libimgui.a: libs/imgui/CMakeFiles/imgui.dir/src/imgui_draw.cpp.o
libs/imgui/libimgui.a: libs/imgui/CMakeFiles/imgui.dir/src/imgui_impl_opengl3.cpp.o
libs/imgui/libimgui.a: libs/imgui/CMakeFiles/imgui.dir/src/imgui_impl_sdl.cpp.o
libs/imgui/libimgui.a: libs/imgui/CMakeFiles/imgui.dir/src/imgui_widgets.cpp.o
libs/imgui/libimgui.a: libs/imgui/CMakeFiles/imgui.dir/build.make
libs/imgui/libimgui.a: libs/imgui/CMakeFiles/imgui.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/brice/Documents/IMAC/projet-imaker/IMAC2-OGL-PROJET/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX static library libimgui.a"
	cd /Users/brice/Documents/IMAC/projet-imaker/IMAC2-OGL-PROJET/libs/imgui && $(CMAKE_COMMAND) -P CMakeFiles/imgui.dir/cmake_clean_target.cmake
	cd /Users/brice/Documents/IMAC/projet-imaker/IMAC2-OGL-PROJET/libs/imgui && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/imgui.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libs/imgui/CMakeFiles/imgui.dir/build: libs/imgui/libimgui.a

.PHONY : libs/imgui/CMakeFiles/imgui.dir/build

libs/imgui/CMakeFiles/imgui.dir/clean:
	cd /Users/brice/Documents/IMAC/projet-imaker/IMAC2-OGL-PROJET/libs/imgui && $(CMAKE_COMMAND) -P CMakeFiles/imgui.dir/cmake_clean.cmake
.PHONY : libs/imgui/CMakeFiles/imgui.dir/clean

libs/imgui/CMakeFiles/imgui.dir/depend:
	cd /Users/brice/Documents/IMAC/projet-imaker/IMAC2-OGL-PROJET && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/brice/Documents/IMAC/projet-imaker/IMAC2-OGL-PROJET /Users/brice/Documents/IMAC/projet-imaker/IMAC2-OGL-PROJET/libs/imgui /Users/brice/Documents/IMAC/projet-imaker/IMAC2-OGL-PROJET /Users/brice/Documents/IMAC/projet-imaker/IMAC2-OGL-PROJET/libs/imgui /Users/brice/Documents/IMAC/projet-imaker/IMAC2-OGL-PROJET/libs/imgui/CMakeFiles/imgui.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libs/imgui/CMakeFiles/imgui.dir/depend

