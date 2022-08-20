#include <cassert>

#include "../util.h"
#include "complex.h"
#include "vector.h"
#include "matrix.h"

int main(int argc, char* argv[])
{
    using namespace math;

    const auto c1 = Complex(1.5, 0.5);
    const auto c2 = c1 + Complex(6.5, -2.75);
    const auto c3 = c1 - Complex(6.5, 0.5);
    const auto c4 = c1 * 4;
    const auto c5 = c1 * Complex(6.5, 0.5);
    const auto c6 = c1 / 4;
    const auto c7 = c1 / Complex(6.5, 0.5);

    assert(!c2.is_real());
    assert(dbl_cmp_eq(c2.real, 8));
    assert(dbl_cmp_eq(c2.imaginary, -2.25));

    assert(c3.is_real());
    assert(dbl_cmp_eq(c3.real, -5));
    assert(dbl_cmp_eq(c3.imaginary, 0));

    assert(dbl_cmp_eq(c4.real, 6));
    assert(dbl_cmp_eq(c4.imaginary, 2));

    assert(dbl_cmp_eq(c5.real, 9.5));
    assert(dbl_cmp_eq(c5.imaginary, 4));
    
    assert(dbl_cmp_eq(c6.real, 0.375));
    assert(dbl_cmp_eq(c6.imaginary, 0.125));

    assert(dbl_cmp_eq(c7.real, 0.235294117647));
    assert(dbl_cmp_eq(c7.imaginary, 0.058823529411));

    const auto v1 = Vector<double>({2.75, 17.25, -5});
    const auto v2 = v1 * 3;
    const auto v3 = v1 / 4;
    const auto v4 = v1 + Vector<double>({-0.5, 2, 5});
    const auto v5 = v1 - Vector<double>({-0.5, 2, 5});
    const auto v6 = v1.dot_product(Vector<double>({-0.5, 2, 5}));

    assert(v1.get_dimension() == 3);

    assert(dbl_cmp_eq(v2[0], 8.25));
    assert(dbl_cmp_eq(v2[1], 51.75));
    assert(dbl_cmp_eq(v2[2], -15));

    assert(dbl_cmp_eq(v3[0], 0.6875));
    assert(dbl_cmp_eq(v3[1], 4.3125));
    assert(dbl_cmp_eq(v3[2], -1.25));

    assert(dbl_cmp_eq(v4[0], 2.25));
    assert(dbl_cmp_eq(v4[1], 19.25));
    assert(dbl_cmp_eq(v4[2], 0));

    assert(dbl_cmp_eq(v5[0], 3.25));
    assert(dbl_cmp_eq(v5[1], 15.25));
    assert(dbl_cmp_eq(v5[2], -10));

    assert(dbl_cmp_eq(v6, 8.125));
}
