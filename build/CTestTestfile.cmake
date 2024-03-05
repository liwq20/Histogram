# CMake generated Testfile for 
# Source directory: /home/oliwi/pipr/cpp2
# Build directory: /home/oliwi/pipr/cpp2/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(mytests "/home/oliwi/pipr/cpp2/build/mytests")
set_tests_properties(mytests PROPERTIES  _BACKTRACE_TRIPLES "/home/oliwi/pipr/cpp2/CMakeLists.txt;16;add_test;/home/oliwi/pipr/cpp2/CMakeLists.txt;0;")
subdirs("googletest")
