#pragma once
#include <stdio.h>
#include "Math.h"
struct Debug
{
public:
	static void Log(const char * value);
	static void Log(const Vector3 value);
};