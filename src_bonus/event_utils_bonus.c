/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:23:11 by mefische          #+#    #+#             */
/*   Updated: 2025/07/28 14:23:11 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_extra(t_game *game)
{
	if (game->extra.img_box)
		mlx_destroy_image(game->mlx, game->extra.img_box);
	if (game->extra.img_open_box)
		mlx_destroy_image(game->mlx, game->extra.img_open_box);
	if (game->extra.img_books)
		mlx_destroy_image(game->mlx, game->extra.img_books);
	if (game->extra.img_chair)
		mlx_destroy_image(game->mlx, game->extra.img_chair);
	if (game->extra.img_jar)
		mlx_destroy_image(game->mlx, game->extra.img_jar);
	if (game->extra.img_lamp)
		mlx_destroy_image(game->mlx, game->extra.img_lamp);
	if (game->extra.img_low_chair)
		mlx_destroy_image(game->mlx, game->extra.img_low_chair);
	if (game->extra.img_plant)
		mlx_destroy_image(game->mlx, game->extra.img_plant);
	if (game->extra.img_table)
		mlx_destroy_image(game->mlx, game->extra.img_table);
}

void	free_walls(t_game *game)
{
	if (game->img_wall_center1)
		mlx_destroy_image(game->mlx, game->img_wall_center1);
	if (game->img_wall_center2)
		mlx_destroy_image(game->mlx, game->img_wall_center2);
	if (game->img_wall_left1)
		mlx_destroy_image(game->mlx, game->img_wall_left1);
	if (game->img_wall_left2)
		mlx_destroy_image(game->mlx, game->img_wall_left2);
	if (game->img_wall_left3)
		mlx_destroy_image(game->mlx, game->img_wall_left3);
	if (game->img_wall_right1)
		mlx_destroy_image(game->mlx, game->img_wall_right1);
	if (game->img_wall_right2)
		mlx_destroy_image(game->mlx, game->img_wall_right2);
	if (game->img_wall_right3)
		mlx_destroy_image(game->mlx, game->img_wall_right3);
}

void	free_images(t_game *game)
{
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->img_player2)
		mlx_destroy_image(game->mlx, game->img_player2);
	if (game->img_collectable)
		mlx_destroy_image(game->mlx, game->img_collectable);
	if (game->extra.img_sock_dirty)
		mlx_destroy_image(game->mlx, game->extra.img_sock_dirty);
	if (game->extra.img_sock_dots)
		mlx_destroy_image(game->mlx, game->extra.img_sock_dots);
}

int	close_window(t_game *game)
{
	free_images(game);
	free_walls(game);
	free_extra(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free_map(&game->map);
	free(game->mlx);
	exit(1);
}

int	handle_input(int keysym, t_game *game)
{
	int	dir_x;
	int	dir_y;

	dir_x = game->player.x;
	dir_y = game->player.y;
	if (keysym == XK_Escape)
		close_window(game);
	else if (keysym == XK_Right)
		move_right(game, dir_x, dir_y);
	else if (keysym == XK_Left)
		move_left(game, dir_x, dir_y);
	else if (keysym == XK_Up)
		move_up(game, dir_x, dir_y);
	else if (keysym == XK_Down)
		move_down(game, dir_x, dir_y);
	return (0);
}
