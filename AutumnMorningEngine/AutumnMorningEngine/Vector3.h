#pragma once
#include "Vector2.h"

struct Vector3
{
public:
	float X;
	float Y;
	float Z;
public:
	Vector3() : X(0), Y(0), Z(0) {}
	Vector3(const Vector3&) {};
	Vector3(float InX, float InY, float InZ) : X(InX), Y(InY), Z(InZ) {}
	~Vector3() {};
public://Static Properties
	static const Vector3 Vector3::zero;
	static const Vector3 Vector3::one;
	//Think. 좌표계에 따라 달라지겠지만.. 일단 유니티에 맞춰서 만듦
	static const Vector3 Vector3::up;
	static const Vector3 Vector3::down;
	static const Vector3 Vector3::forword;
	static const Vector3 Vector3::back;
	static const Vector3 Vector3::right;
	static const Vector3 Vector3::left;
public:
	// 언리얼에선 Size()로 쓰는데.. 
	const float Vector3::magnitude() 
	{
		return X * X + Y * Y + Z * Z;
	}
public:
	Vector3 operator+(const Vector3&) const;
	Vector3 operator-(const Vector3&) const;
	Vector3 operator*(const float&) const;
	Vector3 operator/(const float&) const;
	Vector3 operator+=(const Vector3&);
	Vector3 operator-=(const Vector3&);
public:
	//float Dist(const Vector3 &V1, const Vector3 &V2);
	//float DistSquared(const Vector3 &V1, const Vector3 &V2);
	Vector2 ToVector2();
};

FORCEINLINE Vector3 Vector3::operator+(const Vector3& v) const
{
	Vector3 result;
	result.X = X + v.X;
	result.Y = Y + v.Y;
	result.Z = Z + v.Z;
	return result;
}

FORCEINLINE Vector3 Vector3::operator-(const Vector3& v) const
{
	Vector3 result;
	result.X = X - v.X;
	result.Y = Y - v.Y;
	result.Z = Z - v.Z;
	return result;
}

FORCEINLINE Vector3 Vector3::operator*(const float& scalar) const
{
	Vector3 result;
	result.X = X * scalar;
	result.Y = Y * scalar;
	result.Z = Z * scalar;
	return result;
}

FORCEINLINE Vector3 Vector3::operator/(const float& scalar) const
{
	Vector3 result;
	result.X = X / scalar;
	result.Y = Y / scalar;
	result.Z = Z / scalar;
	return result;
}

FORCEINLINE Vector3 Vector3::operator+=(const Vector3& v)
{
	X += v.X;
	Y += v.Y;
	Z += v.Z;
	return *this;
}

FORCEINLINE Vector3 Vector3::operator-=(const Vector3& v)
{
	X -= v.X;
	Y -= v.Y;
	Z -= v.Z;
	return *this;
}

//float Vector3::Dist(const Vector3 &V1, const Vector3 &V2)
//{
//	return sqrtf(Vector3::DistSquared(V1, V2));
//}

//float Vector3::DistSquared(const Vector3 &V1, const Vector3 &V2)
//{
//	return (V2.X - V1.X) * (V2.X - V1.X) + (V2.Y - V1.Y) * (V2.Y - V1.Y) +(V2.Z - V1.Z) * (V2.Z - V1.Z) ;
//}

FORCEINLINE Vector2 Vector3::ToVector2()
{
	return Vector2(X,Y);
}
