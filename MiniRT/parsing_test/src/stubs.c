#include "minirt.h"
#include <stddef.h>


bool init_scene(t_minirt *minirt, char *filename)
{
    (void)minirt;
    (void)filename;
    return true;
}

bool render_scene(t_minirt *minirt)
{
    (void)minirt;
    return true;
}

int handle_mouse(int button, int x, int y, void *param)
{
    (void)button;
    (void)x;
    (void)y;
    (void)param;
    return 0;
}
