# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Drive\Saxion\2.2 Cpp\1\guessGame"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Drive\Saxion\2.2 Cpp\1\guessGame\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/guessGame.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/guessGame.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/guessGame.dir/flags.make

CMakeFiles/guessGame.dir/main.cpp.obj: CMakeFiles/guessGame.dir/flags.make
CMakeFiles/guessGame.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Drive\Saxion\2.2 Cpp\1\guessGame\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/guessGame.dir/main.cpp.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\guessGame.dir\main.cpp.obj -c "C:\Drive\Saxion\2.2 Cpp\1\guessGame\main.cpp"

CMakeFiles/guessGame.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/guessGame.dir/main.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Drive\Saxion\2.2 Cpp\1\guessGame\main.cpp" > CMakeFiles\guessGame.dir\main.cpp.i

CMakeFiles/guessGame.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/guessGame.dir/main.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Drive\Saxion\2.2 Cpp\1\guessGame\main.cpp" -o CMakeFiles\guessGame.dir\main.cpp.s

# Object files for target guessGame
guessGame_OBJECTS = \
"CMakeFiles/guessGame.dir/main.cpp.obj"

# External object files for target guessGame
guessGame_EXTERNAL_OBJECTS =

guessGame.exe: CMakeFiles/guessGame.dir/main.cpp.obj
guessGame.exe: CMakeFiles/guessGame.dir/build.make
guessGame.exe: CMakeFiles/guessGame.dir/linklibs.rsp
guessGame.exe: CMakeFiles/guessGame.dir/objects1.rsp
guessGame.exe: CMakeFiles/guessGame.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Drive\Saxion\2.2 Cpp\1\guessGame\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable guessGame.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\guessGame.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/guessGame.dir/build: guessGame.exe

.PHONY : CMakeFiles/guessGame.dir/build

CMakeFiles/guessGame.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\guessGame.dir\cmake_clean.cmake
.PHONY : CMakeFiles/guessGame.dir/clean

CMakeFiles/guessGame.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Drive\Saxion\2.2 Cpp\1\guessGame" "C:\Drive\Saxion\2.2 Cpp\1\guessGame" "C:\Drive\Saxion\2.2 Cpp\1\guessGame\cmake-build-debug" "C:\Drive\Saxion\2.2 Cpp\1\guessGame\cmake-build-debug" "C:\Drive\Saxion\2.2 Cpp\1\guessGame\cmake-build-debug\CMakeFiles\guessGame.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/guessGame.dir/depend
