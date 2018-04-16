#include"Debug.h"

void Debug::Log(const char * value)
{
	printf(value);
	return;
}

void Debug::Log(const Vector3 value)
{
	printf("(%3.3f, %3.3f, %3.3f)\n", value.X, value.Y, value.Z);
	return;
}
