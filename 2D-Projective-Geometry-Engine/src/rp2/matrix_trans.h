#pragma once
#include <vector>
#include "vector_proj.h"

/**
 * \brief Defines a transformation matrix in 2 dimensional space for projection vectors.
 */
class MatrixTrans
{
    std::vector<std::vector<double>> m_;

public:
    /**
     * \brief Initializes a transformation matrix with no transformation.
     */
    MatrixTrans();

    /**
     * \brief Initializes a simple transformation matrix with given rotation and translation.
     * \param angle Angle of the transformation
     * \param move_x Translation on the x-axis
     * \param move_y Translation of the y-axis
     */
    MatrixTrans(double angle, double move_x, double move_y);

    /**
     * \brief Initializes an affine transformation matrix with given transformation values.
     */
    MatrixTrans(double a, double b, double c, double d, double e, double f);

    /**
     * \brief Initializes a projective transformation matrix with given transformation values.
     */
    MatrixTrans(double a, double b, double c, double d, double e, double f, double g, double h, double i);

    /**
     * \brief Applies the transformation a projection vector.
     * \param v Projection vector
     * \return Transformed projection vector
     */
    vector_proj apply(vector_proj v) const;

    /**
     * \brief Calculates the determinant of this matrix.
     */
    double det() const;

    /**
     * \brief Calculates the transformation matrix used to transform 4 sample points.
     * \param pre_image_points The chosen 4 points previous to the transformation
     * \param image_points The chosen 4 points after the transformation
     */
    static MatrixTrans find_trans_matrix(vector_proj pre_image_points[4], vector_proj image_points[4]);
};
