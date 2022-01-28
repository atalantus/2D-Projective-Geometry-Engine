#pragma once
#include <vector>

#include "vector_proj.h"

/**
 * \brief Defines a transformation matrix in 2 dimensional space for projection vectors.
 */
class matrix_trans
{
	std::vector<std::vector<double>> m_;

public:
	/**
	 * \brief Initializes a transformation matrix with no transformation.
	 */
	matrix_trans();

	/**
	 * \brief Initializes a transformation matrix with a given transformation.
	 * \param angle Angle of the transformation
	 * \param move_x Translation on the x-axis
	 * \param move_y Translation of the y-axis
	 */
	matrix_trans(double angle, double move_x, double move_y);

	/**
	 * \brief Applies the transformation a projection vector.
	 * \param v Projection vector
	 * \return Transformed projection vector
	 */
	vector_proj apply(const vector_proj v) const;
};
