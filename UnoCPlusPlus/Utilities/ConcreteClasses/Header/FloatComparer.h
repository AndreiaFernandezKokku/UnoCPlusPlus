#pragma once
#include <corecrt_math.h>

static const float EPSILON = 0.05f;

class FloatComparer
{
public:
	static bool AreSame(float a, float b)
	{
		return fabs(a - b) < EPSILON;
	}
};