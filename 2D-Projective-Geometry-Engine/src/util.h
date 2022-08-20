#pragma once

constexpr double kDblCmpEps = 1e-12;

inline bool dbl_cmp_eq(const double d1, const double d2)
{
    return d1 > d2 - kDblCmpEps && d1 < d2 + kDblCmpEps;
}