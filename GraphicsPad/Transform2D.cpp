#pragma once
#include "Transform2D.h"

Transform2D::Transform2D() :
	position(0.0f, 0.0f),
	rotation(0.0f),
	scale(1.0f, 1.0f)
{
}

void Transform2D::outGlOffset(float& x, float& y) {
	x = this->position.x;
	y = this->position.y;
}

void Transform2D::outSingleScale(float& s) {
	s = this->scale.x;
}

void Transform2D::outScale(float& x, float& y) {
	x = this->scale.x;
	y = this->scale.y;
}