#include "minirt.h"

t_vec	vec_cross(t_vec v1, t_vec v2)
{
	t_vec	res;

	res.x = v1.y * v2.z - v1.z * v2.y;
	res.y = v1.z * v2.x - v1.x * v2.z;
	res.z = v1.x * v2.y - v1.y * v2.x;
	return (res);
}

double	get_ratio(int width, int height)
{
	if (height == 0)
		return (1.0);
	return ((double)width / (double)height);
}

bool	init_viewport(t_minirt *rt)
{
	double	fov_rad;
	double	aspect;
	t_vec	world_up;

	rt->viewport = ft_calloc(sizeof(t_viewport), 1);
	if (!rt->viewport)
		return (false);
	fov_rad = (rt->camera->fov * M_PI) / 180.0;
	aspect = get_ratio(rt->window->width, rt->window->height);
	rt->viewport->height = 2.0 * tan(fov_rad / 2.0);
	rt->viewport->width = rt->viewport->height * aspect;
	rt->viewport->normal = normalize(rt->camera->orientation);
	if (fabs(rt->viewport->normal.y) > 0.999)
		world_up = (t_vec){0, 0, 1};
	else
		world_up = (t_vec){0, 1, 0};
	rt->viewport->right = normalize(vec_cross(rt->viewport->normal, world_up));
	rt->viewport->up = normalize(vec_cross(rt->viewport->right, \
rt->viewport->normal));
	return (true);
}
