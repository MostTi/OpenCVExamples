# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/teemo/openCV_ws/overlay

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/teemo/openCV_ws/overlay

# Include any dependencies generated for this target.
include CMakeFiles/overlay.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/overlay.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/overlay.dir/flags.make

CMakeFiles/overlay.dir/overlay.cpp.o: CMakeFiles/overlay.dir/flags.make
CMakeFiles/overlay.dir/overlay.cpp.o: overlay.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/teemo/openCV_ws/overlay/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/overlay.dir/overlay.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/overlay.dir/overlay.cpp.o -c /home/teemo/openCV_ws/overlay/overlay.cpp

CMakeFiles/overlay.dir/overlay.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/overlay.dir/overlay.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/teemo/openCV_ws/overlay/overlay.cpp > CMakeFiles/overlay.dir/overlay.cpp.i

CMakeFiles/overlay.dir/overlay.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/overlay.dir/overlay.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/teemo/openCV_ws/overlay/overlay.cpp -o CMakeFiles/overlay.dir/overlay.cpp.s

CMakeFiles/overlay.dir/overlay.cpp.o.requires:

.PHONY : CMakeFiles/overlay.dir/overlay.cpp.o.requires

CMakeFiles/overlay.dir/overlay.cpp.o.provides: CMakeFiles/overlay.dir/overlay.cpp.o.requires
	$(MAKE) -f CMakeFiles/overlay.dir/build.make CMakeFiles/overlay.dir/overlay.cpp.o.provides.build
.PHONY : CMakeFiles/overlay.dir/overlay.cpp.o.provides

CMakeFiles/overlay.dir/overlay.cpp.o.provides.build: CMakeFiles/overlay.dir/overlay.cpp.o


CMakeFiles/overlay.dir/home/teemo/openCV_ws/rdscp/crdtscp.cpp.o: CMakeFiles/overlay.dir/flags.make
CMakeFiles/overlay.dir/home/teemo/openCV_ws/rdscp/crdtscp.cpp.o: /home/teemo/openCV_ws/rdscp/crdtscp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/teemo/openCV_ws/overlay/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/overlay.dir/home/teemo/openCV_ws/rdscp/crdtscp.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/overlay.dir/home/teemo/openCV_ws/rdscp/crdtscp.cpp.o -c /home/teemo/openCV_ws/rdscp/crdtscp.cpp

CMakeFiles/overlay.dir/home/teemo/openCV_ws/rdscp/crdtscp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/overlay.dir/home/teemo/openCV_ws/rdscp/crdtscp.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/teemo/openCV_ws/rdscp/crdtscp.cpp > CMakeFiles/overlay.dir/home/teemo/openCV_ws/rdscp/crdtscp.cpp.i

CMakeFiles/overlay.dir/home/teemo/openCV_ws/rdscp/crdtscp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/overlay.dir/home/teemo/openCV_ws/rdscp/crdtscp.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/teemo/openCV_ws/rdscp/crdtscp.cpp -o CMakeFiles/overlay.dir/home/teemo/openCV_ws/rdscp/crdtscp.cpp.s

CMakeFiles/overlay.dir/home/teemo/openCV_ws/rdscp/crdtscp.cpp.o.requires:

.PHONY : CMakeFiles/overlay.dir/home/teemo/openCV_ws/rdscp/crdtscp.cpp.o.requires

CMakeFiles/overlay.dir/home/teemo/openCV_ws/rdscp/crdtscp.cpp.o.provides: CMakeFiles/overlay.dir/home/teemo/openCV_ws/rdscp/crdtscp.cpp.o.requires
	$(MAKE) -f CMakeFiles/overlay.dir/build.make CMakeFiles/overlay.dir/home/teemo/openCV_ws/rdscp/crdtscp.cpp.o.provides.build
.PHONY : CMakeFiles/overlay.dir/home/teemo/openCV_ws/rdscp/crdtscp.cpp.o.provides

CMakeFiles/overlay.dir/home/teemo/openCV_ws/rdscp/crdtscp.cpp.o.provides.build: CMakeFiles/overlay.dir/home/teemo/openCV_ws/rdscp/crdtscp.cpp.o


# Object files for target overlay
overlay_OBJECTS = \
"CMakeFiles/overlay.dir/overlay.cpp.o" \
"CMakeFiles/overlay.dir/home/teemo/openCV_ws/rdscp/crdtscp.cpp.o"

# External object files for target overlay
overlay_EXTERNAL_OBJECTS =

overlay: CMakeFiles/overlay.dir/overlay.cpp.o
overlay: CMakeFiles/overlay.dir/home/teemo/openCV_ws/rdscp/crdtscp.cpp.o
overlay: CMakeFiles/overlay.dir/build.make
overlay: /usr/local/lib/libopencv_dnn.so.3.4.9
overlay: /usr/local/lib/libopencv_highgui.so.3.4.9
overlay: /usr/local/lib/libopencv_ml.so.3.4.9
overlay: /usr/local/lib/libopencv_objdetect.so.3.4.9
overlay: /usr/local/lib/libopencv_shape.so.3.4.9
overlay: /usr/local/lib/libopencv_stitching.so.3.4.9
overlay: /usr/local/lib/libopencv_superres.so.3.4.9
overlay: /usr/local/lib/libopencv_videostab.so.3.4.9
overlay: /usr/local/lib/libopencv_viz.so.3.4.9
overlay: /usr/local/lib/libopencv_calib3d.so.3.4.9
overlay: /usr/local/lib/libopencv_features2d.so.3.4.9
overlay: /usr/local/lib/libopencv_flann.so.3.4.9
overlay: /usr/local/lib/libopencv_photo.so.3.4.9
overlay: /usr/local/lib/libopencv_video.so.3.4.9
overlay: /usr/local/lib/libopencv_videoio.so.3.4.9
overlay: /usr/local/lib/libopencv_imgcodecs.so.3.4.9
overlay: /usr/local/lib/libopencv_imgproc.so.3.4.9
overlay: /usr/local/lib/libopencv_core.so.3.4.9
overlay: CMakeFiles/overlay.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/teemo/openCV_ws/overlay/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable overlay"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/overlay.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/overlay.dir/build: overlay

.PHONY : CMakeFiles/overlay.dir/build

CMakeFiles/overlay.dir/requires: CMakeFiles/overlay.dir/overlay.cpp.o.requires
CMakeFiles/overlay.dir/requires: CMakeFiles/overlay.dir/home/teemo/openCV_ws/rdscp/crdtscp.cpp.o.requires

.PHONY : CMakeFiles/overlay.dir/requires

CMakeFiles/overlay.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/overlay.dir/cmake_clean.cmake
.PHONY : CMakeFiles/overlay.dir/clean

CMakeFiles/overlay.dir/depend:
	cd /home/teemo/openCV_ws/overlay && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/teemo/openCV_ws/overlay /home/teemo/openCV_ws/overlay /home/teemo/openCV_ws/overlay /home/teemo/openCV_ws/overlay /home/teemo/openCV_ws/overlay/CMakeFiles/overlay.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/overlay.dir/depend

