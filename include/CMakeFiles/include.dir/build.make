# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ryan/Documents/projects/cpp/ToDo-List

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ryan/Documents/projects/cpp/ToDo-List

# Include any dependencies generated for this target.
include include/CMakeFiles/include.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include include/CMakeFiles/include.dir/compiler_depend.make

# Include the progress variables for this target.
include include/CMakeFiles/include.dir/progress.make

# Include the compile flags for this target's objects.
include include/CMakeFiles/include.dir/flags.make

include/CMakeFiles/include.dir/libconfig/lib/grammar.c.o: include/CMakeFiles/include.dir/flags.make
include/CMakeFiles/include.dir/libconfig/lib/grammar.c.o: include/libconfig/lib/grammar.c
include/CMakeFiles/include.dir/libconfig/lib/grammar.c.o: include/CMakeFiles/include.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ryan/Documents/projects/cpp/ToDo-List/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object include/CMakeFiles/include.dir/libconfig/lib/grammar.c.o"
	cd /home/ryan/Documents/projects/cpp/ToDo-List/include && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT include/CMakeFiles/include.dir/libconfig/lib/grammar.c.o -MF CMakeFiles/include.dir/libconfig/lib/grammar.c.o.d -o CMakeFiles/include.dir/libconfig/lib/grammar.c.o -c /home/ryan/Documents/projects/cpp/ToDo-List/include/libconfig/lib/grammar.c

include/CMakeFiles/include.dir/libconfig/lib/grammar.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/include.dir/libconfig/lib/grammar.c.i"
	cd /home/ryan/Documents/projects/cpp/ToDo-List/include && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ryan/Documents/projects/cpp/ToDo-List/include/libconfig/lib/grammar.c > CMakeFiles/include.dir/libconfig/lib/grammar.c.i

include/CMakeFiles/include.dir/libconfig/lib/grammar.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/include.dir/libconfig/lib/grammar.c.s"
	cd /home/ryan/Documents/projects/cpp/ToDo-List/include && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ryan/Documents/projects/cpp/ToDo-List/include/libconfig/lib/grammar.c -o CMakeFiles/include.dir/libconfig/lib/grammar.c.s

include/CMakeFiles/include.dir/libconfig/lib/libconfig.c.o: include/CMakeFiles/include.dir/flags.make
include/CMakeFiles/include.dir/libconfig/lib/libconfig.c.o: include/libconfig/lib/libconfig.c
include/CMakeFiles/include.dir/libconfig/lib/libconfig.c.o: include/CMakeFiles/include.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ryan/Documents/projects/cpp/ToDo-List/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object include/CMakeFiles/include.dir/libconfig/lib/libconfig.c.o"
	cd /home/ryan/Documents/projects/cpp/ToDo-List/include && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT include/CMakeFiles/include.dir/libconfig/lib/libconfig.c.o -MF CMakeFiles/include.dir/libconfig/lib/libconfig.c.o.d -o CMakeFiles/include.dir/libconfig/lib/libconfig.c.o -c /home/ryan/Documents/projects/cpp/ToDo-List/include/libconfig/lib/libconfig.c

include/CMakeFiles/include.dir/libconfig/lib/libconfig.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/include.dir/libconfig/lib/libconfig.c.i"
	cd /home/ryan/Documents/projects/cpp/ToDo-List/include && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ryan/Documents/projects/cpp/ToDo-List/include/libconfig/lib/libconfig.c > CMakeFiles/include.dir/libconfig/lib/libconfig.c.i

include/CMakeFiles/include.dir/libconfig/lib/libconfig.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/include.dir/libconfig/lib/libconfig.c.s"
	cd /home/ryan/Documents/projects/cpp/ToDo-List/include && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ryan/Documents/projects/cpp/ToDo-List/include/libconfig/lib/libconfig.c -o CMakeFiles/include.dir/libconfig/lib/libconfig.c.s

include/CMakeFiles/include.dir/libconfig/lib/libconfigcpp.c++.o: include/CMakeFiles/include.dir/flags.make
include/CMakeFiles/include.dir/libconfig/lib/libconfigcpp.c++.o: include/libconfig/lib/libconfigcpp.c++
include/CMakeFiles/include.dir/libconfig/lib/libconfigcpp.c++.o: include/CMakeFiles/include.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ryan/Documents/projects/cpp/ToDo-List/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object include/CMakeFiles/include.dir/libconfig/lib/libconfigcpp.c++.o"
	cd /home/ryan/Documents/projects/cpp/ToDo-List/include && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT include/CMakeFiles/include.dir/libconfig/lib/libconfigcpp.c++.o -MF CMakeFiles/include.dir/libconfig/lib/libconfigcpp.c++.o.d -o CMakeFiles/include.dir/libconfig/lib/libconfigcpp.c++.o -c /home/ryan/Documents/projects/cpp/ToDo-List/include/libconfig/lib/libconfigcpp.c++

include/CMakeFiles/include.dir/libconfig/lib/libconfigcpp.c++.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/include.dir/libconfig/lib/libconfigcpp.c++.i"
	cd /home/ryan/Documents/projects/cpp/ToDo-List/include && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ryan/Documents/projects/cpp/ToDo-List/include/libconfig/lib/libconfigcpp.c++ > CMakeFiles/include.dir/libconfig/lib/libconfigcpp.c++.i

include/CMakeFiles/include.dir/libconfig/lib/libconfigcpp.c++.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/include.dir/libconfig/lib/libconfigcpp.c++.s"
	cd /home/ryan/Documents/projects/cpp/ToDo-List/include && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ryan/Documents/projects/cpp/ToDo-List/include/libconfig/lib/libconfigcpp.c++ -o CMakeFiles/include.dir/libconfig/lib/libconfigcpp.c++.s

include/CMakeFiles/include.dir/libconfig/lib/scanctx.c.o: include/CMakeFiles/include.dir/flags.make
include/CMakeFiles/include.dir/libconfig/lib/scanctx.c.o: include/libconfig/lib/scanctx.c
include/CMakeFiles/include.dir/libconfig/lib/scanctx.c.o: include/CMakeFiles/include.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ryan/Documents/projects/cpp/ToDo-List/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object include/CMakeFiles/include.dir/libconfig/lib/scanctx.c.o"
	cd /home/ryan/Documents/projects/cpp/ToDo-List/include && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT include/CMakeFiles/include.dir/libconfig/lib/scanctx.c.o -MF CMakeFiles/include.dir/libconfig/lib/scanctx.c.o.d -o CMakeFiles/include.dir/libconfig/lib/scanctx.c.o -c /home/ryan/Documents/projects/cpp/ToDo-List/include/libconfig/lib/scanctx.c

include/CMakeFiles/include.dir/libconfig/lib/scanctx.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/include.dir/libconfig/lib/scanctx.c.i"
	cd /home/ryan/Documents/projects/cpp/ToDo-List/include && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ryan/Documents/projects/cpp/ToDo-List/include/libconfig/lib/scanctx.c > CMakeFiles/include.dir/libconfig/lib/scanctx.c.i

include/CMakeFiles/include.dir/libconfig/lib/scanctx.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/include.dir/libconfig/lib/scanctx.c.s"
	cd /home/ryan/Documents/projects/cpp/ToDo-List/include && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ryan/Documents/projects/cpp/ToDo-List/include/libconfig/lib/scanctx.c -o CMakeFiles/include.dir/libconfig/lib/scanctx.c.s

include/CMakeFiles/include.dir/libconfig/lib/scanner.c.o: include/CMakeFiles/include.dir/flags.make
include/CMakeFiles/include.dir/libconfig/lib/scanner.c.o: include/libconfig/lib/scanner.c
include/CMakeFiles/include.dir/libconfig/lib/scanner.c.o: include/CMakeFiles/include.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ryan/Documents/projects/cpp/ToDo-List/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object include/CMakeFiles/include.dir/libconfig/lib/scanner.c.o"
	cd /home/ryan/Documents/projects/cpp/ToDo-List/include && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT include/CMakeFiles/include.dir/libconfig/lib/scanner.c.o -MF CMakeFiles/include.dir/libconfig/lib/scanner.c.o.d -o CMakeFiles/include.dir/libconfig/lib/scanner.c.o -c /home/ryan/Documents/projects/cpp/ToDo-List/include/libconfig/lib/scanner.c

include/CMakeFiles/include.dir/libconfig/lib/scanner.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/include.dir/libconfig/lib/scanner.c.i"
	cd /home/ryan/Documents/projects/cpp/ToDo-List/include && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ryan/Documents/projects/cpp/ToDo-List/include/libconfig/lib/scanner.c > CMakeFiles/include.dir/libconfig/lib/scanner.c.i

include/CMakeFiles/include.dir/libconfig/lib/scanner.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/include.dir/libconfig/lib/scanner.c.s"
	cd /home/ryan/Documents/projects/cpp/ToDo-List/include && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ryan/Documents/projects/cpp/ToDo-List/include/libconfig/lib/scanner.c -o CMakeFiles/include.dir/libconfig/lib/scanner.c.s

include/CMakeFiles/include.dir/libconfig/lib/strbuf.c.o: include/CMakeFiles/include.dir/flags.make
include/CMakeFiles/include.dir/libconfig/lib/strbuf.c.o: include/libconfig/lib/strbuf.c
include/CMakeFiles/include.dir/libconfig/lib/strbuf.c.o: include/CMakeFiles/include.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ryan/Documents/projects/cpp/ToDo-List/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object include/CMakeFiles/include.dir/libconfig/lib/strbuf.c.o"
	cd /home/ryan/Documents/projects/cpp/ToDo-List/include && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT include/CMakeFiles/include.dir/libconfig/lib/strbuf.c.o -MF CMakeFiles/include.dir/libconfig/lib/strbuf.c.o.d -o CMakeFiles/include.dir/libconfig/lib/strbuf.c.o -c /home/ryan/Documents/projects/cpp/ToDo-List/include/libconfig/lib/strbuf.c

include/CMakeFiles/include.dir/libconfig/lib/strbuf.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/include.dir/libconfig/lib/strbuf.c.i"
	cd /home/ryan/Documents/projects/cpp/ToDo-List/include && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ryan/Documents/projects/cpp/ToDo-List/include/libconfig/lib/strbuf.c > CMakeFiles/include.dir/libconfig/lib/strbuf.c.i

include/CMakeFiles/include.dir/libconfig/lib/strbuf.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/include.dir/libconfig/lib/strbuf.c.s"
	cd /home/ryan/Documents/projects/cpp/ToDo-List/include && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ryan/Documents/projects/cpp/ToDo-List/include/libconfig/lib/strbuf.c -o CMakeFiles/include.dir/libconfig/lib/strbuf.c.s

include/CMakeFiles/include.dir/libconfig/lib/strvec.c.o: include/CMakeFiles/include.dir/flags.make
include/CMakeFiles/include.dir/libconfig/lib/strvec.c.o: include/libconfig/lib/strvec.c
include/CMakeFiles/include.dir/libconfig/lib/strvec.c.o: include/CMakeFiles/include.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ryan/Documents/projects/cpp/ToDo-List/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object include/CMakeFiles/include.dir/libconfig/lib/strvec.c.o"
	cd /home/ryan/Documents/projects/cpp/ToDo-List/include && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT include/CMakeFiles/include.dir/libconfig/lib/strvec.c.o -MF CMakeFiles/include.dir/libconfig/lib/strvec.c.o.d -o CMakeFiles/include.dir/libconfig/lib/strvec.c.o -c /home/ryan/Documents/projects/cpp/ToDo-List/include/libconfig/lib/strvec.c

include/CMakeFiles/include.dir/libconfig/lib/strvec.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/include.dir/libconfig/lib/strvec.c.i"
	cd /home/ryan/Documents/projects/cpp/ToDo-List/include && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ryan/Documents/projects/cpp/ToDo-List/include/libconfig/lib/strvec.c > CMakeFiles/include.dir/libconfig/lib/strvec.c.i

include/CMakeFiles/include.dir/libconfig/lib/strvec.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/include.dir/libconfig/lib/strvec.c.s"
	cd /home/ryan/Documents/projects/cpp/ToDo-List/include && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ryan/Documents/projects/cpp/ToDo-List/include/libconfig/lib/strvec.c -o CMakeFiles/include.dir/libconfig/lib/strvec.c.s

include/CMakeFiles/include.dir/libconfig/lib/util.c.o: include/CMakeFiles/include.dir/flags.make
include/CMakeFiles/include.dir/libconfig/lib/util.c.o: include/libconfig/lib/util.c
include/CMakeFiles/include.dir/libconfig/lib/util.c.o: include/CMakeFiles/include.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ryan/Documents/projects/cpp/ToDo-List/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object include/CMakeFiles/include.dir/libconfig/lib/util.c.o"
	cd /home/ryan/Documents/projects/cpp/ToDo-List/include && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT include/CMakeFiles/include.dir/libconfig/lib/util.c.o -MF CMakeFiles/include.dir/libconfig/lib/util.c.o.d -o CMakeFiles/include.dir/libconfig/lib/util.c.o -c /home/ryan/Documents/projects/cpp/ToDo-List/include/libconfig/lib/util.c

include/CMakeFiles/include.dir/libconfig/lib/util.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/include.dir/libconfig/lib/util.c.i"
	cd /home/ryan/Documents/projects/cpp/ToDo-List/include && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ryan/Documents/projects/cpp/ToDo-List/include/libconfig/lib/util.c > CMakeFiles/include.dir/libconfig/lib/util.c.i

include/CMakeFiles/include.dir/libconfig/lib/util.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/include.dir/libconfig/lib/util.c.s"
	cd /home/ryan/Documents/projects/cpp/ToDo-List/include && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ryan/Documents/projects/cpp/ToDo-List/include/libconfig/lib/util.c -o CMakeFiles/include.dir/libconfig/lib/util.c.s

include/CMakeFiles/include.dir/libconfig/lib/wincompat.c.o: include/CMakeFiles/include.dir/flags.make
include/CMakeFiles/include.dir/libconfig/lib/wincompat.c.o: include/libconfig/lib/wincompat.c
include/CMakeFiles/include.dir/libconfig/lib/wincompat.c.o: include/CMakeFiles/include.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ryan/Documents/projects/cpp/ToDo-List/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object include/CMakeFiles/include.dir/libconfig/lib/wincompat.c.o"
	cd /home/ryan/Documents/projects/cpp/ToDo-List/include && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT include/CMakeFiles/include.dir/libconfig/lib/wincompat.c.o -MF CMakeFiles/include.dir/libconfig/lib/wincompat.c.o.d -o CMakeFiles/include.dir/libconfig/lib/wincompat.c.o -c /home/ryan/Documents/projects/cpp/ToDo-List/include/libconfig/lib/wincompat.c

include/CMakeFiles/include.dir/libconfig/lib/wincompat.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/include.dir/libconfig/lib/wincompat.c.i"
	cd /home/ryan/Documents/projects/cpp/ToDo-List/include && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ryan/Documents/projects/cpp/ToDo-List/include/libconfig/lib/wincompat.c > CMakeFiles/include.dir/libconfig/lib/wincompat.c.i

include/CMakeFiles/include.dir/libconfig/lib/wincompat.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/include.dir/libconfig/lib/wincompat.c.s"
	cd /home/ryan/Documents/projects/cpp/ToDo-List/include && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ryan/Documents/projects/cpp/ToDo-List/include/libconfig/lib/wincompat.c -o CMakeFiles/include.dir/libconfig/lib/wincompat.c.s

# Object files for target include
include_OBJECTS = \
"CMakeFiles/include.dir/libconfig/lib/grammar.c.o" \
"CMakeFiles/include.dir/libconfig/lib/libconfig.c.o" \
"CMakeFiles/include.dir/libconfig/lib/libconfigcpp.c++.o" \
"CMakeFiles/include.dir/libconfig/lib/scanctx.c.o" \
"CMakeFiles/include.dir/libconfig/lib/scanner.c.o" \
"CMakeFiles/include.dir/libconfig/lib/strbuf.c.o" \
"CMakeFiles/include.dir/libconfig/lib/strvec.c.o" \
"CMakeFiles/include.dir/libconfig/lib/util.c.o" \
"CMakeFiles/include.dir/libconfig/lib/wincompat.c.o"

# External object files for target include
include_EXTERNAL_OBJECTS =

include/libinclude.a: include/CMakeFiles/include.dir/libconfig/lib/grammar.c.o
include/libinclude.a: include/CMakeFiles/include.dir/libconfig/lib/libconfig.c.o
include/libinclude.a: include/CMakeFiles/include.dir/libconfig/lib/libconfigcpp.c++.o
include/libinclude.a: include/CMakeFiles/include.dir/libconfig/lib/scanctx.c.o
include/libinclude.a: include/CMakeFiles/include.dir/libconfig/lib/scanner.c.o
include/libinclude.a: include/CMakeFiles/include.dir/libconfig/lib/strbuf.c.o
include/libinclude.a: include/CMakeFiles/include.dir/libconfig/lib/strvec.c.o
include/libinclude.a: include/CMakeFiles/include.dir/libconfig/lib/util.c.o
include/libinclude.a: include/CMakeFiles/include.dir/libconfig/lib/wincompat.c.o
include/libinclude.a: include/CMakeFiles/include.dir/build.make
include/libinclude.a: include/CMakeFiles/include.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/ryan/Documents/projects/cpp/ToDo-List/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX static library libinclude.a"
	cd /home/ryan/Documents/projects/cpp/ToDo-List/include && $(CMAKE_COMMAND) -P CMakeFiles/include.dir/cmake_clean_target.cmake
	cd /home/ryan/Documents/projects/cpp/ToDo-List/include && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/include.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
include/CMakeFiles/include.dir/build: include/libinclude.a
.PHONY : include/CMakeFiles/include.dir/build

include/CMakeFiles/include.dir/clean:
	cd /home/ryan/Documents/projects/cpp/ToDo-List/include && $(CMAKE_COMMAND) -P CMakeFiles/include.dir/cmake_clean.cmake
.PHONY : include/CMakeFiles/include.dir/clean

include/CMakeFiles/include.dir/depend:
	cd /home/ryan/Documents/projects/cpp/ToDo-List && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ryan/Documents/projects/cpp/ToDo-List /home/ryan/Documents/projects/cpp/ToDo-List/include /home/ryan/Documents/projects/cpp/ToDo-List /home/ryan/Documents/projects/cpp/ToDo-List/include /home/ryan/Documents/projects/cpp/ToDo-List/include/CMakeFiles/include.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : include/CMakeFiles/include.dir/depend

