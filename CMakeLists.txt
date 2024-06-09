# ALWAYS REMEMBER THESE:
# https://gist.github.com/mbinna/c61dbb39bca0e4fb7d1f73b0d66a4fd1
cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)

# todo: Add Semantic Versioning
project(c_cpp)

# load custom modules via src/CMakeLists.txt
add_subdirectory(src)

# todo: try multiple generators
add_executable(glfwTest src/main.cpp)

# add GLFW
# .a
target_link_directories(glfwTest PUBLIC "${CMAKE_SOURCE_DIR}/lib")
# headers
target_include_directories(glfwTest PRIVATE "${CMAKE_SOURCE_DIR}/include/GLFW")

# link non-custom libraries
target_link_libraries(glfwTest
        PRIVATE glfw3
        PRIVATE pthread
        PRIVATE dl
        PRIVATE GL
        PRIVATE X11)

