/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 10:30:56 by mefische          #+#    #+#             */
/*   Updated: 2025/07/09 10:30:56 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/mlx/mlx.h"
# include <X11/keysym.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "../lib/libft/libft.h"

# define MALLOC_ERROR 1
# define WIDTH 1920
# define HEIGHT 1080

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

typedef struct s_data
{
	void	*img;
	int		img_width;
	int		img_height;
	int		x;
	int		y;
}				t_data;

typedef struct s_game
{
	void	*mlx;
	void	*win;
}				t_game;

typedef struct s_player
{
	int		x;
	int		y;
}			t_player;

// Map parsing
int		parsing_map(int argc, char **argv, t_map *map);
int		check_fd(char *file_name);
void	ft_initialize(t_map *map);
void	line_trim(char *str);
int		line_len(char *str);
void	free_map(t_map *map);
int		check_args(int count);
int		check_mapname(char *name);
int		check_characters(t_map *map);
int		check_min_characters(t_map *map);
int		check_walls(t_map *map);
void	map_height(char *map_file, t_map *map);
void	map_read(char *map_file, t_map *map);
int		map_format(t_map *map);
void	player_position(t_map *map);
void	flood_fill(t_map *map, int x, int y);
int		valid_exit(t_map *map, char *file);

//Rendering
void	render_map(t_map *map, t_data *data, t_game *game, t_player *player);
int		put_background(t_map *map, t_data *data, t_game *game);
int		put_objects(t_map *map, t_data *data, t_game *game, t_player *player);

//Images
int		img_floor(t_data *data, t_game *game);
int		img_obstacles(t_data *data, t_game *game);
int		img_player(t_data *data, t_game *game);
int		img_collectable(t_data *data, t_game *game);
int		img_exit(t_data *data, t_game *game);

// Moves and Window
int	handle_input(int keysym, t_game *game, t_data *data, t_player *player);
int	mouse_hook(int event, t_game *game);
int	player_moves(int keysym, t_game *game, t_data *data, t_player *player);

#endif