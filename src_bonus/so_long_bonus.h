/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:22:42 by mefische          #+#    #+#             */
/*   Updated: 2025/07/28 14:22:42 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../lib/mlx/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "../lib/libft/libft.h"

# define MALLOC_ERROR 1
# define SIZE 64
# define ANIM_SPEED 500
# define FLOOR "textures/floor.xpm"
# define PLAYER "textures/player.xpm"
# define PLAYER2 "textures/player2.xpm"
# define COLLECTABLE "textures/sock1.xpm"
# define SOCK_DOTS "textures/sock2.xpm"
# define SOCK_DIRTY "textures/sock3.xpm"
# define BOX "textures/walls/box.xpm"
# define BOOKS "textures/walls/books.xpm"
# define OPEN_BOX "textures/walls/open_box.xpm"
# define CHAIR "textures/walls/chair.xpm"
# define JAR "textures/walls/jar.xpm"
# define LAMP "textures/walls/lamp.xpm"
# define LOW_CHAIR "textures/walls/low_chair.xpm"
# define PLANT "textures/walls/plant.xpm"
# define TABLE "textures/walls/table.xpm"
# define WALL_LEFT1 "textures/walls/wall_topleft_corner.xpm"
# define WALL_LEFT2 "textures/walls/wall_left.xpm"
# define WALL_LEFT3 "textures/walls/wall_corner_downleft.xpm"
# define WALL_RIGHT1 "textures/walls/wall_topright_corner.xpm"
# define WALL_RIGHT2 "textures/walls/wall_right.xpm"
# define WALL_RIGHT3 "textures/walls/wall_corner_downright.xpm"
# define WALL_CENTER1 "textures/walls/wall_top_center.xpm"
# define WALL_CENTER2 "textures/walls/wall_down_center.xpm"
# define EXIT "textures/bed.xpm"

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
	int			is_moving;
	int			move_counter;
	int			frame_count;
	int			anim_delay;
	int			collected;
	void		*idle[3];
	void		*walk_down[3];
	void		*walk_right[3];
	void		*walk_left[3];
	void		*walk_up[3];
	void		*attacked[4];
}			t_player;

typedef struct s_enemy
{
	int			x;
	int			y;
	int			attack_count;
	int			attack_delay;
	int			anim_frame;
	int			anim_delay;
	int			attack_frame_counter;
	void		*img_enemy;
	void		*idle[2];
	void		*alert[3];
	void		*attack[4];
}			t_enemy;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*img_player;
	void		*img_player2;
	void		*img_collectable;
	void		*img_sock_dots;
	void		*img_sock_dirty;
	void		*img_exit;
	void		*img_floor;
	void		*img_wall_left1;
	void		*img_wall_left2;
	void		*img_wall_left3;
	void		*img_wall_right1;
	void		*img_wall_right2;
	void		*img_wall_right3;
	void		*img_wall_center1;
	void		*img_wall_center2;
	void		*img_obstacles[9];
	int			img_x;
	int			img_y;
	int			exit_x;
	int			exit_y;
	int			num;
	int			num_socks;
	int			game_over;
	t_map		map;
	t_player	player;
	t_enemy		enemy;
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
int		load_obstacles(t_game *game, int res);
int		load_extra_obstacles(t_game *game, int res);
void	render_init(t_game *game, t_map *map, t_player *player, t_enemy *enemy);
void	load_map(t_game *game);
void	*render_walls(t_game *game, int x, int y);
int		render_map(t_game *game, int x, int y);
void	render_player(t_game *game);
void	render_enemy(t_game *game);
void	*random_obstacles(t_game *game);
void	*select_collectable(t_game *game, int x, int y);

// Moves and Window
int		handle_key_press(int keysym, t_game *game);
int		close_window(t_game *game);
int		reached_goal(t_game *game);
void	free_images(t_game *game);
void	free_walls(t_game *game);
void	free_walls(t_game *game);
void	free_extra(t_game *game);
void	check_exit(t_game *game, int dir_x, int dir_y);
void	move_right(t_game *game, int x, int y);
void	move_left(t_game *game, int x, int y);
void	move_up(t_game *game, int x, int y);
void	move_down(t_game *game, int x, int y);
int		movements(t_game *game, int dir_x, int dir_y);
void	free_sprite(t_game *game, void **sprite, int i);
void	free_player(t_game *game);
void	free_enemy(t_game *game);

// Text in screen and Animation
int		game_loop(t_game *game);
void	str_message(t_game *game);
int		animation_sprite(t_game *game, int res);
int		walk_down_sprite(t_game *game, int res);
int		walk_down_sprite(t_game *game, int res);
int		walk_up_sprite(t_game *game, int res);
int		walk_right_sprite(t_game *game, int res);
int		walk_left_sprite(t_game *game, int res);
int		player_idle_sprite(t_game *game, int res);
int		player_attacked(t_game *game, int res);
int		enemy_idle(t_game *game, int res);
int		enemy_alert(t_game *game, int res);
int		enemy_attack(t_game *game, int res);
int		player_idle(t_game *game);
int		player_walk_up(t_game *game);
int		player_walk_down(t_game *game);
int		player_walk_right(t_game *game);
int		player_walk_left(t_game *game);
int		render_position_player(t_game *game);
int		enemy_idle_anim(t_game *game);
int		alert_enemy_anim(t_game *game);
int		enemy_attack_anim(t_game *game, int side);
void	player_move(t_game *game);
void	attack_left_anim(t_game *game);
void	attack_right_anim(t_game *game);
void	*image_enemy(t_game *game, int x, int y);
void	*image_player(t_game *game, int x, int y);
int		is_near(t_game *game);
void	game_over(t_game *game);
void	player_attacked_anim(t_game *game);

#endif