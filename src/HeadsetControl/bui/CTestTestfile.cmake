# CMake generated Testfile for 
# Source directory: /home/b3rnie/path2/projects/headsetcontrol-gui/src/HeadsetControl
# Build directory: /home/b3rnie/path2/projects/headsetcontrol-gui/src/HeadsetControl/bui
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[run_test]=] "headsetcontrol")
set_tests_properties([=[run_test]=] PROPERTIES  PASS_REGULAR_EXPRESSION "No supported headset found" _BACKTRACE_TRIPLES "/home/b3rnie/path2/projects/headsetcontrol-gui/src/HeadsetControl/CMakeLists.txt;145;add_test;/home/b3rnie/path2/projects/headsetcontrol-gui/src/HeadsetControl/CMakeLists.txt;0;")
subdirs("src")
subdirs("src/devices")
