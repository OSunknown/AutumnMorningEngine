#include "Math.h"

//Vector2 Initialize
const Vector2 Vector2::zero(0.0f, 0.0f);
const Vector2 Vector2::one(1.0f, 1.0f);
//Vector3 Initialize
const Vector3 Vector3::zero(0.0f, 0.0f, 0.0f);
const Vector3 Vector3::one(1.0f, 1.0f, 1.0f);
//Think. 좌표계에 따라 달라지겠지만.. 일단 유니티에 맞춰서 만듦
const Vector3 Vector3::up(0.0f, 1.0f, 0.0f);
const Vector3 Vector3::down(0.0f, -1.0f, 0.0f);
const Vector3 Vector3::forword(0.0f, 0.0f, 1.0f);
const Vector3 Vector3::back(0.0f, 0.0f, -1.0f);
const Vector3 Vector3::right(1.0f, 0.0f, 0.0f);
const Vector3 Vector3::left(-1.0f, 0.0f, 0.0f);
//Vector4 Initialize
const Vector4 Vector4::zero(0.0f, 0.0f, 0.0f,0.0f);
const Vector4 Vector4::one(1.0f, 1.0f, 1.0f,1.0f);

Matrix4* MatrixRotationYawPitchRoll(Matrix4 *rotationMatrix, float yaw, float pitch, float roll)
{
	rotationMatrix->SetRotation(yaw, pitch, roll);
	return rotationMatrix;
}
Matrix4* MatrixTranspose(Matrix4*pOut, CONST Matrix4 *pV)
{
	float temp = 0;
	temp = pV->_12;
	pOut->_12 = pV->_21;
	pOut->_21 = temp;
	temp = pV->_13;
	pOut->_13 = pV->_31;
	pOut->_31 = temp;
	temp = pV->_14;
	pOut->_14 = pV->_41;
	pOut->_41 = temp;
	temp = pV->_23;
	pOut->_23 = pV->_32;
	pOut->_32 = temp;
	temp = pV->_24;
	pOut->_24 = pV->_42;
	pOut->_42 = temp;
	temp = pV->_34;
	pOut->_34 = pV->_43;
	pOut->_43 = temp;
	return pOut;
}
Vector3* Vec3TransformCoord(Vector3 *pOut, CONST Vector3 *pV, CONST Matrix4 *pM)
{
	Vector4 pC(pV,1);
	pC = pC * pM;
	return pOut;
}