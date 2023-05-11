#include "fdf.h"

void	color(t_point s_point, t_point f_point, t_fdf *data)
{
	if (s_point.z == f_point.z)
	{
		if (s_point.z != 0)
			data->color = 0xFF0000;
		else
			data->color = 0x00FF00;
	}
		
	else if ((s_point.z > f_point.z) || (s_point.z < f_point.z))
		data->color = 0xFFFF00;
}

// void	color(t_point s_point, t_point f_point, t_fdf *data)
// {
// 	if (s_point.z || f_point.z)
// 		data->color = 0x00FF00;
// 	else
// 		data->color = 0xFFFFFF;
// }

void	distance(t_point s_point, t_point f_point, float *x_step,
		float *y_step)
{
	float	max;

	*x_step = f_point.x - s_point.x;
	*y_step = f_point.y - s_point.y;
	max = fmaxf(fabsf(*x_step), fabsf(*y_step));
	*x_step /= max;
	*y_step /= max;
}

void	z_values(t_point *s_point, t_point *f_point, t_fdf *data)
{
	s_point->z = data->matrix[(int)s_point->y][(int)s_point->x];
	f_point->z = data->matrix[(int)f_point->y][(int)f_point->x];
}

void	line(t_point s_point, t_point f_point, t_fdf *data)
{
	float	x_step;
	float	y_step;

	z_values(&s_point, &f_point, data);
	rotation(&s_point, &f_point, data);
	// rotation_x_axe(&s_point, &f_point, data);
	// rotation_y_axe(&s_point, &f_point, data);
	zoom(&s_point, &f_point, data);
	color(s_point, f_point, data);
	if (data->iso_para == 1)
		isometric(&s_point, &f_point);
	else if (data->iso_para == 2)
		parallel(&s_point, &f_point);
	moving(&s_point, &f_point, data);
	distance(s_point, f_point, &x_step, &y_step);
	while ((int)(s_point.x - f_point.x) || (int)(s_point.y - f_point.y))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, s_point.x,
			s_point.y, data->color);
		s_point.x = s_point.x + x_step;
		s_point.y = s_point.y + y_step;
	}
}

void	draw(t_fdf *data)
{
	t_point	starting_point;
	t_point	final_point;

	starting_point.y = 0;
	while (starting_point.y < data->height)
	{
		starting_point.x = 0;
		while (starting_point.x < data->width)
		{
			if (starting_point.x < data->width - 1)
			{
				final_point.x = starting_point.x + 1;
				final_point.y = starting_point.y;
				line(starting_point, final_point, data);
			}
			if (starting_point.y < data->height - 1)
			{
				final_point.x = starting_point.x;
				final_point.y = starting_point.y + 1;
				line(starting_point, final_point, data);
			}
			starting_point.x++;
		}
		starting_point.y++;
	}
}
