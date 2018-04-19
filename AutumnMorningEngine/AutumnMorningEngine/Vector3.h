#pragma once
#include "Vector2.h"

struct Vector3
{
public:
	float x;
	float y;
	float z;
public:
	Vector3() : x(0), y(0), z(0) {}
	Vector3(const Vector3&) {};
	Vector3(float InX, float InY, float InZ) : x(InX), y(InY), z(InZ) {}
	~Vector3() {};
public://Static Properties
	static const Vector3 Vector3::zero;
	static const Vector3 Vector3::one;
	//Think. ��ǥ�迡 ���� �޶���������.. �ϴ� ����Ƽ�� ���缭 ����
	static const Vector3 Vector3::up;
	static const Vector3 Vector3::down;
	static const Vector3 Vector3::forword;
	static const Vector3 Vector3::back;
	static const Vector3 Vector3::right;
	static const Vector3 Vector3::left;
public:
	// �𸮾󿡼� Size()�� ���µ�.. 
	const float Vector3::magnitude() 
	{
		return x * x + y * y + z * z;
	}
public:
	Vector3& operator+(const Vector3&) const;
	Vector3& operator-(const Vector3&) const;
	Vector3& operator*(const float&) const;
	Vector3& operator/(const float&) const;
	Vector3& operator+=(const Vector3&);
	Vector3& operator-=(const Vector3&);
public:
	//float Dist(const Vector3 &V1, const Vector3 &V2);
	//float DistSquared(const Vector3 &V1, const Vector3 &V2);
	Vector2 ToVector2();
};

FORCEINLINE Vector3& Vector3::operator+(const Vector3& v) const
{
	Vector3 result;
	result.x = x + v.x;
	result.y = y + v.y;
	result.z = z + v.z;
	return result;
}

FORCEINLINE Vector3& Vector3::operator-(const Vector3& v) const
{
	Vector3 result;
	result.x = x - v.x;
	result.y = y - v.y;
	result.z = z - v.z;
	return result;
}

FORCEINLINE Vector3& Vector3::operator*(const float& scalar) const
{
	Vector3 result;
	result.x = x * scalar;
	result.y = y * scalar;
	result.z = z * scalar;
	return result;
}

FORCEINLINE Vector3& Vector3::operator/(const float& scalar) const
{
	Vector3 result;
	result.x = x / scalar;
	result.y = y / scalar;
	result.z = z / scalar;
	return result;
}

FORCEINLINE Vector3& Vector3::operator+=(const Vector3& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

FORCEINLINE Vector3& Vector3::operator-=(const Vector3& v)
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

FORCEINLINE Vector2 Vector3::ToVector2()
{
	return Vector2(x,y);
}
