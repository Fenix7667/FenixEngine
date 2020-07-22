#pragma once

#include <iostream>;
#include <time.h>;

namespace FenixEngine {
	float convertIntoCoordinate(float pixels, int axis) {
		return (pixels / (axis / 2)) - 1;
	};
};
