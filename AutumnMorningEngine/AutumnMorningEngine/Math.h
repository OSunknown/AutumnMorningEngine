#pragma once

#define radians 0.0174532925f
#include <math.h>
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h" //Vector3,Vector2 Æ÷ÇÔ
#include "Matrix2.h"
#include "Matrix3.h"
#include "Matrix4.h"

Matrix4* MatrixRotationYawPitchRoll(Matrix4*, FLOAT, FLOAT, FLOAT);
Matrix4* MatrixRotationY(Matrix4*, FLOAT); //Roll
Matrix4* MatrixTranspose(Matrix4*pOut,CONST Matrix4 *pV);
Matrix4* MatrixLookAtLH(Matrix4 *pOut, CONST Vector3 * pEye, CONST Vector3 * pAt, CONST Vector3 *pUp);
Matrix4* MatrixPerspectiveFovLH(Matrix4 *pOut, CONST FLOAT fovy, FLOAT Aspect, FLOAT zn, FLOAT zf);
Vector3* Vec3TransformCoord(Vector3 *pOut, CONST Vector3 *pV, CONST Matrix4 *pM);
Vector3 Cross(Vector3 left, Vector3 right);
float dot(Vector3 left, Vector3 right);