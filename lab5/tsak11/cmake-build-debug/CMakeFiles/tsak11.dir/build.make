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
CMAKE_SOURCE_DIR = C:\Users\dagge\CLionProjects\OOP\lab5\tsak11

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\dagge\CLionProjects\OOP\lab5\tsak11\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/tsak11.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tsak11.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tsak11.dir/flags.make

CMakeFiles/tsak11.dir/main.cpp.obj: CMakeFiles/tsak11.dir/flags.make
CMakeFiles/tsak11.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\dagge\CLionProjects\OOP\lab5\tsak11\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tsak11.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\tsak11.dir\main.cpp.obj -c C:\Users\dagge\CLionProjects\OOP\lab5\tsak11\main.cpp

CMakeFiles/tsak11.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tsak11.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\dagge\CLionProjects\OOP\lab5\tsak11\main.cpp > CMakeFiles\tsak11.dir\main.cpp.i

CMakeFiles/tsak11.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tsak11.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\dagge\CLionProjects\OOP\lab5\tsak11\main.cpp -o CMakeFiles\tsak11.dir\main.cpp.s

# Object files for target tsak11
tsak11_OBJECTS = \
"CMakeFiles/tsak11.dir/main.cpp.obj"

# External object files for target tsak11
tsak11_EXTERNAL_OBJECTS =

tsak11.exe: CMakeFiles/tsak11.dir/main.cpp.obj
tsak11.exe: CMakeFiles/tsak11.dir/build.make
tsak11.exe: CMakeFiles/tsak11.dir/linklibs.rsp
tsak11.exe: CMakeFiles/tsak11.dir/objects1.rsp
tsak11.exe: CMakeFiles/tsak11.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\dagge\CLionProjects\OOP\lab5\tsak11\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tsak11.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\tsak11.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tsak11.dir/build: tsak11.exe

.PHONY : CMakeFiles/tsak11.dir/build

CMakeFiles/tsak11.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\tsak11.dir\cmake_clean.cmake
.PHONY : CMakeFiles/tsak11.dir/clean

CMakeFiles/tsak11.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\dagge\CLionProjects\OOP\lab5\tsak11 C:\Users\dagge\CLionProjects\OOP\lab5\tsak11 C:\Users\dagge\CLionProjects\OOP\lab5\tsak11\cmake-build-debug C:\Users\dagge\CLionProjects\OOP\lab5\tsak11\cmake-build-debug C:\Users\dagge\CLionProjects\OOP\lab5\tsak11\cmake-build-debug\CMakeFiles\tsak11.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tsak11.dir/depend

