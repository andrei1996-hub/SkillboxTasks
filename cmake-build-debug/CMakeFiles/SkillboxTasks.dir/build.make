# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /home/andrei1996/clion-2021.1.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/andrei1996/clion-2021.1.2/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/andrei1996/CLionProjects/SkillboxTasks

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/andrei1996/CLionProjects/SkillboxTasks/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SkillboxTasks.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/SkillboxTasks.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SkillboxTasks.dir/flags.make

CMakeFiles/SkillboxTasks.dir/M14FINAL.cpp.o: CMakeFiles/SkillboxTasks.dir/flags.make
CMakeFiles/SkillboxTasks.dir/M14FINAL.cpp.o: ../M14FINAL.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andrei1996/CLionProjects/SkillboxTasks/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SkillboxTasks.dir/M14FINAL.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SkillboxTasks.dir/M14FINAL.cpp.o -c /home/andrei1996/CLionProjects/SkillboxTasks/M14FINAL.cpp

CMakeFiles/SkillboxTasks.dir/M14FINAL.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SkillboxTasks.dir/M14FINAL.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andrei1996/CLionProjects/SkillboxTasks/M14FINAL.cpp > CMakeFiles/SkillboxTasks.dir/M14FINAL.cpp.i

CMakeFiles/SkillboxTasks.dir/M14FINAL.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SkillboxTasks.dir/M14FINAL.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andrei1996/CLionProjects/SkillboxTasks/M14FINAL.cpp -o CMakeFiles/SkillboxTasks.dir/M14FINAL.cpp.s

# Object files for target SkillboxTasks
SkillboxTasks_OBJECTS = \
"CMakeFiles/SkillboxTasks.dir/M14FINAL.cpp.o"

# External object files for target SkillboxTasks
SkillboxTasks_EXTERNAL_OBJECTS =

SkillboxTasks: CMakeFiles/SkillboxTasks.dir/M14FINAL.cpp.o
SkillboxTasks: CMakeFiles/SkillboxTasks.dir/build.make
SkillboxTasks: CMakeFiles/SkillboxTasks.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/andrei1996/CLionProjects/SkillboxTasks/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SkillboxTasks"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SkillboxTasks.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SkillboxTasks.dir/build: SkillboxTasks
.PHONY : CMakeFiles/SkillboxTasks.dir/build

CMakeFiles/SkillboxTasks.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SkillboxTasks.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SkillboxTasks.dir/clean

CMakeFiles/SkillboxTasks.dir/depend:
	cd /home/andrei1996/CLionProjects/SkillboxTasks/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/andrei1996/CLionProjects/SkillboxTasks /home/andrei1996/CLionProjects/SkillboxTasks /home/andrei1996/CLionProjects/SkillboxTasks/cmake-build-debug /home/andrei1996/CLionProjects/SkillboxTasks/cmake-build-debug /home/andrei1996/CLionProjects/SkillboxTasks/cmake-build-debug/CMakeFiles/SkillboxTasks.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SkillboxTasks.dir/depend

