#pragma once
#include"Vector3.h"

struct Vector4
{
public:
	float X;
	float Y;
	float Z;
	float W;
public:
	Vector4() : X(0), Y(0), Z(0), W(0) {}
	Vector4(const Vector4&) {};
	Vector4(float InX, float InY, float InZ, float InW) : X(InX), Y(InY), Z(InZ), W(InW) {}
	~Vector4() {};
public://Static Properties
	static const Vector4 Vector4::zero;
	static const Vector4 Vector4::one;
//public:
//	Vector4 operator+(const Vector4&) const;
//	Vector4 operator-(const Vector4&) const;
//	Vector4 operator*(const float&) const;
//	Vector4 operator/(const float&) const;
//	Vector4 operator+=(const Vector4&);
//	Vector4 operator-=(const Vector4&);
//public:
//	float Dist(const Vector4 &V1, const Vector4 &V2);
//	float DistSquared(const Vector4 &V1, const Vector4 &V2);
//	Vector2 ToVector2();
//	Vector3 ToVector3();
};

