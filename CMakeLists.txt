# ALWAYS REMEMBER THESE:
# https://gist.github.com/mbinna/c61dbb39bca0e4fb7d1f73b0d66a4fd1
cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)

# todo: Add Semantic Versioning
project(c_cpp)

find_package(OpenGL REQUIRED)

# see https://google.github.io/googletest/quickstart-cmake.html#set-up-a-project
# todo fix warning:
#cmake_policy(SET CMP0135 NEW)
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# see https://google.github.io/googletest/quickstart-cmake.html#create-and-run-a-binary
#enable_testing() https://stackoverflow.com/questions/13550153/no-tests-found-when-using-gtest-with-cmake-ctest
include(CTest)

# todo: try multiple generators
add_executable(glfwTest
        code/sources/main.cc
        code/sources/glad.c
        code/sources/event_dispatcher.cc
        tests/test_dispatcher.cc
)
add_subdirectory(tests)

# todo: watch https://www.youtube.com/watch?v=bsXLMQ6WgIk
# load custom modules via code/CMakeLists.txt
add_subdirectory(code)  # alias to 'Add another CMakeLists.txt'
# load external modules via their CMakeLists.txt
add_subdirectory(external/glfw)



target_include_directories(glfwTest
        # Third party
        PUBLIC external/glfw/include
        PUBLIC external/glad/include
        # Custom
        PRIVATE code/headers
#        PUBLIC external/linmath/include
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
        PRIVATE GTest::gtest_main
        #        PRIVATE linmath
        $<$<NOT:$<PLATFORM_ID:Windows>>:pthread>
        $<$<NOT:$<PLATFORM_ID:Windows>>:dl>
        $<$<NOT:$<PLATFORM_ID:Windows>>:GL>
        $<$<NOT:$<PLATFORM_ID:Windows>>:X11>
        $<$<PLATFORM_ID:Windows>:opengl32>
        $<$<PLATFORM_ID:Windows>:gdi32>
)
