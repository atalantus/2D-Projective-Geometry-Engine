#pragma once
#include "../constants.h"

namespace math
{
    struct Complex
    {
    public:
        //-------------------------------------------------------------
        //                        CONSTRUCTOR
        //-------------------------------------------------------------
        Complex(const double real, const double imaginary)
            : real(real),
              imaginary(imaginary)
        {
        }

        //-------------------------------------------------------------
        //                          OPERATOR
        //-------------------------------------------------------------
        Complex operator +(const Complex& o) const
        {
            return {real + o.real, imaginary + o.imaginary};
        }

        Complex operator -(const Complex& o) const
        {
            return {real - o.real, imaginary - o.imaginary};
        }

        Complex operator *(const double o) const
        {
            return {real * o, imaginary * o};
        }

        Complex operator *(const Complex& o) const
        {
            return {real * o.real - imaginary * o.imaginary, real * o.imaginary + imaginary * o.real};
        }

        Complex operator /(const double o) const
        {
            return {real / o, imaginary / o};
        }

        Complex operator /(const Complex& o) const
        {
            return {
                    (real * o.real + imaginary * o.imaginary) / (imaginary * imaginary + o.imaginary * o.imaginary),
                    (imaginary * o.real - real * o.imaginary) / (imaginary * imaginary + o.imaginary * o.imaginary)
            };
        }

        //-------------------------------------------------------------
        //                          METHOD
        //-------------------------------------------------------------
        /**
         * \brief Calculates the complex conjugate of this number.
         * \return The complex conjugate
         */
        [[nodiscard]] Complex conjugate() const
        {
            return {real, -imaginary};
        }

        /**
         * \brief Checks if this number is real.
         * \return True if the number is real
         */
        [[nodiscard]] bool is_real() const
        {
            return imaginary < kDblCmpEps && imaginary > -kDblCmpEps;
        }

    private:
        //-------------------------------------------------------------
        //                          FIELD
        //-------------------------------------------------------------
        double real;
        double imaginary;
    };
}
