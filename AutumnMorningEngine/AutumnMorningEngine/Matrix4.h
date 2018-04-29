#pragma once
#include "Matrix3.h"

struct Matrix4
{
public:
	float _11, _12, _13, _14;
	float _21, _22, _23, _24;
	float _31, _32, _33, _34;
	float _41, _42, _43, _44;
public:
	Matrix4() : 
		_11(0), _12(0), _13(0), _14(0),
		_21(0), _22(0), _23(0), _24(0),
		_31(0), _32(0), _33(0), _34(0),
		_41(0), _42(0), _43(0), _44(0) {};
	Matrix4(int a) : 
		_11(11), _12(12), _13(13), _14(14),
		_21(21), _22(22), _23(23), _24(24),
		_31(31), _32(32), _33(33), _34(34),
		_41(41), _42(42), _43(43), _44(44) {};
	Matrix4(float _Line1x , float _Line1y, float _Line1z, float _Line1w,
		float _Line2x, float _Line2y, float _Line2z, float _Line2w,
		float _Line3x, float _Line3y, float _Line3z, float _Line3w,
		float _Line4x, float _Line4y, float _Line4z, float _Line4w)
	{
		_11 = _Line1x;
		_12 = _Line1y;
		_13 = _Line1z;
		_14 = _Line1w;
		_21 = _Line2x;
		_22 = _Line2y;
		_23 = _Line2z;
		_24 = _Line2w;
		_31 = _Line3x;
		_32 = _Line3y;
		_33 = _Line3z;
		_34 = _Line3w;
		_41 = _Line4x;
		_42 = _Line4y;
		_43 = _Line4z;
		_44 = _Line4w;
	}
	Matrix4(const Matrix4 * m)
	{
		_11 = m->_11;
		_12 = m->_12;
		_13 = m->_13;
		_14 = m->_14;
		_21 = m->_21;
		_22 = m->_22;
		_23 = m->_23;
		_24 = m->_24;
		_31 = m->_31;
		_32 = m->_32;
		_33 = m->_33;
		_34 = m->_34;
		_41 = m->_41;
		_42 = m->_42;
		_43 = m->_43;
		_44 = m->_44;
	}
	~Matrix4() {};
public:
	void SetIdentity()
	{
		_11 = 1.0f;
		_12 = 0.0f;
		_13 = 0.0f;
		_14 = 0.0f;
		_21 = 0.0f;
		_22 = 1.0f;
		_23 = 0.0f;
		_24 = 0.0f;
		_31 = 0.0f;
		_32 = 0.0f;
		_33 = 1.0f;
		_34 = 0.0f;
		_41 = 0.0f;
		_42 = 0.0f;
		_43 = 0.0f;
		_44 = 1.0f;
	}
	//
	// tutorial Link : http://planning.cs.uiuc.edu/node102.html
	//
	void SetRotation(float yaw, float pitch, float roll)
	{
		SetIdentity();
		float sinY = sinf(yaw);
		float sinP = sinf(pitch);
		float sinR = sinf(roll);
		float cosY = cosf(yaw);
		float cosP = cosf(pitch);
		float cosR = cosf(roll);

		_11 = cosY *cosP;
		_12 = cosY * sinP *sinR - sinY * cosR;
		_13 = cosY * sinP*cosR + sinY * sinR;
		_14 = 0.0f;
		_21 = sinY * cosP;
		_22 = sinY * sinP * sinR + cosY * cosR;
		_23 = sinY * sinP * cosR - cosY * sinR;
		_24 = 0.0f;
		_31 = -sinP;
		_32 = cosP * sinR;
		_33 = cosP * cosR;
		_34 = 0.0f;
		_41 = 0.0f;
		_42 = 0.0f;
		_43 = 0.0f;
		_44 = 1.0f;
	}

	void SetRotationY(float Angle)
	{
		SetIdentity();
		_11 = cosf(Angle);
		_13 = -sinf(Angle);
		_31 = sinf(Angle);
		_33 = cos(Angle);
	}

	void SetMatrixPerspectiveFovLH(FLOAT fovY, FLOAT Aspect, FLOAT zn, FLOAT zf)
	{

	}
};

