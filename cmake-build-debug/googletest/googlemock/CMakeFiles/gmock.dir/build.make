# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /opt/poky/1.7.3/sysroots/x86_64-pokysdk-linux/usr/bin/cmake

# The command to remove a file.
RM = /opt/poky/1.7.3/sysroots/x86_64-pokysdk-linux/usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ubuntu/serialproto

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/serialproto/cmake-build-debug

# Include any dependencies generated for this target.
include googletest/googlemock/CMakeFiles/gmock.dir/depend.make

# Include the progress variables for this target.
include googletest/googlemock/CMakeFiles/gmock.dir/progress.make

# Include the compile flags for this target's objects.
include googletest/googlemock/CMakeFiles/gmock.dir/flags.make

googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o: googletest/googlemock/CMakeFiles/gmock.dir/flags.make
googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o: ../googletest/googlemock/src/gmock-all.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ubuntu/serialproto/cmake-build-debug/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o"
	cd /home/ubuntu/serialproto/cmake-build-debug/googletest/googlemock && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/gmock.dir/src/gmock-all.cc.o -c /home/ubuntu/serialproto/googletest/googlemock/src/gmock-all.cc

googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmock.dir/src/gmock-all.cc.i"
	cd /home/ubuntu/serialproto/cmake-build-debug/googletest/googlemock && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ubuntu/serialproto/googletest/googlemock/src/gmock-all.cc > CMakeFiles/gmock.dir/src/gmock-all.cc.i

googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmock.dir/src/gmock-all.cc.s"
	cd /home/ubuntu/serialproto/cmake-build-debug/googletest/googlemock && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ubuntu/serialproto/googletest/googlemock/src/gmock-all.cc -o CMakeFiles/gmock.dir/src/gmock-all.cc.s

googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.requires:
.PHONY : googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.requires

googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.provides: googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.requires
	$(MAKE) -f googletest/googlemock/CMakeFiles/gmock.dir/build.make googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.provides.build
.PHONY : googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.provides

googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.provides.build: googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o

# Object files for target gmock
gmock_OBJECTS = \
"CMakeFiles/gmock.dir/src/gmock-all.cc.o"

# External object files for target gmock
gmock_EXTERNAL_OBJECTS =

lib/libgmockd.a: googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o
lib/libgmockd.a: googletest/googlemock/CMakeFiles/gmock.dir/build.make
lib/libgmockd.a: googletest/googlemock/CMakeFiles/gmock.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library ../../lib/libgmockd.a"
	cd /home/ubuntu/serialproto/cmake-build-debug/googletest/googlemock && $(CMAKE_COMMAND) -P CMakeFiles/gmock.dir/cmake_clean_target.cmake
	cd /home/ubuntu/serialproto/cmake-build-debug/googletest/googlemock && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gmock.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
googletest/googlemock/CMakeFiles/gmock.dir/build: lib/libgmockd.a
.PHONY : googletest/googlemock/CMakeFiles/gmock.dir/build

googletest/googlemock/CMakeFiles/gmock.dir/requires: googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.requires
.PHONY : googletest/googlemock/CMakeFiles/gmock.dir/requires

googletest/googlemock/CMakeFiles/gmock.dir/clean:
	cd /home/ubuntu/serialproto/cmake-build-debug/googletest/googlemock && $(CMAKE_COMMAND) -P CMakeFiles/gmock.dir/cmake_clean.cmake
.PHONY : googletest/googlemock/CMakeFiles/gmock.dir/clean

googletest/googlemock/CMakeFiles/gmock.dir/depend:
	cd /home/ubuntu/serialproto/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/serialproto /home/ubuntu/serialproto/googletest/googlemock /home/ubuntu/serialproto/cmake-build-debug /home/ubuntu/serialproto/cmake-build-debug/googletest/googlemock /home/ubuntu/serialproto/cmake-build-debug/googletest/googlemock/CMakeFiles/gmock.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : googletest/googlemock/CMakeFiles/gmock.dir/depend
