#pragma once
//#define PI    (3.14159265358979323846)
#define OneByPI ( 1.0 / PI )
#define radians 0.0174532925f
#define ToRadian(degree)((degree) * (PI/180.0))
#define ToDegree( radian ) ((radian) * (180.0 / PI))
#define FRoundToInt(F) (_mm_cvt_ss2si(_mm_set_ss(F + F + 0.5f)) >> 1)

#include <math.h>
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h" //Vector3,Vector2 포함
#include "Matrix2.h" //Vector4포함
#include "Matrix3.h"
#include "Matrix4.h" 

Matrix4* MatrixRotationYawPitchRoll(Matrix4*, FLOAT, FLOAT, FLOAT);
Matrix4* MatrixRotationY(Matrix4*, FLOAT); //Roll
Matrix4* MatrixTranspose(Matrix4*pOut,CONST Matrix4 *pV);
Matrix4* MatrixLookAtLH(Matrix4 *pOut, CONST Vector3 * pEye, CONST Vector3 * pAt, CONST Vector3 *pUp);
Matrix4* MatrixPerspectiveFovLH(Matrix4 *pOut, CONST FLOAT fovy, FLOAT Aspect, FLOAT zn, FLOAT zf);
Matrix4* MatrixOrthoLH(Matrix4 *pOut, FLOAT w, FLOAT h, FLOAT zn, FLOAT zf);
Matrix4* MatrixIdentity(Matrix4* pOut);
Vector3* Vec3TransformCoord(Vector3 *pOut, CONST Vector3 *pV, CONST Matrix4 *pM);
Vector3 Cross(Vector3 left, Vector3 right);
float dot(Vector3 left, Vector3 right);

Vector2 ToVector2(Vector3 value);
Vector2 ToVector2(Vector4 value);
Vector3 ToVector3(Vector4 value);
Vector4 ToVector4(Vector2 value, FLOAT z, FLOAT w);
Vector4 ToVector4(Vector3 value, FLOAT w);
FORCEINLINE int RoundToInt(float F)
{
	// Note: the x2 is to workaround the rounding-to-nearest-even-number issue when the fraction is .5
	return _mm_cvt_ss2si(_mm_set_ss(F + F + 0.5f)) >> 1;
}