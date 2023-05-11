#include	"fdf.h"

void	check_arguments(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Utiliza una ruta de fichero válida: ./fdf <file_path>\n");
		exit(1);
	}
	if (open(argv[0], O_RDONLY) == -1)
	{
		perror("Error:");
		close(open(argv[0], O_RDONLY));
		exit(1);
	}
}

void	leaks(void)
{
	system("leaks -q fdf");
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
}

void	init(t_fdf *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "fdf Project");
	data->moving_x = 450;
	data->moving_y = 400;
	data->zoom = 20;
	data->rot_x = 0;
	data->rot_y = 0;
	data->iso_para = 1;
}

int	clean_close(t_fdf *vars)
{
	mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	exit(EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_fdf	*data;

	atexit(leaks);
	check_arguments(ac, &av[1]);
	data = (t_fdf *)malloc(sizeof(t_fdf));
	get_map(av[1], data);
	init(data);
	draw(data);
	mlx_key_hook(data->win_ptr, key_hook, data);
	mlx_hook(data->win_ptr, 17, 0, clean_close, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
