#include "fdf.h"

void	moving_keys(int keycode, t_fdf *data)
{
	if (keycode == ARROW_UP)
		data->moving_y -= 10;
	if (keycode == ARROW_DOWN)
		data->moving_y += 10;
	if (keycode == ARROW_LEFT)
		data->moving_x -= 10;
	if (keycode == ARROW_RIGHT)
		data->moving_x += 10;
}

void	zoom_keys(int keycode, t_fdf *data)
{
	if (keycode == KEY_PLUS)
		data->zoom += 10;
	if (keycode == KEY_MINUS)
		data->zoom -= 10;
}

void	rotation_keys(int keycode, t_fdf *data)
{
	if (keycode == KEY_D)
		data->rot_x += 0.1;
	if (keycode == KEY_A)
		data->rot_x -= 0.1;
	if (keycode == KEY_W)
		data->rot_y += 0.1;
	if (keycode == KEY_S)
		data->rot_y -= 0.1;
}

void	projection_keys(int keycode, t_fdf *data)
{
	if (keycode == KEY_P)
	{
		if (data->iso_para == 1)
			data->iso_para= 2;
		else
			data->iso_para = 1;
	}
}

int	key_hook(int keycode, t_fdf *data)
{
	printf("keycode: %d\n", keycode);
	if (keycode == KEY_ESC)
		exit(0);
	if (keycode == KEY_I)
	{
		data->moving_x = 450;
		data->moving_y = 400;
		data->zoom = 20;
		data->rot_x = 0;
		data->rot_y = 0;
	}
	moving_keys(keycode, data);
	zoom_keys(keycode, data);
	rotation_keys(keycode, data);
	projection_keys(keycode, data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}