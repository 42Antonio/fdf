#include	"fdf.h"

void	check_arg(int ac, char **av)
{
	if (ac != 2)
	{
		ft_printf("Ruta no válida, siga el patrón: ./fdf <file_path>\n");
		exit(1);
	}
	if (open(av[0], O_RDONLY) == -1)
	{
		perror("Error: ");
		close(open(av[0], O_RDONLY));
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
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	data->shifting_x = 500;
	data->shifting_y = 500;
	data->zoom = 20;
	data->isometric_parallel = 1;
	data->rot_x = 0;
	data->rot_y = 0;
	
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	atexit(leaks);
	check_arg(ac, &av[1]);
	data = (t_fdf *)malloc(sizeof(t_fdf));
	get_map(argv[1], data);
	init(data);
	picture(data);
	mlx_key_hook(data->win_ptr, key_hook, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}


//Programa que lee un archivo con la función get_next_line y pone un pixel blanco en pantalla cuando pulsas la tecla 'a' usando la librería MLX
/*
#include    "mlx/mlx.h"
#include	"libft/libft.h"
#include	<fcntl.h>
#include	<stdio.h>

typedef struct	s_vars {               			  // Estructura que contiene los punteros a la librería MLX
	void	*mlx_ptr;
	void	*win_ptr;
}				t_vars;

int key_hook(int keycode, t_vars *vars)
{
	if (keycode == 0) // Si se pulsa la tecla 'a'
		mlx_pixel_put(vars->mlx_ptr, vars->win_ptr, 250, 250, 0xFFFFFF); // vars->mlx_ptr es equivalente a (*vars).mlx_ptr
	return (0);
}

int	main()
{
	t_vars	vars;
	int		fd;
	char	*line;

	fd = open("tests/43.fdf", O_RDONLY);
	if( fd == -1) {
      perror("Error: ");
      return(-1);
   }
	while (1)
	{
		line = get_next_line(fd); // get_next_line lee una línea del archivo y la guarda en la variable line	
		if (line == NULL)
			break ;
		ft_printf("%s", line); 
		free(line);
	}
    close(fd);

	vars.mlx_ptr = mlx_init();                                       // Inicializa la librería MLX
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, 500, 500, "MLX 42"); // Crea una ventana de 500x500 con el título "MLX 42"
	mlx_key_hook(vars.win_ptr, key_hook, &vars);                     // key_hook es una función que se ejecuta cuando se pulsa una tecla, con la estructura vars pasamos los argumentos.
	mlx_loop(vars.mlx_ptr);                                          // Bucle infinito que mantiene la ventana abierta
	return (0);
}*/