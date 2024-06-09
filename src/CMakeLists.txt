cmake_minimum_required(VERSION 3.16)
# inject code from project-provided modules
# Optional: may have to append module folder to CMAKE_MODULE_PATH, like so:
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/hellovertex_cmake_modules")
include(log_cmake_commands)

# ARGC, ARGV, ARGN
#print_commands()



