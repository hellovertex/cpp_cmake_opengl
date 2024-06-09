extern "C" {
    #include "GLFW/glfw3.h"
}
// Linux:
//  g++ main.cpp -o glwfTest -I`pwd`/include/GLFW -L`pwd`/lib -lglfw3
// throws undefined reference pthread_thread.c so we must link additional libraries
// g++ main.cpp -o build/glwfTest -I`pwd`/include/GLFW -L`pwd`/lib -lglfw3 -lpthread -ldl -lGL -lX11
// OK

// Windows:
// x86_64-w64-mingw32-g++-posix main.cpp -o glfwTest -I`pwd`/include/GLFW -L`pwd`/lib -lglfw3 -lpthread -ldl -lGL -lX11
// /usr/bin/x86_64-w64-mingw32-ld: cannot find -ldl
// /usr/bin/x86_64-w64-mingw32-ld: cannot find -lGL
// /usr/bin/x86_64-w64-mingw32-ld: cannot find -lX11
// removing them does not fix the issue:
// /usr/bin/x86_64-w64-mingw32-ld: /tmp/ccrCipIh.o:main.cpp:(.text+0xe): undefined reference to `glfwInit'
// todo:
//  1. rebuild GLFW using their cmake but for another platform (WINDOWS)
//  2. add new library (.dll?) to `pwd`/lib
//  3. re-run `x86_64-w64-mingw32-g++-posix` but with .dll linked instead of .a

int main()
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}