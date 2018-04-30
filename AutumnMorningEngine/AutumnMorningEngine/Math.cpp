#include "Math.h"

//Vector2 Initialize
const Vector2 Vector2::zero(0.0f, 0.0f);
const Vector2 Vector2::one(1.0f, 1.0f);
//Vector3 Initialize
const Vector3 Vector3::zero(0.0f, 0.0f, 0.0f);
const Vector3 Vector3::one(1.0f, 1.0f, 1.0f);
//Think. ��ǥ�迡 ���� �޶���������.. �ϴ� ����Ƽ�� ���缭 ����
const Vector3 Vector3::up(0.0f, 1.0f, 0.0f);
const Vector3 Vector3::down(0.0f, -1.0f, 0.0f);
const Vector3 Vector3::forword(0.0f, 0.0f, 1.0f);
const Vector3 Vector3::back(0.0f, 0.0f, -1.0f);
const Vector3 Vector3::right(1.0f, 0.0f, 0.0f);
const Vector3 Vector3::left(-1.0f, 0.0f, 0.0f);
//Vector4 Initialize
const Vector4 Vector4::zero(0.0f, 0.0f, 0.0f,0.0f);
const Vector4 Vector4::one(1.0f, 1.0f, 1.0f,1.0f);

Matrix4* MatrixRotationYawPitchRoll(Matrix4 *rotationMatrix, FLOAT yaw, FLOAT pitch, FLOAT roll)
{
	rotationMatrix->SetRotation(yaw, pitch, roll);
	return rotationMatrix;
}
//Roll Rotation Y axis
Matrix4 * MatrixRotationY(Matrix4 * pOut, FLOAT Angle)
{
	pOut->SetRotationY(Angle);
	return pOut;
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
Matrix4 * MatrixLookAtLH(Matrix4 * pOut, CONST Vector3 * pEye, CONST Vector3 * pAt, CONST Vector3 * pUp)
{
	Vector3 xaxis, yaxis, zaxis;
	zaxis = (Vector3)pAt - (Vector3)pEye;
	zaxis.Normalized();
	xaxis = Cross((Vector3)pUp ,zaxis);
	xaxis.Normalized();
	yaxis = Cross(zaxis, xaxis);

	/*  zaxis = normal(At - Eye)
		xaxis = normal(cross(Up, zaxis))
		yaxis = cross(zaxis, xaxis)*/
	/*	xaxis.x           yaxis.x           zaxis.x          0
		xaxis.y           yaxis.y           zaxis.y          0
		xaxis.z           yaxis.z           zaxis.z          0
		- dot(xaxis, eye) - dot(yaxis, eye) - dot(zaxis, eye)  1*/


	pOut->_11 = xaxis.x;
	pOut->_12 = yaxis.x;
	pOut->_13 = zaxis.x;
	pOut->_14 = 0.0f;
	pOut->_21 = xaxis.y;
	pOut->_22 = yaxis.y;
	pOut->_23 = zaxis.y;
	pOut->_24 = 0.0f;
	pOut->_31 = xaxis.z;
	pOut->_32 = yaxis.z;
	pOut->_33 = zaxis.z;
	pOut->_34 = 0.0f;
	pOut->_41 = -dot(xaxis, pEye);
	pOut->_42 = -dot(yaxis, pEye);
	pOut->_43 = -dot(zaxis, pEye);
	pOut->_44 = 1.0f;

	return pOut;
}
Matrix4 * MatrixPerspectiveFovLH(Matrix4 * pOut, const FLOAT fovy, FLOAT Aspect, FLOAT zn, FLOAT zf)
{
	pOut->SetMatrixPerspectiveFovLH(fovy, Aspect, zn, zf);
	return pOut;
}
Matrix4 * MatrixOrthoLH(Matrix4 * pOut, FLOAT w, FLOAT h, FLOAT zn, FLOAT zf)
{
	pOut->SetMatrixOrthoLH(w, h, zn, zf);
	return pOut;
}
Matrix4 * MatrixIdentity(Matrix4 * pOut)
{
	pOut->SetIdentity();
	return pOut;
}
Vector3* Vec3TransformCoord(Vector3 *pOut, CONST Vector3 *pV, CONST Matrix4 *pM)
{
	Vector4 pC = ToVector4(pV,1);
	pC = pC * pM;
	return pOut;
}
Vector3 Cross(Vector3 left, Vector3 right)
{
	Vector3 returnValue;
	returnValue.x = left.y * right.z - left.z * right.y;
	returnValue.y = left.z * right.x - left.x * right.z;
	returnValue.z = left.x * right.y - left.y * right.x;
	return returnValue;
}
float dot(Vector3 left, Vector3 right)
{
	float returnValue = left.x*right.x + left.y*right.y + left.z*right.z;
	return returnValue;
}


Vector2 ToVector2(Vector3 value)
{
	return Vector2(value.x, value.y);
}

Vector2 ToVector2(Vector4 value)
{
	return Vector2(value.x, value.y);
}

Vector3 ToVector3(Vector2 value, FLOAT z)
{
	return Vector3(value.x, value.y, z);
}

Vector3 ToVector3(Vector4 value)
{
	return Vector3(value.x, value.y,value.z);
}

Vector4 ToVector4(Vector2 value,FLOAT z, FLOAT w)
{
	return Vector4(value.x, value.y, z, w);
}

Vector4 ToVector4(Vector3 value , FLOAT w)
{
	return Vector4(value.x, value.y, value.z,w);
}