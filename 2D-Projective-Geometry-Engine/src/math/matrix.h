#pragma once
#include <vector>

#include "vector.h"

namespace math
{
    template <typename T>
    struct Matrix
    {
    public:
        //-------------------------------------------------------------
        //                        CONSTRUCTOR
        //-------------------------------------------------------------
        Matrix(const std::initializer_list<std::initializer_list<T>> column_values_list)
            : value(0)
        {
            if (column_values_list.size() > 0)
            {
                uint32_t row_dim = column_values_list.begin()->size();

                for (const std::initializer_list<T>& column_value : column_values_list)
                {
                    if (column_value.size() != row_dim)
                        throw DimensionMismatch(std::format("Can not create matrix of vectors with different dimensions {0} and {1}.",
                                                            row_dim,
                                                            column_value.size()));

                    value.emplace_back(column_value);
                }
            }
        }

        Matrix(const std::initializer_list<Vector<T>> column_vector_list)
            : value(column_vector_list)
        {
            if (column_vector_list.size() > 0)
            {
                uint32_t row_dim = column_vector_list.begin()->get_dimension();

                for (const Vector<T>& v : column_vector_list)
                {
                    if (v.get_dimension() != row_dim)
                        throw DimensionMismatch(std::format("Can not create matrix of vectors with different dimensions {0} and {1}.",
                                                            row_dim,
                                                            v.get_dimension()));
                }
            }
        }

        Matrix(const uint32_t row_dimension, const uint32_t column_dimension)
            : value{std::vector(column_dimension, Vector<T>(row_dimension))}
        {
        }

        //-------------------------------------------------------------
        //                          OPERATOR
        //-------------------------------------------------------------
        Vector<T> operator [](const uint32_t i) const
        {
            return value[i];
        }

        Vector<T>& operator[](const uint32_t i)
        {
            return value[i];
        }

        //-------------------------------------------------------------
        //                          METHOD
        //-------------------------------------------------------------
        [[nodiscard]] uint32_t column_dimension() const
        {
            return value.size();
        }

        [[nodiscard]] uint32_t row_dimension() const
        {
            if (!value.empty())
                return value[0].get_dimension();
            return 0;
        }

        [[nodiscard]] Matrix transpose() const
        {
            Matrix t(column_dimension(), row_dimension());


            return t;
        }

    private:
        //-------------------------------------------------------------
        //                          FIELD
        //-------------------------------------------------------------
        /**
         * \brief Vector of column vectors of this matrix.
         */
        std::vector<Vector<T>> value;
    };
}
