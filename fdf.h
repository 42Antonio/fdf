#ifndef FDF_H
# define FDF_H
# include	"mlx/mlx.h"
# include	"libft/libft.h"
# include	<fcntl.h>
# include	<math.h>
# include	<stdio.h>

typedef struct s_fdf
{
	int			height;
	int			width;
	int			**matrix;
    void		*mlx_ptr;
	void		*win_ptr;
    int			color;
    int			iso_para;
	int			zoom;
	int			shifting_x;
	int			shifting_y;
	float		rot_x;
	float		rot_y;
}	t_fdf;

typedef struct s_point
{
	float		x;
	float		y;
	float		z;
}	t_point;

/*
**	Keys
*/

// shiffing
# define ARROW_UP			126
# define ARROW_DOWN			125
# define ARROW_LEFT			123
# define ARROW_RIGHT		124
// zoom
# define KEY_PLUS			69
# define KEY_MINUS			78
// other
# define KEY_ESC			53
// rotation x axis (up and down)
# define KEY_W				13
# define KEY_S				1
// rotation y axis (left and right)
# define KEY_A				0
# define KEY_D				2
// reset all
# define KEY_R				15
// projection
# define KEY_P				35

void	get_map(char *file_name, t_fdf *data);
void	picture(t_fdf *data);
int		key_hook(int keycode, t_fdf *data);
void	isometric(t_point *s_point, t_point *f_point);
void	zoom(t_point *s_point, t_point *f_point, t_fdf *data);
void	shitfting(t_point *s_point, t_point *f_point, t_fdf *data);
void	init(t_fdf *data);
void	check_arguments(int argc, char **argv);
void	leaks(void);
void	free_split(char **split);
void	rotation(t_point *s_point, t_point *f_point, t_fdf *data);
void	parallel(t_point *s_point, t_point *f_point);
#endif