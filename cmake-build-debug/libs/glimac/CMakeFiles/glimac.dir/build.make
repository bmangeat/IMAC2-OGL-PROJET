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
CMAKE_COMMAND = "/Users/brice/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/193.5233.103/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/brice/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/193.5233.103/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/brice/Documents/COURS/OpenGL/Voxel_Project/IMAC2-OGL-PROJET

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/brice/Documents/COURS/OpenGL/Voxel_Project/IMAC2-OGL-PROJET/cmake-build-debug

# Include any dependencies generated for this target.
include libs/glimac/CMakeFiles/glimac.dir/depend.make

# Include the progress variables for this target.
include libs/glimac/CMakeFiles/glimac.dir/progress.make

# Include the compile flags for this target's objects.
include libs/glimac/CMakeFiles/glimac.dir/flags.make

libs/glimac/CMakeFiles/glimac.dir/src/Geometry.cpp.o: libs/glimac/CMakeFiles/glimac.dir/flags.make
libs/glimac/CMakeFiles/glimac.dir/src/Geometry.cpp.o: ../libs/glimac/src/Geometry.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/brice/Documents/COURS/OpenGL/Voxel_Project/IMAC2-OGL-PROJET/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object libs/glimac/CMakeFiles/glimac.dir/src/Geometry.cpp.o"
	cd /Users/brice/Documents/COURS/OpenGL/Voxel_Project/IMAC2-OGL-PROJET/cmake-build-debug/libs/glimac && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/glimac.dir/src/Geometry.cpp.o -c /Users/brice/Documents/COURS/OpenGL/Voxel_Project/IMAC2-OGL-PROJET/libs/glimac/src/Geometry.cpp

libs/glimac/CMakeFiles/glimac.dir/src/Geometry.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/glimac.dir/src/Geometry.cpp.i"
	cd /Users/brice/Documents/COURS/OpenGL/Voxel_Project/IMAC2-OGL-PROJET/cmake-build-debug/libs/glimac && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/brice/Documents/COURS/OpenGL/Voxel_Project/IMAC2-OGL-PROJET/libs/glimac/src/Geometry.cpp > CMakeFiles/glimac.dir/src/Geometry.cpp.i

libs/glimac/CMakeFiles/glimac.dir/src/Geometry.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/glimac.dir/src/Geometry.cpp.s"
	cd /Users/brice/Documents/COURS/OpenGL/Voxel_Project/IMAC2-OGL-PROJET/cmake-build-debug/libs/glimac && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/brice/Documents/COURS/OpenGL/Voxel_Project/IMAC2-OGL-PROJET/libs/glimac/src/Geometry.cpp -o CMakeFiles/glimac.dir/src/Geometry.cpp.s

libs/glimac/CMakeFiles/glimac.dir/src/Image.cpp.o: libs/glimac/CMakeFiles/glimac.dir/flags.make
libs/glimac/CMakeFiles/glimac.dir/src/Image.cpp.o: ../libs/glimac/src/Image.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/brice/Documents/COURS/OpenGL/Voxel_Project/IMAC2-OGL-PROJET/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object libs/glimac/CMakeFiles/glimac.dir/src/Image.cpp.o"
	cd /Users/brice/Documents/COURS/OpenGL/Voxel_Project/IMAC2-OGL-PROJET/cmake-build-debug/libs/glimac && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/glimac.dir/src/Image.cpp.o -c /Users/brice/Documents/COURS/OpenGL/Voxel_Project/IMAC2-OGL-PROJET/libs/glimac/src/Image.cpp

libs/glimac/CMakeFiles/glimac.dir/src/Image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/glimac.dir/src/Image.cpp.i"
	cd /Users/brice/Documents/COURS/OpenGL/Voxel_Project/IMAC2-OGL-PROJET/cmake-build-debug/libs/glimac && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/brice/Documents/COURS/OpenGL/Voxel_Project/IMAC2-OGL-PROJET/libs/glimac/src/Image.cpp > CMakeFiles/glimac.dir/src/Image.cpp.i

libs/glimac/CMakeFiles/glimac.dir/src/Image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/glimac.dir/src/Image.cpp.s"
	cd /Users/brice/Documents/COURS/OpenGL/Voxel_Project/IMAC2-OGL-PROJET/cmake-build-debug/libs/glimac && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/brice/Documents/COURS/OpenGL/Voxel_Project/IMAC2-OGL-PROJET/libs/glimac/src/Image.cpp -o CMakeFiles/glimac.dir/src/Image.cpp.s

libs/glimac/CMakeFiles/glimac.dir/src/Program.cpp.o: libs/glimac/CMakeFiles/glimac.dir/flags.make
libs/glimac/CMakeFiles/glimac.dir/src/Program.cpp.o: ../libs/glimac/src/Program.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/brice/Documents/COURS/OpenGL/Voxel_Project/IMAC2-OGL-PROJET/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object libs/glimac/CMakeFiles/glimac.dir/src/Program.cpp.o"
	cd /Users/brice/Documents/COURS/OpenGL/Voxel_Project/IMAC2-OGL-PROJET/cmake-build-debug/libs/glimac && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/glimac.dir/src/Program.cpp.o -c /Users/brice/Documents/COURS/OpenGL/Voxel_Project/IMAC2-OGL-PROJET/libs/glimac/src/Program.cpp

libs/glimac/CMakeFiles/glimac.dir/src/Program.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/glimac.dir/src/Program.cpp.i"
	cd /Users/brice/Documents/COURS/OpenGL/Voxel_Project/IMAC2-OGL-PROJET/cmake-build-debug/libs/glimac && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/brice/Documents/COURS/OpenGL/Voxel_Project/IMAC2-OGL-PROJET/libs/glimac/src/Program.cpp > CMakeFiles/glimac.dir/src/Program.cpp.i

libs/glimac/CMakeFiles/glimac.dir/src/Program.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/glimac.dir/src/Program.cpp.s"
	cd /Users/brice/Documents/COURS/OpenGL/Voxel_Project/IMAC2-OGL-PROJET/cmake-build-debug/libs/glimac && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/brice/Documents/COURS/OpenGL/Voxel_Project/IMAC2-OGL-PROJET/libs/glimac/src/Program.cpp -o CMakeFiles/glimac.dir/src/Program.cpp.s

libs/glimac/CMakeFiles/glimac.dir/src/SDLWindowManager.cpp.o: libs/glimac/CMakeFiles/glimac.dir/flags.make
libs/glimac/CMakeFiles/glimac.dir/src/SDLWindowManager.cpp.o: ../libs/glimac/src/SDLWindowManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/brice/Documents/COURS/OpenGL/Voxel_Project/IMAC2-OGL-PROJET/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object libs/glimac/CMakeFiles/glimac.dir/src/SDLWindowManager.cpp.o"
	cd /Users/brice/Documents/COURS/OpenGL/Voxel_Project/IMAC2-OGL-PROJET/cmake-build-debug/libs/glimac && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/glimac.dir/src/SDLWindowManager.cpp.o -c /Users/brice/Documents/COURS/OpenGL/Voxel_Project/IMAC2-OGL-PROJET/libs/glimac/src/SDLWindowManager.cpp

libs/glimac/CMakeFiles/glimac.dir/src/SDLWindowManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/glimac.dir/src/SDLWindowManager.cpp.i"
	cd /Users/brice/Documents/COURS/OpenGL/Voxel_Project/IMAC2-OGL-PROJET/cmake-build-debug/libs/glimac && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/brice/Documents/COURS/OpenGL/Voxel_Project/IMAC2-OGL-PROJET/libs/glimac/src/SDLWindowManager.cpp > CMakeFiles/glimac.dir/src/SDLWindowManager.cpp.i

libs/glimac/CMakeFiles/glimac.dir/src/SDLWindowManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/glimac.dir/src/SDLWindowManager.cpp.s"
	cd /Users/brice/Documents/COURS/OpenGL/Voxel_Project/IMAC2-OGL-PROJET/cmake-build-debug/libs/glimac && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/brice/Documents/COURS/OpenGL/Voxel_Project/IMAC2-OGL-PROJET/libs/glimac/src/SDLWindowManager.cpp -o CMakeFiles/glimac.dir/src/SDLWindowManager.cpp.s

libs/glimac/CMakeFiles/glimac.dir/src/Shader.cpp.o: libs/glimac/CMakeFiles/glimac.dir/flags.make
libs/glimac/CMakeFiles/glimac.dir/src/Shader.cpp.o: ../libs/glimac/src/Shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/brice/Documents/COURS/OpenGL/Voxel_Project/IMAC2-OGL-PROJET/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object libs/glimac/CMakeFiles/glimac.dir/src/Shader.cpp.o"
	cd /Users/brice/Documents/COURS/OpenGL/Voxel_Project/IMAC2-OGL-PROJET/cmake-build-debug/libs/glimac && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/glimac.dir/src/Shader.cpp.o -c /Users/brice/Documents/COURS/OpenGL/Voxel_Project/IMAC2-OGL-PROJET/libs/glimac/src/Shader.cpp

libs/glimac/CMakeFiles/glimac.dir/src/Shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/glimac.dir/src/Shader.cpp.i"
	cd /Users/brice/Documents/COURS/OpenGL/Voxel_Project/IMAC2-OGL-PROJET/cmake-build-debug/libs/glimac && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/brice/Documents/COURS/OpenGL/Voxel_Project/IMAC2-OGL-PROJET/libs/glimac/src/Shader.cpp > CMakeFiles/glimac.dir/src/Shader.cpp.i

libs/glimac/CMakeFiles/glimac.dir/src/Shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/glimac.dir/src/Shader.cpp.s"
	cd /Users/brice/Documents/COURS/OpenGL/Voxel_Project/IMAC2-OGL-PROJET/cmake-build-debug/libs/glimac && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/brice/Documents/COURS/OpenGL/Voxel_Project/IMAC2-OGL-PROJET/libs/glimac/src/Shader.cpp -o CMakeFiles/glimac.dir/src/Shader.cpp.s

libs/glimac/CMakeFiles/glimac.dir/src/tiny_obj_loader.cpp.o: libs/glimac/CMakeFiles/glimac.dir/flags.make
libs/glimac/CMakeFiles/glimac.dir/src/tiny_obj_loader.cpp.o: ../libs/glimac/src/tiny_obj_loader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/brice/Documents/COURS/OpenGL/Voxel_Project/IMAC2-OGL-PROJET/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object libs/glimac/CMakeFiles/glimac.dir/src/tiny_obj_loader.cpp.o"
	cd /Users/brice/Documents/COURS/OpenGL/Voxel_Project/IMAC2-OGL-PROJET/cmake-build-debug/libs/glimac && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/glimac.dir/src/tiny_obj_loader.cpp.o -c /Users/brice/Documents/COURS/OpenGL/Voxel_Project/IMAC2-OGL-PROJET/libs/glimac/src/tiny_obj_loader.cpp

libs/glimac/CMakeFiles/glimac.dir/src/tiny_obj_loader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/glimac.dir/src/tiny_obj_loader.cpp.i"
	cd /Users/brice/Documents/COURS/OpenGL/Voxel_Project/IMAC2-OGL-PROJET/cmake-build-debug/libs/glimac && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/brice/Documents/COURS/OpenGL/Voxel_Project/IMAC2-OGL-PROJET/libs/glimac/src/tiny_obj_loader.cpp > CMakeFiles/glimac.dir/src/tiny_obj_loader.cpp.i

libs/glimac/CMakeFiles/glimac.dir/src/tiny_obj_loader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/glimac.dir/src/tiny_obj_loader.cpp.s"
	cd /Users/brice/Documents/COURS/OpenGL/Voxel_Project/IMAC2-OGL-PROJET/cmake-build-debug/libs/glimac && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/brice/Documents/COURS/OpenGL/Voxel_Project/IMAC2-OGL-PROJET/libs/glimac/src/tiny_obj_loader.cpp -o CMakeFiles/glimac.dir/src/tiny_obj_loader.cpp.s

# Object files for target glimac
glimac_OBJECTS = \
"CMakeFiles/glimac.dir/src/Geometry.cpp.o" \
"CMakeFiles/glimac.dir/src/Image.cpp.o" \
"CMakeFiles/glimac.dir/src/Program.cpp.o" \
"CMakeFiles/glimac.dir/src/SDLWindowManager.cpp.o" \
"CMakeFiles/glimac.dir/src/Shader.cpp.o" \
"CMakeFiles/glimac.dir/src/tiny_obj_loader.cpp.o"

# External object files for target glimac
glimac_EXTERNAL_OBJECTS =

libs/glimac/libglimac.a: libs/glimac/CMakeFiles/glimac.dir/src/Geometry.cpp.o
libs/glimac/libglimac.a: libs/glimac/CMakeFiles/glimac.dir/src/Image.cpp.o
libs/glimac/libglimac.a: libs/glimac/CMakeFiles/glimac.dir/src/Program.cpp.o
libs/glimac/libglimac.a: libs/glimac/CMakeFiles/glimac.dir/src/SDLWindowManager.cpp.o
libs/glimac/libglimac.a: libs/glimac/CMakeFiles/glimac.dir/src/Shader.cpp.o
libs/glimac/libglimac.a: libs/glimac/CMakeFiles/glimac.dir/src/tiny_obj_loader.cpp.o
libs/glimac/libglimac.a: libs/glimac/CMakeFiles/glimac.dir/build.make
libs/glimac/libglimac.a: libs/glimac/CMakeFiles/glimac.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/brice/Documents/COURS/OpenGL/Voxel_Project/IMAC2-OGL-PROJET/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX static library libglimac.a"
	cd /Users/brice/Documents/COURS/OpenGL/Voxel_Project/IMAC2-OGL-PROJET/cmake-build-debug/libs/glimac && $(CMAKE_COMMAND) -P CMakeFiles/glimac.dir/cmake_clean_target.cmake
	cd /Users/brice/Documents/COURS/OpenGL/Voxel_Project/IMAC2-OGL-PROJET/cmake-build-debug/libs/glimac && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/glimac.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libs/glimac/CMakeFiles/glimac.dir/build: libs/glimac/libglimac.a

.PHONY : libs/glimac/CMakeFiles/glimac.dir/build

libs/glimac/CMakeFiles/glimac.dir/clean:
	cd /Users/brice/Documents/COURS/OpenGL/Voxel_Project/IMAC2-OGL-PROJET/cmake-build-debug/libs/glimac && $(CMAKE_COMMAND) -P CMakeFiles/glimac.dir/cmake_clean.cmake
.PHONY : libs/glimac/CMakeFiles/glimac.dir/clean

libs/glimac/CMakeFiles/glimac.dir/depend:
	cd /Users/brice/Documents/COURS/OpenGL/Voxel_Project/IMAC2-OGL-PROJET/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/brice/Documents/COURS/OpenGL/Voxel_Project/IMAC2-OGL-PROJET /Users/brice/Documents/COURS/OpenGL/Voxel_Project/IMAC2-OGL-PROJET/libs/glimac /Users/brice/Documents/COURS/OpenGL/Voxel_Project/IMAC2-OGL-PROJET/cmake-build-debug /Users/brice/Documents/COURS/OpenGL/Voxel_Project/IMAC2-OGL-PROJET/cmake-build-debug/libs/glimac /Users/brice/Documents/COURS/OpenGL/Voxel_Project/IMAC2-OGL-PROJET/cmake-build-debug/libs/glimac/CMakeFiles/glimac.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libs/glimac/CMakeFiles/glimac.dir/depend

