#include "matrix_trans.h"

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
	double c = cos(angle);
	double s = sin(angle);

	m_ = {
		{c, -s, move_x},
		{s, c, move_y},
		{0, 0, 1}
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
