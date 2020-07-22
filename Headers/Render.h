#pragma once

#include <glad/glad.h>;
#include <GLFW/glfw3.h>;

#include "../Headers/ComplementaryFunctions.h";
#include "../Headers/Buffers.h";

#include <vector>;
#include <string>;

namespace FenixEngine {
	std::vector<unsigned int> indicesArray = {
		
	};

	std::vector<float> vertexArray = {
	  
	};

	void createObject(std::vector<unsigned int> indicesArray, std::vector<float> vertexArray) {
	  	FenixEngine::indicesArray = indicesArray;
	    FenixEngine::vertexArray = vertexArray;

	 //	FenixEngine::indicesArray.insert(FenixEngine::indicesArray.end(), indicesArray.begin(), indicesArray.end());
	 //	FenixEngine::vertexArray.insert(FenixEngine::vertexArray.end(), vertexArray.begin(), vertexArray.end());

		FenixEngine::createBuffers(indicesArray, vertexArray);
	};
};
