# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\repos\OOP\lab10\task5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\repos\OOP\lab10\task5\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/task5.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/task5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/task5.dir/flags.make

CMakeFiles/task5.dir/main.cpp.obj: CMakeFiles/task5.dir/flags.make
CMakeFiles/task5.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\repos\OOP\lab10\task5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/task5.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\task5.dir\main.cpp.obj -c D:\repos\OOP\lab10\task5\main.cpp

CMakeFiles/task5.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task5.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\repos\OOP\lab10\task5\main.cpp > CMakeFiles\task5.dir\main.cpp.i

CMakeFiles/task5.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task5.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\repos\OOP\lab10\task5\main.cpp -o CMakeFiles\task5.dir\main.cpp.s

# Object files for target task5
task5_OBJECTS = \
"CMakeFiles/task5.dir/main.cpp.obj"

# External object files for target task5
task5_EXTERNAL_OBJECTS =

task5.exe: CMakeFiles/task5.dir/main.cpp.obj
task5.exe: CMakeFiles/task5.dir/build.make
task5.exe: CMakeFiles/task5.dir/linklibs.rsp
task5.exe: CMakeFiles/task5.dir/objects1.rsp
task5.exe: CMakeFiles/task5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\repos\OOP\lab10\task5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable task5.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\task5.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/task5.dir/build: task5.exe

.PHONY : CMakeFiles/task5.dir/build

CMakeFiles/task5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\task5.dir\cmake_clean.cmake
.PHONY : CMakeFiles/task5.dir/clean

CMakeFiles/task5.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\repos\OOP\lab10\task5 D:\repos\OOP\lab10\task5 D:\repos\OOP\lab10\task5\cmake-build-debug D:\repos\OOP\lab10\task5\cmake-build-debug D:\repos\OOP\lab10\task5\cmake-build-debug\CMakeFiles\task5.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/task5.dir/depend

