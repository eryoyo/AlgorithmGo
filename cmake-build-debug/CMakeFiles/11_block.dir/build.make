# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/chenjialin/CLionProjects/AlgorithmGo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/chenjialin/CLionProjects/AlgorithmGo/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/11_block.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/11_block.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/11_block.dir/flags.make

CMakeFiles/11_block.dir/PAT/11_more/11_block.cpp.o: CMakeFiles/11_block.dir/flags.make
CMakeFiles/11_block.dir/PAT/11_more/11_block.cpp.o: ../PAT/11_more/11_block.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/chenjialin/CLionProjects/AlgorithmGo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/11_block.dir/PAT/11_more/11_block.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/11_block.dir/PAT/11_more/11_block.cpp.o -c /Users/chenjialin/CLionProjects/AlgorithmGo/PAT/11_more/11_block.cpp

CMakeFiles/11_block.dir/PAT/11_more/11_block.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/11_block.dir/PAT/11_more/11_block.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/chenjialin/CLionProjects/AlgorithmGo/PAT/11_more/11_block.cpp > CMakeFiles/11_block.dir/PAT/11_more/11_block.cpp.i

CMakeFiles/11_block.dir/PAT/11_more/11_block.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/11_block.dir/PAT/11_more/11_block.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/chenjialin/CLionProjects/AlgorithmGo/PAT/11_more/11_block.cpp -o CMakeFiles/11_block.dir/PAT/11_more/11_block.cpp.s

# Object files for target 11_block
11_block_OBJECTS = \
"CMakeFiles/11_block.dir/PAT/11_more/11_block.cpp.o"

# External object files for target 11_block
11_block_EXTERNAL_OBJECTS =

11_block: CMakeFiles/11_block.dir/PAT/11_more/11_block.cpp.o
11_block: CMakeFiles/11_block.dir/build.make
11_block: CMakeFiles/11_block.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/chenjialin/CLionProjects/AlgorithmGo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 11_block"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/11_block.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/11_block.dir/build: 11_block
.PHONY : CMakeFiles/11_block.dir/build

CMakeFiles/11_block.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/11_block.dir/cmake_clean.cmake
.PHONY : CMakeFiles/11_block.dir/clean

CMakeFiles/11_block.dir/depend:
	cd /Users/chenjialin/CLionProjects/AlgorithmGo/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/chenjialin/CLionProjects/AlgorithmGo /Users/chenjialin/CLionProjects/AlgorithmGo /Users/chenjialin/CLionProjects/AlgorithmGo/cmake-build-debug /Users/chenjialin/CLionProjects/AlgorithmGo/cmake-build-debug /Users/chenjialin/CLionProjects/AlgorithmGo/cmake-build-debug/CMakeFiles/11_block.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/11_block.dir/depend

