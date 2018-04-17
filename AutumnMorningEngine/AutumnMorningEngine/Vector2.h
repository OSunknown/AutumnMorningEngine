#pragma once
#include "stdafx.h"

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
	Vector2(float InX, float InY) : X(InX), Y(InY) {};
	~Vector2() {};
public:
	Vector2 operator+(const Vector2&) const;
	Vector2 operator-(const Vector2&) const;
	Vector2 operator*(const float&) const;
	Vector2 operator/(const float&) const;
	Vector2 operator+=(const Vector2&);
	Vector2 operator-=(const Vector2&);
public:
	float Dist(const Vector2 &V1, const Vector2 &V2)
	{
		return sqrtf(Vector2::DistSquared(V1, V2));
	}
	float DistSquared(const Vector2 &V1, const Vector2 &V2)
	{
		return (V2.X - V1.X) * (V2.X - V1.X) + (V2.Y - V1.Y) * (V2.Y - V1.Y);
	}
};

FORCEINLINE Vector2 Vector2::operator+(const Vector2& v) const
{
	Vector2 result;
	result.X = X + v.X;
	result.Y = Y + v.Y;
	return result;
}

FORCEINLINE Vector2 Vector2::operator-(const Vector2& v) const
{
	Vector2 result;
	result.X = X - v.X;
	result.Y = Y - v.Y;
	return result;
}

FORCEINLINE Vector2 Vector2::operator*(const float& scalar) const
{
	Vector2 result;
	result.X = X * scalar;
	result.Y = Y * scalar;
	return result;
}

FORCEINLINE Vector2 Vector2::operator/(const float& scalar) const
{
	Vector2 result;
	result.X = X / scalar;
	result.Y = Y / scalar;
	return result;
}

FORCEINLINE Vector2 Vector2::operator+=(const Vector2& v)
{
	X += v.X;
	Y += v.Y;
	return *this;
}

FORCEINLINE Vector2 Vector2::operator-=(const Vector2& v)
{
	X -= v.X;
	Y -= v.Y;
	return *this;
}
