# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "E:\Program Files\JetBrains\CLion 2019.1.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "E:\Program Files\JetBrains\CLion 2019.1.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\DS\list-top2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\DS\list-top2\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/list_top2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/list_top2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/list_top2.dir/flags.make

CMakeFiles/list_top2.dir/main.c.obj: CMakeFiles/list_top2.dir/flags.make
CMakeFiles/list_top2.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\DS\list-top2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/list_top2.dir/main.c.obj"
	E:\PROGRA~1\Dev-Cpp\MinGW64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\list_top2.dir\main.c.obj   -c E:\DS\list-top2\main.c

CMakeFiles/list_top2.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/list_top2.dir/main.c.i"
	E:\PROGRA~1\Dev-Cpp\MinGW64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:\DS\list-top2\main.c > CMakeFiles\list_top2.dir\main.c.i

CMakeFiles/list_top2.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/list_top2.dir/main.c.s"
	E:\PROGRA~1\Dev-Cpp\MinGW64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:\DS\list-top2\main.c -o CMakeFiles\list_top2.dir\main.c.s

# Object files for target list_top2
list_top2_OBJECTS = \
"CMakeFiles/list_top2.dir/main.c.obj"

# External object files for target list_top2
list_top2_EXTERNAL_OBJECTS =

list_top2.exe: CMakeFiles/list_top2.dir/main.c.obj
list_top2.exe: CMakeFiles/list_top2.dir/build.make
list_top2.exe: CMakeFiles/list_top2.dir/linklibs.rsp
list_top2.exe: CMakeFiles/list_top2.dir/objects1.rsp
list_top2.exe: CMakeFiles/list_top2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\DS\list-top2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable list_top2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\list_top2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/list_top2.dir/build: list_top2.exe

.PHONY : CMakeFiles/list_top2.dir/build

CMakeFiles/list_top2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\list_top2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/list_top2.dir/clean

CMakeFiles/list_top2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\DS\list-top2 E:\DS\list-top2 E:\DS\list-top2\cmake-build-debug E:\DS\list-top2\cmake-build-debug E:\DS\list-top2\cmake-build-debug\CMakeFiles\list_top2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/list_top2.dir/depend
