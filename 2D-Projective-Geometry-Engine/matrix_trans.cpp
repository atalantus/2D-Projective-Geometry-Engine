#include "matrix_trans.h"
#include "util.h"

matrix_trans::matrix_trans()
{
	m_ = {
		{1, 0, 0},
		{0, 1, 0},
		{0, 0, 1}
	};
}

matrix_trans::matrix_trans(const double angle, const double move_x, const double move_y)
{
	const double r = util::deg_to_rad(angle);
	double c = cos(r);
	double s = sin(r);

	m_ = {
		{c, -s, move_x},
		{s, c, move_y},
		{0, 0, 1}
	};
}

matrix_trans::matrix_trans(double a, double b, double c, double d, double e, double f)
{
	m_ = {
		{a, b, c},
		{d, e, f},
		{0, 0, 1}
	};
}

matrix_trans::matrix_trans(double a, double b, double c, double d, double e, double f, double g, double h, double i)
{
	m_ = {
		{a, b, c},
		{d, e, f},
		{g, h, i}
	};
}

vector_proj matrix_trans::apply(vector_proj v) const
{
	const double x = v.x(), y = v.y(), w = v.w();

	return {
		m_[0][0] * x + m_[0][1] * y + m_[0][2] * w,
		m_[1][0] * x + m_[1][1] * y + m_[1][2] * w,
		m_[2][0] * x + m_[2][1] * y + m_[2][2] * w
	};
}

double matrix_trans::det() const
{
	return m_[0][0] * (m_[1][1] * m_[2][2] - m_[1][2] * m_[2][1])
		- m_[0][1] * (m_[1][0] * m_[2][2] - m_[1][2] * m_[2][0])
		+ m_[0][2] * (m_[1][0] * m_[2][1] - m_[1][1] * m_[2][0]);
}

matrix_trans matrix_trans::find_trans_matrix(vector_proj pre_image_points[4], vector_proj image_points[4])
{
	const vector_proj a = {1, 0, 0}, b = {0, 1, 0}, c = {0, 0, 1}, d = {1, 1, 1};

	const matrix_trans m1 = {

	};

	const matrix_trans m2 = {

	};
}
