#include "fdf.h"

void	rotation(t_point *s_point, t_point *f_point, t_fdf *data)
{
	float	initial_x;
	float	initial_y;

	initial_x = s_point->x;
	//initial_y = s_point->y;
	s_point->x = initial_x * cos(data->rot_x) + s_point->z * sin(data->rot_x);
	s_point->z = -initial_x * sin(data->rot_x) + s_point->z * cos(data->rot_x);
	initial_x = f_point->x;
	//initial_y = f_point->y;
	f_point->x = initial_x * cos(data->rot_x) + f_point->z * sin(data->rot_x);
	f_point->z = -initial_x * sin(data->rot_x) + f_point->z * cos(data->rot_x);
	//initial_x = s_point->x;
	initial_y = s_point->y;
	s_point->y = initial_y * cos(data->rot_y) - s_point->z * sin(data->rot_y);
	s_point->z = initial_y * sin(data->rot_y) + s_point->z * cos(data->rot_y);
	//initial_x = f_point->x;
	initial_y = f_point->y;
	f_point->y = initial_y * cos(data->rot_y) - f_point->z * sin(data->rot_y);
	f_point->z = initial_y * sin(data->rot_y) + f_point->z * cos(data->rot_y);
}

void	zoom(t_point *s_point, t_point *f_point, t_fdf *data)
{
	s_point->x = s_point->x * data->zoom;
	s_point->y = s_point->y * data->zoom;
	f_point->x = f_point->x * data->zoom;
	f_point->y = f_point->y * data->zoom;
}

void	isometric(t_point *s_point, t_point *f_point)
{
	float	initial_x;
	float	initial_y;

	initial_x = s_point->x;
	initial_y = s_point->y;
	s_point->x = (initial_x - initial_y) * cos(0.523599);
	s_point->y = -s_point->z + (initial_x + initial_y) * sin(0.523599);
	initial_x = f_point->x;
	initial_y = f_point->y;
	f_point->x = (initial_x - initial_y) * cos(0.523599);
	f_point->y = -f_point->z + (initial_x + initial_y) * sin(0.523599);
}

void	parallel(t_point *s_point, t_point *f_point)
{
	s_point->x = s_point->x;
	s_point->y = s_point->y;
	f_point->x = f_point->x;
	f_point->y = f_point->y;
}

void	shitfting(t_point *s_point, t_point *f_point, t_fdf *data)
{
	s_point->x = s_point->x + data->shifting_x;
	s_point->y = s_point->y + data->shifting_y;
	f_point->x = s_point->x +data->shifting_x;
	f_point->y = s_point->y + data->shifting_y;
}

