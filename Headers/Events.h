#pragma once

#include <GLFW/glfw3.h>;

#include "../Headers/ComplementaryFunctions.h";
#include "../Headers/Render.h";

#include <iostream>;
#include <string>;

// Events:

namespace FenixEngine {
	void onRender() {
		glDrawElements(GL_TRIANGLES, (std::size(FenixEngine::indicesArray)), GL_UNSIGNED_INT, 0);
	};

	void onClick(GLFWwindow* window, int button, int action, int mods) {
		if (button == GLFW_MOUSE_BUTTON_1 and action == GLFW_PRESS) {
			double xPos, yPos;

			glfwGetCursorPos(window, &xPos, &yPos);

			float xPosF = (float) xPos;
			float yPosF = (float) yPos;

			int width, height;
			glfwGetFramebufferSize(window, &width, &height);

			float xCoordinate = FenixEngine::convertIntoCoordinate(xPosF, width);
			float yCoordinate = FenixEngine::convertIntoCoordinate(yPosF, height);

			std::vector<float> vertexArray = {
				xCoordinate, yCoordinate,                   // 0
				xCoordinate * 0.05f, yCoordinate,           // 1

				xCoordinate * -0.05f, yCoordinate * 0.05f,  // 2
				xCoordinate, yCoordinate * -0.05f,          // 3
			};

			std::vector<unsigned int> itemArray = {
				0, 1, 2,
				2, 3, 0,
			};

			FenixEngine::createObject(itemArray, vertexArray);
		};
	};
};
