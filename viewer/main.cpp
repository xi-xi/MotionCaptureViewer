#include <iostream>
#include <memory>

#include <GLFW/glfw3.h>

static void error_callback(int error, const char* desc)
{
    std::cerr << desc;
}

static void key_callback(GLFWwindow *window,int key, int scancode, int action, int mods)
{
}


int main(int argc,const char** argv)
{
    glfwInit();
    GLboolean running = GL_TRUE;
    glfwSetErrorCallback(error_callback);
    GLFWwindow* window = glfwCreateWindow(640, 480, "TEST", NULL, NULL);
    if(!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwSetKeyCallback(window, key_callback);
    glfwMakeContextCurrent(window);
    glClearColor(.0, .0, .0, 1.0);
    while(running)
    {
        glfwMakeContextCurrent(window);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        if(glfwWindowShouldClose(window))
        {
            running = GL_FALSE;
        }
        glfwPollEvents();
    }
    glfwTerminate();
    exit(EXIT_SUCCESS);
    return 0;
}