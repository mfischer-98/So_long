#ifndef SO_LONG_H
#define SO_LONG_H

#include "../lib/mlx/mlx.h"
#include <X11/keysym.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "../lib/libft/libft.h"

#define MALLOC_ERROR 1
#define WIDTH 1920
#define HEIGHT 1080

typedef struct s_map
{
	int		width;
	int		height;
	int		is_collectable;
	int		is_floor;
	int		is_exit;
	int		is_player;
	char	**design;
}			t_map;

typedef struct s_player
{
	void	*img;
	int		img_width;
	int		img_height;
	int		x;
	int		y;
}			t_player;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	int		img_width;
	int		img_height;
	int		x;
	int		y;
}				t_data;

// Map
void ft_initialize(t_map *map);
int	parsing_map(int argc, char **argv);
int	check_mapname(char *name);
int	check_fd(char *file);
int check_characters(t_map *map);
int	check_mapvalid(t_map *map);
int	check_walls(t_map *map);
void	str_trim(char *str);
int	line_len(char *str);

// Moves and Window
int	player_moves(int keysym, t_data *data);
int	handle_input(int keysym, t_data *data);


#endif