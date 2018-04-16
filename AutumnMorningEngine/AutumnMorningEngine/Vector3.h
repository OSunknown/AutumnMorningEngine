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
		return X * X + Y * Y + Z * Z;
	}


};


