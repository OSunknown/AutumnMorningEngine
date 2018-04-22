#include"Debug.h"

void Debug::Log(const char * value)
{
	printf(value);
	return;
}

void Debug::Log(const float value)
{
	printf("%f \n",value);
	return;
}

void Debug::Log(Vector2 value)
{
	printf("(%.3f, %.3f)\n", value.x, value.y);
	return;
}

void Debug::Log(Vector3 value)
{
	printf("(%f, %f, %f)\n", value.x, value.y, value.z);
	return;
}

void Debug::Log(const Vector4& value)
{
	printf("(%f, %f, %f, %f)\n", value.x, value.y, value.z, value.w);
	return;
}

void Debug::Log(D3DXVECTOR3 value)
{
	printf("(%.3f, %.3f, %.3f)\n", value.x, value.y, value.z);
}

void Debug::Log(D3DXVECTOR4 value)
{
	printf("(%.3f, %.3f, %.3f, %.3f)\n", value.x, value.y, value.z, value.w);
}