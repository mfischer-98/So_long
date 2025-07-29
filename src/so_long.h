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
# define SIZE 64
# define FLOOR "textures/floor.xpm"
# define PLAYER "textures/player.xpm"
# define PLAYER2 "textures/player2.xpm"
# define COLLECTABLE "textures/collectable1.xpm"
# define OBSTACLE "textures/walls/box.xpm"
# define WALL_LEFT1 "textures/walls/wall_topleft_corner.xpm"
# define WALL_LEFT2 "textures/walls/wall_left.xpm"
# define WALL_LEFT3 "textures/walls/wall_corner_downleft.xpm"
# define WALL_RIGHT1 "textures/walls/wall_topright_corner.xpm"
# define WALL_RIGHT2 "textures/walls/wall_right.xpm"
# define WALL_RIGHT3 "textures/walls/wall_corner_downright.xpm"
# define WALL_CENTER1 "textures/walls/wall_top_center.xpm"
# define WALL_CENTER2 "textures/walls/wall_down_center.xpm"
# define EXIT "textures/exit.xpm"

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
	int			x;
	int			y;
	int			move_counter;
	int			collected;
}			t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*img_player;
	void		*img_player2;
	void		*img_collectable;
	void		*img_exit;
	void		*img_floor;
	void		*img_obstacle;
	void		*img_wall_left1;
	void		*img_wall_left2;
	void		*img_wall_left3;
	void		*img_wall_right1;
	void		*img_wall_right2;
	void		*img_wall_right3;
	void		*img_wall_center1;
	void		*img_wall_center2;
	int			img_x;
	int			img_y;
	int			exit_x;
	int			exit_y;
	t_map		map;
	t_player	player;
}				t_game;

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
int		load_images(t_game *game);
int		load_walls(t_game *game, int res);
int		load_extra_walls(t_game *game, int res);
void	render_init(t_game *game, t_map *map, t_player *player);
void	load_map(t_game *game);
void	*render_walls(t_game *game, int x, int y);
int		render_map(t_game *game, int x, int y);

// Moves and Window
int		handle_input(int keysym, t_game *game);
int		close_window(t_game *game);
int		reached_goal(t_game *game);
void	free_walls(t_game *game);
void	free_walls(t_game *game);
void	check_exit(t_game *game, int dir_x, int dir_y);
void	move_right(t_game *game, int x, int y);
void	move_left(t_game *game, int x, int y);
void	move_up(t_game *game, int x, int y);
void	move_down(t_game *game, int x, int y);
int		movements(t_game *game, int dir_x, int dir_y);

#endif