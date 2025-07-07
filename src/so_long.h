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
	int		start_x;
	int		start_y;
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
int		parsing_map(int argc, char **argv);
int		check_fd(int fd);
void 	ft_initialize(t_map *map);
void	str_trim(char *str);
int		line_len(char *str);
int		free_map (t_map *map);
int		check_args(int count);
int		check_mapname(char *name);
int 	check_characters(t_map *map);
int		check_min_characters(t_map *map);
int		check_walls(t_map *map);
void	map_height(char *map_file, t_map *map);
void	map_read(char *map_file, t_map *map);
int	map_format(t_map *map);
void	player_position (t_map &map);
void	flood_fill(t_map *map, int x, int y);
int		valid_exit(t_map *map);

// Moves and Window
int	player_moves(int keysym, t_data *data);
int	handle_input(int keysym, t_data *data);


#endif