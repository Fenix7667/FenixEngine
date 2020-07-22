#pragma once

#include <glad/glad.h>;
#include <GLFW/glfw3.h>;

#include <vector>;

namespace FenixEngine {
    void createBuffers(std::vector<unsigned int> indicesArray, std::vector<float> vertexArray) {
        GLuint vao = 0;
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);

        unsigned int buffer;
        glGenBuffers(1, &buffer);
        glBindBuffer(GL_ARRAY_BUFFER, buffer);
        glBufferData(GL_ARRAY_BUFFER, vertexArray.size() * sizeof(float), vertexArray.data(), GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

        unsigned int indexBufferObject;
        glGenBuffers(1, &indexBufferObject);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferObject);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesArray.size() * sizeof(float), indicesArray.data(), GL_STATIC_DRAW);
    };
};
