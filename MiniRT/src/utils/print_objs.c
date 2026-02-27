#include "minirt.h"

#include <stdio.h>

void	print_rgb(t_rgb c)
{
	printf("RGB: (%u, %u, %u)\n", c.r, c.g, c.b);
}

void	print_vector(char *name, t_vector v)
{
	printf("%s: (%.3f, %.3f, %.3f)\n", name, v.x, v.y, v.z);
}

void	print_camera(t_camera *cam)
{
	if (!cam)
	{
		printf("Camera: NULL\n");
		return ;
	}
	printf("Camera:\n");
	print_vector("  position", cam->position);
	print_vector("  orientation", cam->orientation);
	printf("  fov: %.2f\n", cam->fov);
	printf("  is_exist: %d\n", cam->exists);
}

void	print_ambient(t_amb_light *amb)
{
	if (!amb)
	{
		printf("Ambient light: NULL\n");
		return ;
	}
	printf("Ambient light:\n");
	printf("  ratio: %.2f\n", amb->ratio);
	print_rgb(amb->color);
}

void	print_lights(t_light *light)
{
	int	i;

	i = 0;
	if (!light)
	{
		printf("Lights: NULL\n");
		return ;
	}
	while (light)
	{
		printf("Light #%d:\n", i++);
		print_vector("  position", light->position);
		printf("  brightness: %.2f\n", light->brightness);
		print_rgb(light->color);
		light = light->next;
	}
}

void	print_sphere(t_sphere *s)
{
	printf("  Sphere:\n");
	print_vector("    center", s->center);
	printf("    radius: %.2f\n", s->radius);
	printf("    diameter: %.2f\n", s->diameter);
	print_rgb(s->color);
}

void	print_plane(t_plane *p)
{
	printf("  Plane:\n");
	print_vector("    center", p->center);
	print_vector("    normal", p->normal);
	print_rgb(p->color);
}

void	print_cylinder(t_cylinder *c)
{
	printf("  Cylinder:\n");
	print_vector("    center", c->center);
	print_vector("    normal", c->normal);
	printf("    radius: %.2f\n", c->radius);
	printf("    diameter: %.2f\n", c->diameter);
	printf("    height: %.2f\n", c->height);
	print_rgb(c->color);
}

void	print_objects(t_obj *obj)
{
	int	i;

	i = 0;
	if (!obj)
	{
		printf("Objects: NULL\n");
		return ;
	}
	while (obj)
	{
		printf("Object #%d:\n", i++);
		if (obj->shape == SPHERE)
			print_sphere((t_sphere *)obj->data);
		else if (obj->shape == PLANE)
			print_plane((t_plane *)obj->data);
		else if (obj->shape == CYLINDER)
			print_cylinder((t_cylinder *)obj->data);
		else
			printf("  Unknown shape\n");
		obj = obj->next;
	}
}

void	print_minirt(t_minirt *rt)
{
	if (!rt)
	{
		printf("minirt: NULL\n");
		return ;
	}
	printf("===== MINI RT DATA =====\n");
	print_camera(rt->camera);
	print_ambient(rt->amb_light);
	print_lights(rt->light);
	print_objects(rt->objects);
	printf("========================\n");
}
