#pragma once

#define radians 0.0174532925f

#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h" //Vector3,Vector2 Æ÷ÇÔ
#include "Matrix2.h"
#include "Matrix3.h"
#include "Matrix4.h"

Matrix4* MatrixRotationYawPitchRoll(Matrix4*, float, float, float);
Matrix4* MatrixTranspose(Matrix4*pOut,CONST Matrix4 *pV);
Vector3* Vec3TransformCoord(Vector3 *pOut, CONST Vector3 *pV, CONST Matrix4 *pM);