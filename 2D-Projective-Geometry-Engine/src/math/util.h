#pragma once
#include "constants.h"

namespace math
{
    inline double deg_to_rad(const double deg)
    {
        return deg * kPi / 180;
    }
}
