# ALWAYS REMEMBER THESE:
# https://gist.github.com/mbinna/c61dbb39bca0e4fb7d1f73b0d66a4fd1
cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)

# todo: Add Semantic Versioning
project(c_cpp)

find_package(OpenGL REQUIRED)
# --------------------------------------------------------------------------- #
# ------------------------------ glfwTest ----------------------------------- #
# --------------------------------------------------------------------------- #
set(sourcefiles
        code/source_files/event_dispatcher.cc
)

# todo: try multiple generators
add_executable(glfwTest
        code/source_files/main.cc
        code/source_files/glad.c
        ${sourcefiles}
)

# todo: watch https://www.youtube.com/watch?v=bsXLMQ6WgIk
# load custom modules via code/CMakeLists.txt
add_subdirectory(code)  # alias to 'Add another CMakeLists.txt'
# load lib modules via their CMakeLists.txt
add_subdirectory(lib/glfw)

# pointers to header files
target_include_directories(glfwTest
        # Third party headers
        PUBLIC lib/glfw/include
        PUBLIC lib/glad/include
        # Custom headers
        PRIVATE include
#        PUBLIC lib/linmath/include
)

# path to glfw library that has been created using `add_library` in
#  the glfw-CMakeLists.txt file
target_link_directories(glfwTest
        PRIVATE lib/glfw/src
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
#        PRIVATE GTest::gtest_main
        #        PRIVATE linmath
        $<$<NOT:$<PLATFORM_ID:Windows>>:pthread>
        $<$<NOT:$<PLATFORM_ID:Windows>>:dl>
        $<$<NOT:$<PLATFORM_ID:Windows>>:GL>
        $<$<NOT:$<PLATFORM_ID:Windows>>:X11>
        $<$<PLATFORM_ID:Windows>:opengl32>
        $<$<PLATFORM_ID:Windows>:gdi32>
)

# --------------------------------------------------------------------------- #
# -------------------------------- GTEST ------------------------------------ #
# --------------------------------------------------------------------------- #
# see https://google.github.io/googletest/quickstart-cmake.html#set-up-a-project
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
# This makes the gtest headers available
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# see https://google.github.io/googletest/quickstart-cmake.html#create-and-run-a-binary
#https://stackoverflow.com/questions/13550153/no-tests-found-when-using-gtest-with-cmake-ctest
#include(CTest)
enable_testing()

# Add test executable
add_executable(my_tests
        ${sourcefiles}
        tests/tests_main.cc
        tests/test_dispatcher.cc
        # other test files
)

target_include_directories(my_tests
        PRIVATE include
)
target_link_libraries(my_tests
        GTest::gtest_main
)

# Include tests in the testing framework
include(GoogleTest)
gtest_discover_tests(my_tests)