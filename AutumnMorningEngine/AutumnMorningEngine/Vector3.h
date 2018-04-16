#pragma once

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
	Vector3(int InX, int InY, int InZ) : X(InX), Y(InY), Z(InZ) {}
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


};


