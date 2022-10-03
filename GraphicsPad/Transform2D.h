#pragma once
#include <glm/glm.hpp>

class Transform2D {
public:
	Transform2D();
	glm::vec2 position;
	float rotation;
	glm::vec2 scale;
	void outGlOffset(float& x, float& y);
	void outScale(float& x, float& y);
	void outSingleScale(float& s);
	void setUniScale(float s);
};