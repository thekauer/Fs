# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.11

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
CMAKE_SOURCE_DIR = /home/thekauer/Documents/fs

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/thekauer/Documents/fs/build

# Include any dependencies generated for this target.
include CMakeFiles/fs.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/fs.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fs.dir/flags.make

CMakeFiles/fs.dir/main.cpp.o: CMakeFiles/fs.dir/flags.make
CMakeFiles/fs.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/thekauer/Documents/fs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/fs.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fs.dir/main.cpp.o -c /home/thekauer/Documents/fs/main.cpp

CMakeFiles/fs.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fs.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/thekauer/Documents/fs/main.cpp > CMakeFiles/fs.dir/main.cpp.i

CMakeFiles/fs.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fs.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/thekauer/Documents/fs/main.cpp -o CMakeFiles/fs.dir/main.cpp.s

CMakeFiles/fs.dir/compiler.cpp.o: CMakeFiles/fs.dir/flags.make
CMakeFiles/fs.dir/compiler.cpp.o: ../compiler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/thekauer/Documents/fs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/fs.dir/compiler.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fs.dir/compiler.cpp.o -c /home/thekauer/Documents/fs/compiler.cpp

CMakeFiles/fs.dir/compiler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fs.dir/compiler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/thekauer/Documents/fs/compiler.cpp > CMakeFiles/fs.dir/compiler.cpp.i

CMakeFiles/fs.dir/compiler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fs.dir/compiler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/thekauer/Documents/fs/compiler.cpp -o CMakeFiles/fs.dir/compiler.cpp.s

CMakeFiles/fs.dir/errcodes.cpp.o: CMakeFiles/fs.dir/flags.make
CMakeFiles/fs.dir/errcodes.cpp.o: ../errcodes.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/thekauer/Documents/fs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/fs.dir/errcodes.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fs.dir/errcodes.cpp.o -c /home/thekauer/Documents/fs/errcodes.cpp

CMakeFiles/fs.dir/errcodes.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fs.dir/errcodes.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/thekauer/Documents/fs/errcodes.cpp > CMakeFiles/fs.dir/errcodes.cpp.i

CMakeFiles/fs.dir/errcodes.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fs.dir/errcodes.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/thekauer/Documents/fs/errcodes.cpp -o CMakeFiles/fs.dir/errcodes.cpp.s

CMakeFiles/fs.dir/hashed_string.cpp.o: CMakeFiles/fs.dir/flags.make
CMakeFiles/fs.dir/hashed_string.cpp.o: ../hashed_string.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/thekauer/Documents/fs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/fs.dir/hashed_string.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fs.dir/hashed_string.cpp.o -c /home/thekauer/Documents/fs/hashed_string.cpp

CMakeFiles/fs.dir/hashed_string.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fs.dir/hashed_string.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/thekauer/Documents/fs/hashed_string.cpp > CMakeFiles/fs.dir/hashed_string.cpp.i

CMakeFiles/fs.dir/hashed_string.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fs.dir/hashed_string.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/thekauer/Documents/fs/hashed_string.cpp -o CMakeFiles/fs.dir/hashed_string.cpp.s

CMakeFiles/fs.dir/lex.cpp.o: CMakeFiles/fs.dir/flags.make
CMakeFiles/fs.dir/lex.cpp.o: ../lex.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/thekauer/Documents/fs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/fs.dir/lex.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fs.dir/lex.cpp.o -c /home/thekauer/Documents/fs/lex.cpp

CMakeFiles/fs.dir/lex.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fs.dir/lex.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/thekauer/Documents/fs/lex.cpp > CMakeFiles/fs.dir/lex.cpp.i

CMakeFiles/fs.dir/lex.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fs.dir/lex.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/thekauer/Documents/fs/lex.cpp -o CMakeFiles/fs.dir/lex.cpp.s

CMakeFiles/fs.dir/parser.cpp.o: CMakeFiles/fs.dir/flags.make
CMakeFiles/fs.dir/parser.cpp.o: ../parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/thekauer/Documents/fs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/fs.dir/parser.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fs.dir/parser.cpp.o -c /home/thekauer/Documents/fs/parser.cpp

CMakeFiles/fs.dir/parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fs.dir/parser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/thekauer/Documents/fs/parser.cpp > CMakeFiles/fs.dir/parser.cpp.i

CMakeFiles/fs.dir/parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fs.dir/parser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/thekauer/Documents/fs/parser.cpp -o CMakeFiles/fs.dir/parser.cpp.s

CMakeFiles/fs.dir/sources.cpp.o: CMakeFiles/fs.dir/flags.make
CMakeFiles/fs.dir/sources.cpp.o: ../sources.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/thekauer/Documents/fs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/fs.dir/sources.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fs.dir/sources.cpp.o -c /home/thekauer/Documents/fs/sources.cpp

CMakeFiles/fs.dir/sources.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fs.dir/sources.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/thekauer/Documents/fs/sources.cpp > CMakeFiles/fs.dir/sources.cpp.i

CMakeFiles/fs.dir/sources.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fs.dir/sources.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/thekauer/Documents/fs/sources.cpp -o CMakeFiles/fs.dir/sources.cpp.s

# Object files for target fs
fs_OBJECTS = \
"CMakeFiles/fs.dir/main.cpp.o" \
"CMakeFiles/fs.dir/compiler.cpp.o" \
"CMakeFiles/fs.dir/errcodes.cpp.o" \
"CMakeFiles/fs.dir/hashed_string.cpp.o" \
"CMakeFiles/fs.dir/lex.cpp.o" \
"CMakeFiles/fs.dir/parser.cpp.o" \
"CMakeFiles/fs.dir/sources.cpp.o"

# External object files for target fs
fs_EXTERNAL_OBJECTS =

fs: CMakeFiles/fs.dir/main.cpp.o
fs: CMakeFiles/fs.dir/compiler.cpp.o
fs: CMakeFiles/fs.dir/errcodes.cpp.o
fs: CMakeFiles/fs.dir/hashed_string.cpp.o
fs: CMakeFiles/fs.dir/lex.cpp.o
fs: CMakeFiles/fs.dir/parser.cpp.o
fs: CMakeFiles/fs.dir/sources.cpp.o
fs: CMakeFiles/fs.dir/build.make
fs: CMakeFiles/fs.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/thekauer/Documents/fs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable fs"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fs.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fs.dir/build: fs

.PHONY : CMakeFiles/fs.dir/build

CMakeFiles/fs.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/fs.dir/cmake_clean.cmake
.PHONY : CMakeFiles/fs.dir/clean

CMakeFiles/fs.dir/depend:
	cd /home/thekauer/Documents/fs/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/thekauer/Documents/fs /home/thekauer/Documents/fs /home/thekauer/Documents/fs/build /home/thekauer/Documents/fs/build /home/thekauer/Documents/fs/build/CMakeFiles/fs.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/fs.dir/depend

