#include <GL/glew.h>;
#include <GLFW/glfw3.h>;

#include "../Headers/Buffers.h";
#include "../Headers/Shaders.h";
#include "../Headers/Render.h";

#include <iostream>;
#include <string>;

int main() {
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "| FenixEngine |", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    };

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
       std::cout << "Glew is not ok!" << std::endl;

    std::cout << glGetString(GL_VERSION) << std::endl;

    FenixEngine::initializeBuffers(FenixEngine::getDefaultVertexArray(), FenixEngine::getDefaultIndicesArray());

    unsigned int shader = FenixEngine::createShader("   color = vec4(0.0, 0.0, 1.0, 1.0); \n");
    glUseProgram(shader);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        FenixEngine::drawVertexArray(FenixEngine::getDefaultIndicesArray());
        
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    };

    glfwTerminate();

    return 0;
};
