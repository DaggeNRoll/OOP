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
CMAKE_SOURCE_DIR = C:\Users\dagge\CLionProjects\OOP\lab8\tsk7

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\dagge\CLionProjects\OOP\lab8\tsk7\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/tsk7.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tsk7.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tsk7.dir/flags.make

CMakeFiles/tsk7.dir/main.cpp.obj: CMakeFiles/tsk7.dir/flags.make
CMakeFiles/tsk7.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\dagge\CLionProjects\OOP\lab8\tsk7\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tsk7.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\tsk7.dir\main.cpp.obj -c C:\Users\dagge\CLionProjects\OOP\lab8\tsk7\main.cpp

CMakeFiles/tsk7.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tsk7.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\dagge\CLionProjects\OOP\lab8\tsk7\main.cpp > CMakeFiles\tsk7.dir\main.cpp.i

CMakeFiles/tsk7.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tsk7.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\dagge\CLionProjects\OOP\lab8\tsk7\main.cpp -o CMakeFiles\tsk7.dir\main.cpp.s

# Object files for target tsk7
tsk7_OBJECTS = \
"CMakeFiles/tsk7.dir/main.cpp.obj"

# External object files for target tsk7
tsk7_EXTERNAL_OBJECTS =

tsk7.exe: CMakeFiles/tsk7.dir/main.cpp.obj
tsk7.exe: CMakeFiles/tsk7.dir/build.make
tsk7.exe: CMakeFiles/tsk7.dir/linklibs.rsp
tsk7.exe: CMakeFiles/tsk7.dir/objects1.rsp
tsk7.exe: CMakeFiles/tsk7.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\dagge\CLionProjects\OOP\lab8\tsk7\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tsk7.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\tsk7.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tsk7.dir/build: tsk7.exe

.PHONY : CMakeFiles/tsk7.dir/build

CMakeFiles/tsk7.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\tsk7.dir\cmake_clean.cmake
.PHONY : CMakeFiles/tsk7.dir/clean

CMakeFiles/tsk7.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\dagge\CLionProjects\OOP\lab8\tsk7 C:\Users\dagge\CLionProjects\OOP\lab8\tsk7 C:\Users\dagge\CLionProjects\OOP\lab8\tsk7\cmake-build-debug C:\Users\dagge\CLionProjects\OOP\lab8\tsk7\cmake-build-debug C:\Users\dagge\CLionProjects\OOP\lab8\tsk7\cmake-build-debug\CMakeFiles\tsk7.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tsk7.dir/depend

