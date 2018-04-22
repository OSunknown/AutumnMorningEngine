#pragma once
#include"Vector3.h"

struct Vector4
{
public:
	float x;
	float y;
	float z;
	float w;
public:
	Vector4() : x(0), y(0), z(0), w(0) { x = 0; y = 0; z = 0; w = 0; };
	Vector4(float InX, float InY, float InZ, float InW); //: x(InX), y(InY), z(InZ), w(InW)
	~Vector4() {};
public://Static Properties
	static const Vector4 Vector4::zero;
	static const Vector4 Vector4::one;
public:
	Vector4& operator+(const Vector4&) const;
	Vector4& operator-(const Vector4&) const;
	Vector4& operator*(const float&) const;
	Vector4& operator/(const float&) const;
	Vector4& operator+=(const Vector4&);
	Vector4& operator-=(const Vector4&);
	
public:
	float Dist(const Vector4 &V1, const Vector4 &V2);
	float DistSquared(const Vector4 &V1, const Vector4 &V2);
	Vector2 ToVector2();
	Vector3 ToVector3();
	Vector4 Get() {
		return Vector4(x, y, z, w);
	};

};


FORCEINLINE Vector4& Vector4::operator+(const Vector4& v) const
{
	Vector4 result;
	result.x = x + v.x;
	result.y = y + v.y;
	result.z = z + v.z;
	result.w = w + v.w;
	return result;
}

FORCEINLINE Vector4& Vector4::operator-(const Vector4& v) const
{
	Vector4 result;
	result.x = x - v.x;
	result.y = y - v.y;
	result.z = z - v.z;
	result.w = w - v.w;
	return result;
}

FORCEINLINE Vector4& Vector4::operator*(const float& scalar) const
{
	Vector4 result;
	result.x = x * scalar;
	result.y = y * scalar;
	result.z = z * scalar;
	return result;
}

FORCEINLINE Vector4& Vector4::operator/(const float& scalar) const
{
	Vector4 result;
	result.x = x / scalar;
	result.y = y / scalar;
	result.z = z / scalar;
	return result;
}

FORCEINLINE Vector4& Vector4::operator+=(const Vector4& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

FORCEINLINE Vector4& Vector4::operator-=(const Vector4& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
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

FORCEINLINE Vector2 Vector4::ToVector2()
{
	return Vector2(x, y);
}