#pragma once

struct Vector2
{
public:
	float X;
	float Y;
public://Static Praoperties
	static const Vector2 Vector2::zero;
	static const Vector2 Vector2::one;
public:
	Vector2() : X(0), Y(0) {};
	Vector2(float InX, float InY) : X(InX), Y(InY) {}
	~Vector2() {};
};
