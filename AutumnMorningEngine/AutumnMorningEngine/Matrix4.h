#pragma once
struct Matrix4
{
public:
	float _11, _12, _13, _14;
	float _21, _22, _23, _24;
	float _31, _32, _33, _34;
	float _41, _42, _43, _44;
public:
	Matrix4() : _11(0), _12(0), _13(0), _14(0),
				_21(0), _22(0), _23(0), _24(0),
				_31(0), _32(0), _33(0), _34(0),
				_41(0), _42(0), _43(0), _44(0){}
	~Matrix4() {};

	Matrix4* __stdcall MatrixRotationYawPitchRoll(Matrix4* a)
	{

	}
};

