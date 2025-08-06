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

int	close_window(t_game *game)
{
	free_images(game);
	free_walls(game);
	free_extra(game);
	free_player(game);
	free_enemy(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free_map(&game->map);
	free(game->mlx);
	exit(1);
}

void	free_extra(t_game *game)
{
	if (game->img_obstacles[0])
		mlx_destroy_image(game->mlx, game->img_obstacles[0]);
	if (game->img_obstacles[1])
		mlx_destroy_image(game->mlx, game->img_obstacles[1]);
	if (game->img_obstacles[2])
		mlx_destroy_image(game->mlx, game->img_obstacles[2]);
	if (game->img_obstacles[3])
		mlx_destroy_image(game->mlx, game->img_obstacles[3]);
	if (game->img_obstacles[4])
		mlx_destroy_image(game->mlx, game->img_obstacles[4]);
	if (game->img_obstacles[5])
		mlx_destroy_image(game->mlx, game->img_obstacles[5]);
	if (game->img_obstacles[6])
		mlx_destroy_image(game->mlx, game->img_obstacles[6]);
	if (game->img_obstacles[7])
		mlx_destroy_image(game->mlx, game->img_obstacles[7]);
	if (game->img_obstacles[8])
		mlx_destroy_image(game->mlx, game->img_obstacles[8]);
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
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->img_player2)
		mlx_destroy_image(game->mlx, game->img_player2);
	if (game->img_collectable)
		mlx_destroy_image(game->mlx, game->img_collectable);
	if (game->img_sock_dirty)
		mlx_destroy_image(game->mlx, game->img_sock_dirty);
	if (game->img_sock_dots)
		mlx_destroy_image(game->mlx, game->img_sock_dots);
}
