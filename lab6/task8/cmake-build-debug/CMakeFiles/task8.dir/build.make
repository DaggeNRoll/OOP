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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\dagge\CLionProjects\OOP\lab6\task8

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\dagge\CLionProjects\OOP\lab6\task8\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/task8.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/task8.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/task8.dir/flags.make

CMakeFiles/task8.dir/main.cpp.obj: CMakeFiles/task8.dir/flags.make
CMakeFiles/task8.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\dagge\CLionProjects\OOP\lab6\task8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/task8.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\task8.dir\main.cpp.obj -c C:\Users\dagge\CLionProjects\OOP\lab6\task8\main.cpp

CMakeFiles/task8.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task8.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\dagge\CLionProjects\OOP\lab6\task8\main.cpp > CMakeFiles\task8.dir\main.cpp.i

CMakeFiles/task8.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task8.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\dagge\CLionProjects\OOP\lab6\task8\main.cpp -o CMakeFiles\task8.dir\main.cpp.s

# Object files for target task8
task8_OBJECTS = \
"CMakeFiles/task8.dir/main.cpp.obj"

# External object files for target task8
task8_EXTERNAL_OBJECTS =

task8.exe: CMakeFiles/task8.dir/main.cpp.obj
task8.exe: CMakeFiles/task8.dir/build.make
task8.exe: CMakeFiles/task8.dir/linklibs.rsp
task8.exe: CMakeFiles/task8.dir/objects1.rsp
task8.exe: CMakeFiles/task8.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\dagge\CLionProjects\OOP\lab6\task8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable task8.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\task8.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/task8.dir/build: task8.exe

.PHONY : CMakeFiles/task8.dir/build

CMakeFiles/task8.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\task8.dir\cmake_clean.cmake
.PHONY : CMakeFiles/task8.dir/clean

CMakeFiles/task8.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\dagge\CLionProjects\OOP\lab6\task8 C:\Users\dagge\CLionProjects\OOP\lab6\task8 C:\Users\dagge\CLionProjects\OOP\lab6\task8\cmake-build-debug C:\Users\dagge\CLionProjects\OOP\lab6\task8\cmake-build-debug C:\Users\dagge\CLionProjects\OOP\lab6\task8\cmake-build-debug\CMakeFiles\task8.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/task8.dir/depend

