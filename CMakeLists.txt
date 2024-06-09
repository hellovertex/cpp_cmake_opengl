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

#[[
GLFW is essentially a wrapper of various platform-specific APIs and therefore needs to link against
many different system libraries. If you are using GLFW as a shared library / dynamic library / DLL
then it takes care of these links. However, if you are using GLFW as a static library then your executable
 will need to link against these libraries.

On Windows and macOS, the list of system libraries is static and can be hard-coded into your build
environment. See the section for your development environment below. On Linux and other Unix-like
operating systems, the list varies but can be retrieved in various ways as described below.
#]]
# todo: add glad https://github.com/enkisoftware/GLFW-CMake-starter/blob/main/CMakeLists.txt
target_link_libraries(glfwTest
        PRIVATE glfw
        $<$<NOT:$<PLATFORM_ID:Windows>>:pthread>
        $<$<NOT:$<PLATFORM_ID:Windows>>:dl>
        $<$<NOT:$<PLATFORM_ID:Windows>>:GL>
        $<$<NOT:$<PLATFORM_ID:Windows>>:X11>
        $<$<PLATFORM_ID:Windows>:opengl32>
        $<$<PLATFORM_ID:Windows>:gdi32>
)

