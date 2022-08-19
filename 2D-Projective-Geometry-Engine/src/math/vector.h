#pragma once
#include <vector>
#include <format>

#include "exceptions.h"

namespace math
{
    template <typename T>
    struct Vector
    {
    public:
        //-------------------------------------------------------------
        //                        CONSTRUCTOR
        //-------------------------------------------------------------
        Vector(const std::initializer_list<T> value)
            : value(value),
              dimension(value.size())
        {
        }

        explicit Vector(const std::vector<T>& value)
            : value(value),
              dimension(value.size())
        {
        }

        explicit Vector(const uint32_t dimension)
            : value(dimension),
              dimension(dimension)
        {
        }

        //-------------------------------------------------------------
        //                          OPERATOR
        //-------------------------------------------------------------
        T operator [](const uint32_t i) const
        {
            return value[i];
        }

        T& operator[](const uint32_t i)
        {
            return value[i];
        }

        //-------------------------------------------------------------
        //                          METHOD
        //-------------------------------------------------------------
        [[nodiscard]] uint32_t get_dimension() const
        {
            return dimension;
        }

        /**
         * \brief Calculates the dot product between this vector and another.
         * \param v The other vector
         * \return The dot product
         */
        [[nodiscard]] T dot_product(const Vector& v) const
        {
            if (dimension != v.dimension)
                throw DimensionMismatch(std::format("Can not compute dot product of vectors with different dimension {0} and {1}."));

            T x = 0;

            for (uint32_t i = 0; i < dimension; ++i)
            {
                x += value[i] * v[i];
            }

            return x;
        }

    private:
        //-------------------------------------------------------------
        //                          FIELD
        //-------------------------------------------------------------
        std::vector<T> value;
        uint32_t dimension;
    };
}
