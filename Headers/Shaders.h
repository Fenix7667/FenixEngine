#pragma once
#include <GL/glew.h>;
#include <GLFW/glfw3.h>;

#include <iostream>;

namespace FenixEngine {
    static unsigned int compileShader(unsigned int type, const std::string& source) {
        unsigned int id = glCreateShader(type);
        const char* src = source.c_str();
        glShaderSource(id, 1, &src, nullptr);
        glCompileShader(id);

        int result;
        glGetShaderiv(id, GL_COMPILE_STATUS, &result);
        if (result == GL_FALSE) {
            int length;
            glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
            char* message = (char*)_malloca(length * sizeof(char));
            glGetShaderInfoLog(id, length, &length, message);
            std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader!" << std::endl;
            std::cout << message << std::endl;
            glDeleteShader(id);

            return 0;
        };

        return id;
    };

    static unsigned int createShader(std::string color) {
        std::string vertexShaderConfig =
            "#version 330 core\n"
            "\n"
            "layout(location = 0) in vec4 position;\n"
            "\n"
            "void main()\n"
            "{\n"
            "   gl_Position = position;\n"
            "}\n";

        std::string fragmentShaderConfig =
            "#version 330 core\n"
            "\n"
            "layout(location = 0) out vec4 color;\n"
            "\n"
            "void main()\n"
            "{\n" + color + "}";

        unsigned int program = glCreateProgram();
        unsigned int vertexShader = compileShader(GL_VERTEX_SHADER, vertexShaderConfig);
        unsigned int fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentShaderConfig);

        glAttachShader(program, vertexShader);
        glAttachShader(program, fragmentShader);
        glLinkProgram(program);
        glValidateProgram(program);

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        return program;
    };
};
