# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /home/liu/clion-2019.1.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/liu/clion-2019.1.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/liu/c++_study/Algorithm_competition

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/liu/c++_study/Algorithm_competition/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Algorithm_competitio.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Algorithm_competitio.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Algorithm_competitio.dir/flags.make

CMakeFiles/Algorithm_competitio.dir/Template_All/Array/Input.cpp.o: CMakeFiles/Algorithm_competitio.dir/flags.make
CMakeFiles/Algorithm_competitio.dir/Template_All/Array/Input.cpp.o: ../Template_All/Array/Input.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liu/c++_study/Algorithm_competition/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Algorithm_competitio.dir/Template_All/Array/Input.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Algorithm_competitio.dir/Template_All/Array/Input.cpp.o -c /home/liu/c++_study/Algorithm_competition/Template_All/Array/Input.cpp

CMakeFiles/Algorithm_competitio.dir/Template_All/Array/Input.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Algorithm_competitio.dir/Template_All/Array/Input.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liu/c++_study/Algorithm_competition/Template_All/Array/Input.cpp > CMakeFiles/Algorithm_competitio.dir/Template_All/Array/Input.cpp.i

CMakeFiles/Algorithm_competitio.dir/Template_All/Array/Input.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Algorithm_competitio.dir/Template_All/Array/Input.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liu/c++_study/Algorithm_competition/Template_All/Array/Input.cpp -o CMakeFiles/Algorithm_competitio.dir/Template_All/Array/Input.cpp.s

# Object files for target Algorithm_competitio
Algorithm_competitio_OBJECTS = \
"CMakeFiles/Algorithm_competitio.dir/Template_All/Array/Input.cpp.o"

# External object files for target Algorithm_competitio
Algorithm_competitio_EXTERNAL_OBJECTS =

Algorithm_competitio: CMakeFiles/Algorithm_competitio.dir/Template_All/Array/Input.cpp.o
Algorithm_competitio: CMakeFiles/Algorithm_competitio.dir/build.make
Algorithm_competitio: CMakeFiles/Algorithm_competitio.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/liu/c++_study/Algorithm_competition/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Algorithm_competitio"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Algorithm_competitio.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Algorithm_competitio.dir/build: Algorithm_competitio

.PHONY : CMakeFiles/Algorithm_competitio.dir/build

CMakeFiles/Algorithm_competitio.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Algorithm_competitio.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Algorithm_competitio.dir/clean

CMakeFiles/Algorithm_competitio.dir/depend:
	cd /home/liu/c++_study/Algorithm_competition/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/liu/c++_study/Algorithm_competition /home/liu/c++_study/Algorithm_competition /home/liu/c++_study/Algorithm_competition/cmake-build-debug /home/liu/c++_study/Algorithm_competition/cmake-build-debug /home/liu/c++_study/Algorithm_competition/cmake-build-debug/CMakeFiles/Algorithm_competitio.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Algorithm_competitio.dir/depend

