#include "vector_proj.h"
#include "constants.h"
#include <cstdlib>

vector_2d vector_proj::normalize_2d() const
{
	if (abs(w_) <= dbl_cmp_eps)
		return {x_, y_, true};

	return {x_ / w_, y_ / w_, false};
}

double& vector_proj::x()
{
	return x_;
}

double& vector_proj::y()
{
	return y_;
}

double& vector_proj::w()
{
	return w_;
}

double vector_proj::dot(const vector_proj a, const vector_proj b)
{
	return a.x_ * b.x_ + a.y_ * b.y_ + a.w_ * b.w_;
}

vector_proj vector_proj::cross(const vector_proj a, const vector_proj b)
{
	return {a.y_ * b.w_ - a.w_ * b.y_, a.w_ * b.x_ - a.x_ * b.w_, a.x_ * b.y_ - a.y_ * b.x_};
}

bool vector_proj::lies_on_line(const vector_proj p, const vector_proj l)
{
	return abs(dot(p, l)) <= dbl_cmp_eps;
}

vector_proj vector_proj::get_line(const vector_proj p, const vector_proj q)
{
	return cross(p, q);
}

vector_proj vector_proj::get_intersection(const vector_proj l, const vector_proj m)
{
	return cross(l, m);
}

vector_proj vector_proj::get_parallel(const vector_proj l, const vector_proj p)
{
	return cross(p, cross(l, {0, 0, 1}));
}

vector_proj vector_proj::get_perpendicular(const vector_proj l, const vector_proj p)
{
	vector_proj q = cross(l, {0, 0, 1});
	return cross(p, {q.y_, -q.x_, 0});
}

vector_proj vector_proj::get_projection(const vector_proj p, const vector_proj l)
{
	return cross(l, get_perpendicular(l, p));
}
