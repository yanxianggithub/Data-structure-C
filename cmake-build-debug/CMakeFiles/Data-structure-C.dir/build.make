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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\asus\Documents\GitHub\Data-structure-C

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\asus\Documents\GitHub\Data-structure-C\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Data-structure-C.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Data-structure-C.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Data-structure-C.dir/flags.make

CMakeFiles/Data-structure-C.dir/99-test/2.1.c.obj: CMakeFiles/Data-structure-C.dir/flags.make
CMakeFiles/Data-structure-C.dir/99-test/2.1.c.obj: ../99-test/2.1.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\asus\Documents\GitHub\Data-structure-C\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Data-structure-C.dir/99-test/2.1.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Data-structure-C.dir\99-test\2.1.c.obj   -c C:\Users\asus\Documents\GitHub\Data-structure-C\99-test\2.1.c

CMakeFiles/Data-structure-C.dir/99-test/2.1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Data-structure-C.dir/99-test/2.1.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\asus\Documents\GitHub\Data-structure-C\99-test\2.1.c > CMakeFiles\Data-structure-C.dir\99-test\2.1.c.i

CMakeFiles/Data-structure-C.dir/99-test/2.1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Data-structure-C.dir/99-test/2.1.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\asus\Documents\GitHub\Data-structure-C\99-test\2.1.c -o CMakeFiles\Data-structure-C.dir\99-test\2.1.c.s

CMakeFiles/Data-structure-C.dir/99-test/5.1.c.obj: CMakeFiles/Data-structure-C.dir/flags.make
CMakeFiles/Data-structure-C.dir/99-test/5.1.c.obj: ../99-test/5.1.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\asus\Documents\GitHub\Data-structure-C\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Data-structure-C.dir/99-test/5.1.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Data-structure-C.dir\99-test\5.1.c.obj   -c C:\Users\asus\Documents\GitHub\Data-structure-C\99-test\5.1.c

CMakeFiles/Data-structure-C.dir/99-test/5.1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Data-structure-C.dir/99-test/5.1.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\asus\Documents\GitHub\Data-structure-C\99-test\5.1.c > CMakeFiles\Data-structure-C.dir\99-test\5.1.c.i

CMakeFiles/Data-structure-C.dir/99-test/5.1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Data-structure-C.dir/99-test/5.1.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\asus\Documents\GitHub\Data-structure-C\99-test\5.1.c -o CMakeFiles\Data-structure-C.dir\99-test\5.1.c.s

# Object files for target Data-structure-C
Data__structure__C_OBJECTS = \
"CMakeFiles/Data-structure-C.dir/99-test/2.1.c.obj" \
"CMakeFiles/Data-structure-C.dir/99-test/5.1.c.obj"

# External object files for target Data-structure-C
Data__structure__C_EXTERNAL_OBJECTS =

Data-structure-C.exe: CMakeFiles/Data-structure-C.dir/99-test/2.1.c.obj
Data-structure-C.exe: CMakeFiles/Data-structure-C.dir/99-test/5.1.c.obj
Data-structure-C.exe: CMakeFiles/Data-structure-C.dir/build.make
Data-structure-C.exe: CMakeFiles/Data-structure-C.dir/linklibs.rsp
Data-structure-C.exe: CMakeFiles/Data-structure-C.dir/objects1.rsp
Data-structure-C.exe: CMakeFiles/Data-structure-C.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\asus\Documents\GitHub\Data-structure-C\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable Data-structure-C.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Data-structure-C.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Data-structure-C.dir/build: Data-structure-C.exe

.PHONY : CMakeFiles/Data-structure-C.dir/build

CMakeFiles/Data-structure-C.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Data-structure-C.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Data-structure-C.dir/clean

CMakeFiles/Data-structure-C.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\asus\Documents\GitHub\Data-structure-C C:\Users\asus\Documents\GitHub\Data-structure-C C:\Users\asus\Documents\GitHub\Data-structure-C\cmake-build-debug C:\Users\asus\Documents\GitHub\Data-structure-C\cmake-build-debug C:\Users\asus\Documents\GitHub\Data-structure-C\cmake-build-debug\CMakeFiles\Data-structure-C.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Data-structure-C.dir/depend

