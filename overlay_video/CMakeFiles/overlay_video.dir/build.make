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
CMAKE_SOURCE_DIR = /home/teemo/openCV_ws/overlay_video

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/teemo/openCV_ws/overlay_video

# Include any dependencies generated for this target.
include CMakeFiles/overlay_video.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/overlay_video.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/overlay_video.dir/flags.make

CMakeFiles/overlay_video.dir/overlay_video.cpp.o: CMakeFiles/overlay_video.dir/flags.make
CMakeFiles/overlay_video.dir/overlay_video.cpp.o: overlay_video.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/teemo/openCV_ws/overlay_video/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/overlay_video.dir/overlay_video.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/overlay_video.dir/overlay_video.cpp.o -c /home/teemo/openCV_ws/overlay_video/overlay_video.cpp

CMakeFiles/overlay_video.dir/overlay_video.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/overlay_video.dir/overlay_video.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/teemo/openCV_ws/overlay_video/overlay_video.cpp > CMakeFiles/overlay_video.dir/overlay_video.cpp.i

CMakeFiles/overlay_video.dir/overlay_video.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/overlay_video.dir/overlay_video.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/teemo/openCV_ws/overlay_video/overlay_video.cpp -o CMakeFiles/overlay_video.dir/overlay_video.cpp.s

CMakeFiles/overlay_video.dir/overlay_video.cpp.o.requires:

.PHONY : CMakeFiles/overlay_video.dir/overlay_video.cpp.o.requires

CMakeFiles/overlay_video.dir/overlay_video.cpp.o.provides: CMakeFiles/overlay_video.dir/overlay_video.cpp.o.requires
	$(MAKE) -f CMakeFiles/overlay_video.dir/build.make CMakeFiles/overlay_video.dir/overlay_video.cpp.o.provides.build
.PHONY : CMakeFiles/overlay_video.dir/overlay_video.cpp.o.provides

CMakeFiles/overlay_video.dir/overlay_video.cpp.o.provides.build: CMakeFiles/overlay_video.dir/overlay_video.cpp.o


# Object files for target overlay_video
overlay_video_OBJECTS = \
"CMakeFiles/overlay_video.dir/overlay_video.cpp.o"

# External object files for target overlay_video
overlay_video_EXTERNAL_OBJECTS =

overlay_video: CMakeFiles/overlay_video.dir/overlay_video.cpp.o
overlay_video: CMakeFiles/overlay_video.dir/build.make
overlay_video: /usr/local/lib/libopencv_dnn.so.3.4.9
overlay_video: /usr/local/lib/libopencv_highgui.so.3.4.9
overlay_video: /usr/local/lib/libopencv_ml.so.3.4.9
overlay_video: /usr/local/lib/libopencv_objdetect.so.3.4.9
overlay_video: /usr/local/lib/libopencv_shape.so.3.4.9
overlay_video: /usr/local/lib/libopencv_stitching.so.3.4.9
overlay_video: /usr/local/lib/libopencv_superres.so.3.4.9
overlay_video: /usr/local/lib/libopencv_videostab.so.3.4.9
overlay_video: /usr/local/lib/libopencv_viz.so.3.4.9
overlay_video: /usr/local/lib/libopencv_calib3d.so.3.4.9
overlay_video: /usr/local/lib/libopencv_features2d.so.3.4.9
overlay_video: /usr/local/lib/libopencv_flann.so.3.4.9
overlay_video: /usr/local/lib/libopencv_photo.so.3.4.9
overlay_video: /usr/local/lib/libopencv_video.so.3.4.9
overlay_video: /usr/local/lib/libopencv_videoio.so.3.4.9
overlay_video: /usr/local/lib/libopencv_imgcodecs.so.3.4.9
overlay_video: /usr/local/lib/libopencv_imgproc.so.3.4.9
overlay_video: /usr/local/lib/libopencv_core.so.3.4.9
overlay_video: CMakeFiles/overlay_video.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/teemo/openCV_ws/overlay_video/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable overlay_video"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/overlay_video.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/overlay_video.dir/build: overlay_video

.PHONY : CMakeFiles/overlay_video.dir/build

CMakeFiles/overlay_video.dir/requires: CMakeFiles/overlay_video.dir/overlay_video.cpp.o.requires

.PHONY : CMakeFiles/overlay_video.dir/requires

CMakeFiles/overlay_video.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/overlay_video.dir/cmake_clean.cmake
.PHONY : CMakeFiles/overlay_video.dir/clean

CMakeFiles/overlay_video.dir/depend:
	cd /home/teemo/openCV_ws/overlay_video && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/teemo/openCV_ws/overlay_video /home/teemo/openCV_ws/overlay_video /home/teemo/openCV_ws/overlay_video /home/teemo/openCV_ws/overlay_video /home/teemo/openCV_ws/overlay_video/CMakeFiles/overlay_video.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/overlay_video.dir/depend
