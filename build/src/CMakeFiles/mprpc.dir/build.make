# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /home/robin/workplace/cmake-3.22.0-linux-x86_64/bin/cmake

# The command to remove a file.
RM = /home/robin/workplace/cmake-3.22.0-linux-x86_64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/robin/projects/MpRpc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/robin/projects/MpRpc/build

# Include any dependencies generated for this target.
include src/CMakeFiles/mprpc.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/mprpc.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/mprpc.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/mprpc.dir/flags.make

src/CMakeFiles/mprpc.dir/src/mprpcapplication.cpp.o: src/CMakeFiles/mprpc.dir/flags.make
src/CMakeFiles/mprpc.dir/src/mprpcapplication.cpp.o: ../src/src/mprpcapplication.cpp
src/CMakeFiles/mprpc.dir/src/mprpcapplication.cpp.o: src/CMakeFiles/mprpc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robin/projects/MpRpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/mprpc.dir/src/mprpcapplication.cpp.o"
	cd /home/robin/projects/MpRpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/mprpc.dir/src/mprpcapplication.cpp.o -MF CMakeFiles/mprpc.dir/src/mprpcapplication.cpp.o.d -o CMakeFiles/mprpc.dir/src/mprpcapplication.cpp.o -c /home/robin/projects/MpRpc/src/src/mprpcapplication.cpp

src/CMakeFiles/mprpc.dir/src/mprpcapplication.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mprpc.dir/src/mprpcapplication.cpp.i"
	cd /home/robin/projects/MpRpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robin/projects/MpRpc/src/src/mprpcapplication.cpp > CMakeFiles/mprpc.dir/src/mprpcapplication.cpp.i

src/CMakeFiles/mprpc.dir/src/mprpcapplication.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mprpc.dir/src/mprpcapplication.cpp.s"
	cd /home/robin/projects/MpRpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robin/projects/MpRpc/src/src/mprpcapplication.cpp -o CMakeFiles/mprpc.dir/src/mprpcapplication.cpp.s

src/CMakeFiles/mprpc.dir/src/mprpcconfig.cpp.o: src/CMakeFiles/mprpc.dir/flags.make
src/CMakeFiles/mprpc.dir/src/mprpcconfig.cpp.o: ../src/src/mprpcconfig.cpp
src/CMakeFiles/mprpc.dir/src/mprpcconfig.cpp.o: src/CMakeFiles/mprpc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robin/projects/MpRpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/mprpc.dir/src/mprpcconfig.cpp.o"
	cd /home/robin/projects/MpRpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/mprpc.dir/src/mprpcconfig.cpp.o -MF CMakeFiles/mprpc.dir/src/mprpcconfig.cpp.o.d -o CMakeFiles/mprpc.dir/src/mprpcconfig.cpp.o -c /home/robin/projects/MpRpc/src/src/mprpcconfig.cpp

src/CMakeFiles/mprpc.dir/src/mprpcconfig.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mprpc.dir/src/mprpcconfig.cpp.i"
	cd /home/robin/projects/MpRpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robin/projects/MpRpc/src/src/mprpcconfig.cpp > CMakeFiles/mprpc.dir/src/mprpcconfig.cpp.i

src/CMakeFiles/mprpc.dir/src/mprpcconfig.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mprpc.dir/src/mprpcconfig.cpp.s"
	cd /home/robin/projects/MpRpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robin/projects/MpRpc/src/src/mprpcconfig.cpp -o CMakeFiles/mprpc.dir/src/mprpcconfig.cpp.s

src/CMakeFiles/mprpc.dir/src/rpcprovider.cpp.o: src/CMakeFiles/mprpc.dir/flags.make
src/CMakeFiles/mprpc.dir/src/rpcprovider.cpp.o: ../src/src/rpcprovider.cpp
src/CMakeFiles/mprpc.dir/src/rpcprovider.cpp.o: src/CMakeFiles/mprpc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robin/projects/MpRpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/mprpc.dir/src/rpcprovider.cpp.o"
	cd /home/robin/projects/MpRpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/mprpc.dir/src/rpcprovider.cpp.o -MF CMakeFiles/mprpc.dir/src/rpcprovider.cpp.o.d -o CMakeFiles/mprpc.dir/src/rpcprovider.cpp.o -c /home/robin/projects/MpRpc/src/src/rpcprovider.cpp

src/CMakeFiles/mprpc.dir/src/rpcprovider.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mprpc.dir/src/rpcprovider.cpp.i"
	cd /home/robin/projects/MpRpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robin/projects/MpRpc/src/src/rpcprovider.cpp > CMakeFiles/mprpc.dir/src/rpcprovider.cpp.i

src/CMakeFiles/mprpc.dir/src/rpcprovider.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mprpc.dir/src/rpcprovider.cpp.s"
	cd /home/robin/projects/MpRpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robin/projects/MpRpc/src/src/rpcprovider.cpp -o CMakeFiles/mprpc.dir/src/rpcprovider.cpp.s

# Object files for target mprpc
mprpc_OBJECTS = \
"CMakeFiles/mprpc.dir/src/mprpcapplication.cpp.o" \
"CMakeFiles/mprpc.dir/src/mprpcconfig.cpp.o" \
"CMakeFiles/mprpc.dir/src/rpcprovider.cpp.o"

# External object files for target mprpc
mprpc_EXTERNAL_OBJECTS =

../lib/libmprpc.so: src/CMakeFiles/mprpc.dir/src/mprpcapplication.cpp.o
../lib/libmprpc.so: src/CMakeFiles/mprpc.dir/src/mprpcconfig.cpp.o
../lib/libmprpc.so: src/CMakeFiles/mprpc.dir/src/rpcprovider.cpp.o
../lib/libmprpc.so: src/CMakeFiles/mprpc.dir/build.make
../lib/libmprpc.so: src/CMakeFiles/mprpc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/robin/projects/MpRpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX shared library ../../lib/libmprpc.so"
	cd /home/robin/projects/MpRpc/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mprpc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/mprpc.dir/build: ../lib/libmprpc.so
.PHONY : src/CMakeFiles/mprpc.dir/build

src/CMakeFiles/mprpc.dir/clean:
	cd /home/robin/projects/MpRpc/build/src && $(CMAKE_COMMAND) -P CMakeFiles/mprpc.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/mprpc.dir/clean

src/CMakeFiles/mprpc.dir/depend:
	cd /home/robin/projects/MpRpc/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/robin/projects/MpRpc /home/robin/projects/MpRpc/src /home/robin/projects/MpRpc/build /home/robin/projects/MpRpc/build/src /home/robin/projects/MpRpc/build/src/CMakeFiles/mprpc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/mprpc.dir/depend

