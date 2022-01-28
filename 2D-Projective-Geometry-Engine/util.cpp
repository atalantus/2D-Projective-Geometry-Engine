#include "util.h"
#define _USE_MATH_DEFINES
#include "cmath"

double util::deg_to_rad(const double deg)
{
	return deg * M_PI / 180;
}
