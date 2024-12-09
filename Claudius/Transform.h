#pragma once

#include "Vector2.h"

struct Transform
{
	Transform();
	Transform(const Transform& rhs);
	Transform(float x, float y, float rotation);
	
	void SetPosition(const float x, const float y);
	void ChangePosition(const float x, const float y);
	void SetRotation(const float rotation);
	void ChangeRotation(const float rotation);

	Vector2 GetPosition() const noexcept;
	float GetX() const noexcept;
	float GetY() const noexcept;
	float GetRotation();

	Vector2 position;
	float rotation;
};