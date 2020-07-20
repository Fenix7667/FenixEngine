#pragma once
#include <GL/glew.h>;
#include <GLFW/glfw3.h>;

#include <vector>;
#include <string>;

namespace FenixEngine {
	void drawVertexArray(std::vector<unsigned int> indices) {
		glDrawElements(GL_TRIANGLES, (std::size(indices)), GL_UNSIGNED_INT, 0);
	};

	std::vector<float> getDefaultVertexArray() {
		std::vector<float> vertexArray = {
			  0,   0.5, // 0
			  0.5, 0.0, // 1
			 -0.5, 0.0, // 2
			  0,  -0.5, // 3
		};

		return vertexArray;
	};

	std::vector<unsigned int> getDefaultIndicesArray() {
		std::vector<unsigned int> indicesArray = {
			0, 1, 2,
			1, 2, 3,
		};

		return indicesArray;
	};
};
