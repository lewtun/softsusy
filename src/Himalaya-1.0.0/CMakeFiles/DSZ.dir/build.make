# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/bca20/code/softsusy/src/Himalaya-1.0.0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bca20/code/softsusy/src/Himalaya-1.0.0

# Include any dependencies generated for this target.
include CMakeFiles/DSZ.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DSZ.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DSZ.dir/flags.make

CMakeFiles/DSZ.dir/source/include/mh2l/functs.f.o: CMakeFiles/DSZ.dir/flags.make
CMakeFiles/DSZ.dir/source/include/mh2l/functs.f.o: source/include/mh2l/functs.f
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bca20/code/softsusy/src/Himalaya-1.0.0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building Fortran object CMakeFiles/DSZ.dir/source/include/mh2l/functs.f.o"
	/usr/bin/gfortran  $(Fortran_DEFINES) $(Fortran_INCLUDES) $(Fortran_FLAGS) -c /home/bca20/code/softsusy/src/Himalaya-1.0.0/source/include/mh2l/functs.f -o CMakeFiles/DSZ.dir/source/include/mh2l/functs.f.o

CMakeFiles/DSZ.dir/source/include/mh2l/functs.f.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing Fortran source to CMakeFiles/DSZ.dir/source/include/mh2l/functs.f.i"
	/usr/bin/gfortran  $(Fortran_DEFINES) $(Fortran_INCLUDES) $(Fortran_FLAGS) -E /home/bca20/code/softsusy/src/Himalaya-1.0.0/source/include/mh2l/functs.f > CMakeFiles/DSZ.dir/source/include/mh2l/functs.f.i

CMakeFiles/DSZ.dir/source/include/mh2l/functs.f.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling Fortran source to assembly CMakeFiles/DSZ.dir/source/include/mh2l/functs.f.s"
	/usr/bin/gfortran  $(Fortran_DEFINES) $(Fortran_INCLUDES) $(Fortran_FLAGS) -S /home/bca20/code/softsusy/src/Himalaya-1.0.0/source/include/mh2l/functs.f -o CMakeFiles/DSZ.dir/source/include/mh2l/functs.f.s

CMakeFiles/DSZ.dir/source/include/mh2l/functs.f.o.requires:

.PHONY : CMakeFiles/DSZ.dir/source/include/mh2l/functs.f.o.requires

CMakeFiles/DSZ.dir/source/include/mh2l/functs.f.o.provides: CMakeFiles/DSZ.dir/source/include/mh2l/functs.f.o.requires
	$(MAKE) -f CMakeFiles/DSZ.dir/build.make CMakeFiles/DSZ.dir/source/include/mh2l/functs.f.o.provides.build
.PHONY : CMakeFiles/DSZ.dir/source/include/mh2l/functs.f.o.provides

CMakeFiles/DSZ.dir/source/include/mh2l/functs.f.o.provides.build: CMakeFiles/DSZ.dir/source/include/mh2l/functs.f.o


CMakeFiles/DSZ.dir/source/include/mh2l/DSZHiggs.f.o: CMakeFiles/DSZ.dir/flags.make
CMakeFiles/DSZ.dir/source/include/mh2l/DSZHiggs.f.o: source/include/mh2l/DSZHiggs.f
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bca20/code/softsusy/src/Himalaya-1.0.0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building Fortran object CMakeFiles/DSZ.dir/source/include/mh2l/DSZHiggs.f.o"
	/usr/bin/gfortran  $(Fortran_DEFINES) $(Fortran_INCLUDES) $(Fortran_FLAGS) -c /home/bca20/code/softsusy/src/Himalaya-1.0.0/source/include/mh2l/DSZHiggs.f -o CMakeFiles/DSZ.dir/source/include/mh2l/DSZHiggs.f.o

CMakeFiles/DSZ.dir/source/include/mh2l/DSZHiggs.f.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing Fortran source to CMakeFiles/DSZ.dir/source/include/mh2l/DSZHiggs.f.i"
	/usr/bin/gfortran  $(Fortran_DEFINES) $(Fortran_INCLUDES) $(Fortran_FLAGS) -E /home/bca20/code/softsusy/src/Himalaya-1.0.0/source/include/mh2l/DSZHiggs.f > CMakeFiles/DSZ.dir/source/include/mh2l/DSZHiggs.f.i

CMakeFiles/DSZ.dir/source/include/mh2l/DSZHiggs.f.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling Fortran source to assembly CMakeFiles/DSZ.dir/source/include/mh2l/DSZHiggs.f.s"
	/usr/bin/gfortran  $(Fortran_DEFINES) $(Fortran_INCLUDES) $(Fortran_FLAGS) -S /home/bca20/code/softsusy/src/Himalaya-1.0.0/source/include/mh2l/DSZHiggs.f -o CMakeFiles/DSZ.dir/source/include/mh2l/DSZHiggs.f.s

CMakeFiles/DSZ.dir/source/include/mh2l/DSZHiggs.f.o.requires:

.PHONY : CMakeFiles/DSZ.dir/source/include/mh2l/DSZHiggs.f.o.requires

CMakeFiles/DSZ.dir/source/include/mh2l/DSZHiggs.f.o.provides: CMakeFiles/DSZ.dir/source/include/mh2l/DSZHiggs.f.o.requires
	$(MAKE) -f CMakeFiles/DSZ.dir/build.make CMakeFiles/DSZ.dir/source/include/mh2l/DSZHiggs.f.o.provides.build
.PHONY : CMakeFiles/DSZ.dir/source/include/mh2l/DSZHiggs.f.o.provides

CMakeFiles/DSZ.dir/source/include/mh2l/DSZHiggs.f.o.provides.build: CMakeFiles/DSZ.dir/source/include/mh2l/DSZHiggs.f.o


# Object files for target DSZ
DSZ_OBJECTS = \
"CMakeFiles/DSZ.dir/source/include/mh2l/functs.f.o" \
"CMakeFiles/DSZ.dir/source/include/mh2l/DSZHiggs.f.o"

# External object files for target DSZ
DSZ_EXTERNAL_OBJECTS =

libDSZ.a: CMakeFiles/DSZ.dir/source/include/mh2l/functs.f.o
libDSZ.a: CMakeFiles/DSZ.dir/source/include/mh2l/DSZHiggs.f.o
libDSZ.a: CMakeFiles/DSZ.dir/build.make
libDSZ.a: CMakeFiles/DSZ.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bca20/code/softsusy/src/Himalaya-1.0.0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking Fortran static library libDSZ.a"
	$(CMAKE_COMMAND) -P CMakeFiles/DSZ.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DSZ.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DSZ.dir/build: libDSZ.a

.PHONY : CMakeFiles/DSZ.dir/build

CMakeFiles/DSZ.dir/requires: CMakeFiles/DSZ.dir/source/include/mh2l/functs.f.o.requires
CMakeFiles/DSZ.dir/requires: CMakeFiles/DSZ.dir/source/include/mh2l/DSZHiggs.f.o.requires

.PHONY : CMakeFiles/DSZ.dir/requires

CMakeFiles/DSZ.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DSZ.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DSZ.dir/clean

CMakeFiles/DSZ.dir/depend:
	cd /home/bca20/code/softsusy/src/Himalaya-1.0.0 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bca20/code/softsusy/src/Himalaya-1.0.0 /home/bca20/code/softsusy/src/Himalaya-1.0.0 /home/bca20/code/softsusy/src/Himalaya-1.0.0 /home/bca20/code/softsusy/src/Himalaya-1.0.0 /home/bca20/code/softsusy/src/Himalaya-1.0.0/CMakeFiles/DSZ.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DSZ.dir/depend

