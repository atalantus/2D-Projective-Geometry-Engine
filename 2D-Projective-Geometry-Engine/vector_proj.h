#pragma once

/**
 * \brief Represents a point in the projected 2D plane.
 *
 * Can lie at infinity.
 */
struct vector_2d
{
	const double x, y;
	const bool at_infinity;
};

/**
 * \brief Defines a 3 dimensional vector projecting onto a 2D plane at w = 1.
 */
class vector_proj
{
	// x, y, w components
	double x_, y_, w_;

public:
	// Initializes a zero vector in the 2D projected plane.
	vector_proj() : x_(0), y_(0), w_(1)
	{
	}

	// Initializes a vector with given values in the 2D projected plane.
	vector_proj(const double x, const double y)
		: x_(x), y_(y), w_(1)
	{
	}

	// Initializes a vector with given values.
	vector_proj(const double x, const double y, const double w)
		: x_(x), y_(y), w_(w)
	{
	}

	/**
	 * \brief Normalizes this vector onto the 2D projected plane.
	 * \return The Point in the 2D projected plane represented by this projection vector.
	 */
	vector_2d normalize_2d() const;

	// The x-component of the vector.
	double& x();

	// The y-component of the vector.
	double& y();

	// The w-component of the vector.
	double& w();

	// Computes the dot product of two vectors.
	static double dot(vector_proj a, vector_proj b);

	// Computes the cross product of two vectors.
	static vector_proj cross(vector_proj a, vector_proj b);

	/**
	 * \brief Checks if a given point lies on the given line in the 2D projected plane.
	 * \param p Point represented by projection vector p
	 * \param l Line represented by projection vector l
	 * \return True if the point lies on the line otherwise False
	 */
	static bool lies_on_line(vector_proj p, vector_proj l);

	/**
	 * \brief Calculates the line going through 2 given points in the 2D projected plane.
	 * \param p Point represented by projection vector p
	 * \param q Point represented by projection vector q
	 * \return The projection vector representing the line
	 */
	static vector_proj get_line(vector_proj p, vector_proj q);

	/**
	 * \brief Calculates the point of intersection of two given lines.
	 * \param l Line represented by projection vector l
	 * \param m Line represented by projection vector m
	 * \return The projection vector representing the intersection point in the 2D projected plane. (Can be at infinity.)
	 */
	static vector_proj get_intersection(vector_proj l, vector_proj m);

	/**
	 * \brief Calculates the line going through a given point that is parallel to a given line.
	 * \param l Line represented by projection vector l
	 * \param p Point represented by projection vector p
	 * \return The projection vector representing the line
	 */
	static vector_proj get_parallel(vector_proj l, vector_proj p);

	/**
	 * \brief Calculates the line going through a given point that is perpendicular to a given line.
	 * \param l Line represented by projection vector l
	 * \param p Point represented by projection vector p
	 * \return The projection vector representing the line
	 */
	static vector_proj get_perpendicular(vector_proj l, vector_proj p);

	/**
	 * \brief Calculates the projection of a point onto a line.
	 * \param p Point represented by projection vector p
	 * \param l Line represented by projection vector l
	 * \return The projection vector representing the projected point
	 */
	static vector_proj get_projection(vector_proj p, vector_proj l);
};
