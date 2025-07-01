#ifndef SO_LONG_H
#define SO_LONG_H

#include "../lib/mlx/mlx.h"
#include <X11/keysym.h>
#include <stdlib.h>
#include <stdio.h>

#define MALLOC_ERROR 1
#define WIDTH 1920
#define HEIGHT 1080

typedef struct s_mlx_data
{
	void	*mlx;
	void	*win;
	void	*img_player;
	void	*img_floor;
	int		x;
	int		y;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_width;
	int		img_height;
}				t_mlx_data;

int handle_input(int keysym, t_mlx_data *data);
int player_moves(int keysym, t_mlx_data *data);

#endif