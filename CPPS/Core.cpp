#include <glad/glad.h>;
#include <GLFW/glfw3.h>;

#include "../Headers/ErrorHandler.h";
#include "../Headers/Buffers.h";
#include "../Headers/Shaders.h";
#include "../Headers/Render.h";
#include "../Headers/Events.h";

#include <iostream>;
#include <string>;

int main() {
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(800, 600, "| FenixEngine |", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    };

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glViewport(0, 0, 800, 600);

    glfwSetWindowSizeCallback(window, [](GLFWwindow* window, int width, int height) {
        glViewport(0, 0, width, height);
    });

    // Fenix Engine initializers:

    FenixEngine::createShader(1.0f, 1.0f, 1.0f);

    // Some events handler:

    glfwSetMouseButtonCallback(window, FenixEngine::onClick);

    /* Loop until the user closes the window */

    while (!glfwWindowShouldClose(window))
    {
        /* Render here */

        glClearColor(0.31f, 0.31f, 0.31f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        FenixEngine::glClearError();
        FenixEngine::onRender();
        FenixEngine::glCheckError();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    };

    glfwTerminate();

    return 0;
};
