#pragma once

#include  <D3DX10math.h>
#include "Math.h"
#include "Debug.h"
class LightClass
{
public:
	LightClass();
	LightClass(const LightClass&);
	~LightClass();

	void SetDiffuseColor(float, float, float, float);
	void SetDirection(float, float, float);
	float a;
	Vector4 GetDiffuseColor();
	Vector3 GetDirection();
private:
	Vector4 m_diffuseColor;
	Vector3 m_direction;
};

