#pragma once

#include<D3DX10math.h>
#include "Math.h"

class CameraClass
{
public:
	CameraClass();
	CameraClass(const CameraClass &);
	~CameraClass();
	
	void SetPosition(float, float, float);
	void SetRotation(float, float, float);

	Vector3 GetPosition();
	Vector3 GetRotation();

	void Render();
	void GetViewMatrix(D3DXMATRIX&);

private:
	float m_positionX, m_positionY, m_positionZ;
	float m_rotationX, m_rotationY, m_rotationZ;
	D3DXMATRIX m_viewMatrix;
};

