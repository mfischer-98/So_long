#ifndef SO_LONG_H
#define SO_LONG_H

#include "../lib/mlx/mlx.h"
#include <X11/keysym.h>
#include <stdlib.h>

#define MALLOC_ERROR 1
#define WIDTH 1920
#define HEIGHT 1080

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_mlx_data
{
	void	*mlx;
	void	*win;
	t_img	img;
}				t_mlx_data;

#endif