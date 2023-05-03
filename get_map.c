
#include "fdf.h"

void	map_dimensions(char *file, t_fdf *data)
{
	int		fd;
	char	*line;
	char	**line_width;

	fd = open(file, O_RDONLY);
	data->height = 0;
	data->width = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		data->height++;
		if (data->width == 0)
		{
			line_width = ft_split(line, ' ');
			while (line_width[data->width])
				data->width++;
			free_split(line_width);
		}			
		free(line);
	}
	close(fd);
}

void	allocate_matrix(t_fdf *data)
{
	int	i;

	data->matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	if (!data->matrix)
		return ;
	i = 0;
	while (i < data->height)
	{
		data->matrix[i] = (int *)malloc(sizeof(int) * (data->width + 1));
		i++;
	}
	data->matrix[i] = NULL;
}

void	set_row(char *line, int *row)
{
	int		i;
	char	**zs;

	zs = ft_split(line, ' ');
	i = 0;
	while (zs[i])
	{
		row[i] = ft_atoi(zs[i]) * 10;
		free(zs[i]);
		i++;
	}
	free(zs);
}

void	set_matrix(char *file, t_fdf *data)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(file, O_RDONLY);
	i = 0;
	while (i < data->height)
	{
		line = get_next_line(fd);
		set_row(line, data->matrix[i]);
		free(line);
		i++;
	}
	close(fd);
}

void	get_map(char *file, t_fdf *data)
{
	map_dimensions(file, data);
	allocate_matrix(data);
	set_matrix(file, data);
}
