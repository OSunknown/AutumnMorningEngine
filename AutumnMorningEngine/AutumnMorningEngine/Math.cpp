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
	Vector3 v, r, u;
	v = (Vector3)pAt - (Vector3)pEye;
	v.Normalized();
	r = Cross((Vector3)pUp ,v);
	r.Normalized();
	u = Cross(v, r);

	/*  zaxis = normal(At - Eye)
		xaxis = normal(cross(Up, zaxis))
		yaxis = cross(zaxis, xaxis)*/
	/*	xaxis.x           yaxis.x           zaxis.x          0
		xaxis.y           yaxis.y           zaxis.y          0
		xaxis.z           yaxis.z           zaxis.z          0
		- dot(xaxis, eye) - dot(yaxis, eye) - dot(zaxis, eye)  1*/
	Vector4 mList[4] = {
		Vector4(r.x,u.x,v.x,0),
		Vector4(r.y,u.y,v.y,0),
		Vector4(r.z,u.z,v.z,0),
		Vector4(-dot(r,pEye),u.x,v.x,0)
	};
	return nullptr;
}
Matrix4 * MatrixPerspectiveFovLH(Matrix4 * pOut, const FLOAT fovy, FLOAT Aspect, FLOAT zn, FLOAT zf)
{
	return nullptr;
}
Vector3* Vec3TransformCoord(Vector3 *pOut, CONST Vector3 *pV, CONST Matrix4 *pM)
{
	Vector4 pC(pV,1);
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