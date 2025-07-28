/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 10:30:42 by mefische          #+#    #+#             */
/*   Updated: 2025/07/09 10:30:42 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_images(t_game *game)
{
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_obstacle)
		mlx_destroy_image(game->mlx, game->img_obstacle);
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->img_player2)
		mlx_destroy_image(game->mlx, game->img_player2);
	if (game->img_collectable)
		mlx_destroy_image(game->mlx, game->img_collectable);
	if (game->img_wall_center1)
		mlx_destroy_image(game->mlx, game->img_wall_center1);
}

int	close_window(t_game *game)
{
	free_images(game);
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
