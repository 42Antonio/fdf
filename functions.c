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

// void	rotation_x_axe(t_point *s_point, t_point *f_point, t_fdf *data)
// {
// 	float	s_init_y;
// 	float	s_init_z;
// 	float	f_init_y;
// 	float	f_init_z;

// 	s_init_y = s_point->y;
// 	s_init_z = s_point->z;
// 	f_init_y = f_point->y;
// 	f_init_z = f_point->z;
// 	s_point->y = s_init_y * cos(data->rot_x) + s_init_z * sin(data->rot_x);
// 	s_point->z = -s_init_y * sin(data->rot_x) + s_init_z * cos(data->rot_x);
// 	f_point->y = f_init_y * cos(data->rot_x) + f_init_z * sin(data->rot_x);
// 	f_point->z = -f_init_y * sin(data->rot_x) + f_init_z * cos(data->rot_x);
// }

// void	rotation_y_axe(t_point *s_point, t_point *f_point, t_fdf *data)
// {
// 	float	s_init_x;
// 	float	s_init_z;
// 	float	f_init_x;
// 	float	f_init_z;

// 	s_init_x = s_point->x;
// 	s_init_z = s_point->z;
// 	f_init_x = f_point->x;
// 	f_init_z = f_point->z;
// 	s_point->x = s_init_x * cos(data->rot_x) - s_init_z * sin(data->rot_x);
// 	s_point->z = s_init_x * sin(data->rot_x) + s_init_z * cos(data->rot_x);
// 	f_point->x = f_init_x * cos(data->rot_y) - f_init_z * sin(data->rot_y);
// 	f_point->z = f_init_x * sin(data->rot_y) + f_init_z * cos(data->rot_y);
// }

// void	rotation_x_axe(t_point *s_point, t_point *f_point, t_fdf *data)
// {
// 	float	s_init_y;
// 	float	s_init_z;
// 	float	f_init_y;
// 	float	f_init_z;
// 	float	s_module;
// 	float	f_module;
// 	float	smodule;
// 	float	fmodule;

// 	s_init_y = s_point->y;
// 	s_init_z = s_point->z;
// 	f_init_y = f_point->y;
// 	f_init_z = f_point->z;
// 	s_module = sqrt(s_point->x * s_point->x + s_point->y * s_point->y + s_point->z * s_point->z);
// 	f_module = sqrt(f_point->x * f_point->x + f_point->y * f_point->y + f_point->z * f_point->z);
// 	(void)s_module;
// 	(void)f_module;
// 	printf("\ns_module es: %f", s_module);
// 	smodule = sqrt(s_point->x * s_point->x + s_init_y * cos(data->rot_x) + s_init_z * sin(data->rot_x) * s_init_y * cos(data->rot_x) + s_init_z * sin(data->rot_x) + -s_init_y * sin(data->rot_x) + s_init_z * cos(data->rot_x) * -s_init_y * sin(data->rot_x) + s_init_z * cos(data->rot_x));
// 	fmodule = sqrt(f_point->x * f_point->x + f_init_y * cos(data->rot_x) + f_init_z * sin(data->rot_x)*f_init_y * cos(data->rot_x) + f_init_z * sin(data->rot_x) + -f_init_y * sin(data->rot_x) + f_init_z * cos(data->rot_x)*-f_init_y * sin(data->rot_x) + f_init_z * cos(data->rot_x));
// 	(void)smodule;
// 	(void)fmodule;
// 	printf("\nsmodule es: %f", smodule);
// 	s_point->y = (s_init_y * cos(data->rot_x) + s_init_z * sin(data->rot_x));
// 	s_point->z = -s_init_y * sin(data->rot_x) + s_init_z * cos(data->rot_x);
// 	f_point->y = f_init_y * cos(data->rot_x) + f_init_z * sin(data->rot_x);
// 	f_point->z = -f_init_y * sin(data->rot_x) + f_init_z * cos(data->rot_x);
// }

void	zoom(t_point *s_point, t_point *f_point, t_fdf *data)
{
	s_point->x = s_point->x * data->zoom;
	s_point->y = s_point->y * data->zoom;
	f_point->x = f_point->x * data->zoom;
	f_point->y = f_point->y * data->zoom;
}

void	moving(t_point *s_point, t_point *f_point, t_fdf *data)
{
	s_point->x += data->moving_x;
	s_point->y += data->moving_y;
	f_point->x += data->moving_x;
	f_point->y += data->moving_y;
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

