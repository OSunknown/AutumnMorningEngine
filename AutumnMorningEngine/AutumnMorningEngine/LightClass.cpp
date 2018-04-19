#include "LightClass.h"


LightClass::LightClass()
{
	Debug::Log("LightClass Awake");
}

LightClass::LightClass(const LightClass& other)
{
}

LightClass::~LightClass()
{
}

void LightClass::SetDiffuseColor(float red, float green, float blue, float alpha)
{
	m_diffuseColor = Vector4(red, green, blue, alpha);
	return;
}


void LightClass::SetDirection(float x, float y, float z)
{
	m_direction = Vector3(x, y, z);
	return;
}


Vector4 LightClass::GetDiffuseColor()
{
	Debug::Log("LightClass GetDiffuseColor \n");
	Debug::Log(m_diffuseColor);
	return m_diffuseColor;
}


Vector3 LightClass::GetDirection()
{
	Debug::Log("LightClass GetDirection \n");
	Debug::Log(m_direction);
	return m_direction;
}