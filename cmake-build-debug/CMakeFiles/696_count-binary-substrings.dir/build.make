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
include CMakeFiles/696_count-binary-substrings.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/696_count-binary-substrings.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/696_count-binary-substrings.dir/flags.make

CMakeFiles/696_count-binary-substrings.dir/leetcode/editor/cn/696_count-binary-substrings.cpp.o: CMakeFiles/696_count-binary-substrings.dir/flags.make
CMakeFiles/696_count-binary-substrings.dir/leetcode/editor/cn/696_count-binary-substrings.cpp.o: ../leetcode/editor/cn/696_count-binary-substrings.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/chenjialin/CLionProjects/AlgorithmGo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/696_count-binary-substrings.dir/leetcode/editor/cn/696_count-binary-substrings.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/696_count-binary-substrings.dir/leetcode/editor/cn/696_count-binary-substrings.cpp.o -c /Users/chenjialin/CLionProjects/AlgorithmGo/leetcode/editor/cn/696_count-binary-substrings.cpp

CMakeFiles/696_count-binary-substrings.dir/leetcode/editor/cn/696_count-binary-substrings.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/696_count-binary-substrings.dir/leetcode/editor/cn/696_count-binary-substrings.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/chenjialin/CLionProjects/AlgorithmGo/leetcode/editor/cn/696_count-binary-substrings.cpp > CMakeFiles/696_count-binary-substrings.dir/leetcode/editor/cn/696_count-binary-substrings.cpp.i

CMakeFiles/696_count-binary-substrings.dir/leetcode/editor/cn/696_count-binary-substrings.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/696_count-binary-substrings.dir/leetcode/editor/cn/696_count-binary-substrings.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/chenjialin/CLionProjects/AlgorithmGo/leetcode/editor/cn/696_count-binary-substrings.cpp -o CMakeFiles/696_count-binary-substrings.dir/leetcode/editor/cn/696_count-binary-substrings.cpp.s

# Object files for target 696_count-binary-substrings
696_count__binary__substrings_OBJECTS = \
"CMakeFiles/696_count-binary-substrings.dir/leetcode/editor/cn/696_count-binary-substrings.cpp.o"

# External object files for target 696_count-binary-substrings
696_count__binary__substrings_EXTERNAL_OBJECTS =

696_count-binary-substrings: CMakeFiles/696_count-binary-substrings.dir/leetcode/editor/cn/696_count-binary-substrings.cpp.o
696_count-binary-substrings: CMakeFiles/696_count-binary-substrings.dir/build.make
696_count-binary-substrings: CMakeFiles/696_count-binary-substrings.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/chenjialin/CLionProjects/AlgorithmGo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 696_count-binary-substrings"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/696_count-binary-substrings.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/696_count-binary-substrings.dir/build: 696_count-binary-substrings
.PHONY : CMakeFiles/696_count-binary-substrings.dir/build

CMakeFiles/696_count-binary-substrings.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/696_count-binary-substrings.dir/cmake_clean.cmake
.PHONY : CMakeFiles/696_count-binary-substrings.dir/clean

CMakeFiles/696_count-binary-substrings.dir/depend:
	cd /Users/chenjialin/CLionProjects/AlgorithmGo/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/chenjialin/CLionProjects/AlgorithmGo /Users/chenjialin/CLionProjects/AlgorithmGo /Users/chenjialin/CLionProjects/AlgorithmGo/cmake-build-debug /Users/chenjialin/CLionProjects/AlgorithmGo/cmake-build-debug /Users/chenjialin/CLionProjects/AlgorithmGo/cmake-build-debug/CMakeFiles/696_count-binary-substrings.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/696_count-binary-substrings.dir/depend

