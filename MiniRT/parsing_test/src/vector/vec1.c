#include "minirt.h"

float	vectlen(t_vector v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

t_vector	*normalize(t_vector *v)
{
	float	norm;

	norm = 1 / vectlen(*v);
	v->x *= norm;
	v->y *= norm;
	v->z *= norm;
	return (v);
}

t_vector	vect_add(t_vector v1, t_vector v2)
{
	t_vector	vec;

	vec.x = v1.x + v2.x;
	vec.y = v1.y + v2.y;
	vec.z = v1.z + v2.z;
	return (vec);
}

t_vector	vect_sub(t_vector v1, t_vector v2)
{
	t_vector	vec;

	vec.x = v2.x - v1.x;
	vec.y = v2.y - v1.y;
	vec.z = v2.z - v1.z;
	return (vec);
}

t_vector	vect_multi(t_vector v, float f)
{
	t_vector	vec;

	vec.x = v.x * f;
	vec.y = v.y * f;
	vec.z = v.z * f;
	return (vec);
}
