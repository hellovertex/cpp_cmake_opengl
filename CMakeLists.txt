# ALWAYS REMEMBER THESE:
# https://gist.github.com/mbinna/c61dbb39bca0e4fb7d1f73b0d66a4fd1
cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)

# todo: Add Semantic Versioning
project(c_cpp)
find_package(OpenGL REQUIRED)

# todo: try multiple generators
add_executable(glfwTest src/main.cpp)

# load custom modules via src/CMakeLists.txt
add_subdirectory(src)  # alias to 'Add another CMakeLists.txt'
# load external modules via their CMakeLists.txt
add_subdirectory(external/glfw)

# add GLFW headers
target_include_directories(glfwTest
        PUBLIC external/glfw/include
)
target_link_directories(glfwTest
        PRIVATE external/glfw/src
)
# link non-custom libraries
target_link_libraries(glfwTest
        PRIVATE glfw
        PRIVATE pthread
        PRIVATE dl
        PRIVATE GL
        PRIVATE X11
)
