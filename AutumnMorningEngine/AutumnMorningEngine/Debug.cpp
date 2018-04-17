#include"Debug.h"

void Debug::Log(const char * value)
{
	printf(value);
	return;
}

void Debug::Log(Vector2 value)
{
	printf("(%.3f, %.3f)\n", value.X, value.Y);
	return;
}

void Debug::Log(Vector3 value)
{
	printf("(%.3f, %.3f, %.3f)\n", value.X, value.Y, value.Z);
	return;
}

void Debug::Log(Vector4 value)
{
	printf("(%.3f, %.3f, %.3f, %.3f)\n", value.X, value.Y, value.Z, value.W);
	return;
}