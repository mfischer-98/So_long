/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:23:06 by mefische          #+#    #+#             */
/*   Updated: 2025/07/28 14:23:06 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	load_extra_walls(t_game *game, int res)
{
	game->img_wall_right1 = mlx_xpm_file_to_image
		(game->mlx, WALL_RIGHT1, &res, &res);
	if (!game->img_wall_right1)
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	game->img_wall_right2 = mlx_xpm_file_to_image
		(game->mlx, WALL_RIGHT2, &res, &res);
	if (!game->img_wall_right2)
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	game->img_wall_right3 = mlx_xpm_file_to_image
		(game->mlx, WALL_RIGHT3, &res, &res);
	if (!game->img_wall_right3)
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	return (0);
}

int	load_walls(t_game *game, int res)
{
	game->img_wall_center1 = mlx_xpm_file_to_image
		(game->mlx, WALL_CENTER1, &res, &res);
	if (!game->img_wall_center1)
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	game->img_wall_center2 = mlx_xpm_file_to_image
		(game->mlx, WALL_CENTER2, &res, &res);
	if (!game->img_wall_center2)
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	game->img_wall_left1 = mlx_xpm_file_to_image
		(game->mlx, WALL_LEFT1, &res, &res);
	if (!game->img_wall_left1)
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	game->img_wall_left2 = mlx_xpm_file_to_image
		(game->mlx, WALL_LEFT2, &res, &res);
	if (!game->img_wall_left2)
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	game->img_wall_left3 = mlx_xpm_file_to_image
		(game->mlx, WALL_LEFT3, &res, &res);
	if (!game->img_wall_left3)
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	return (0);
}

int	load_images(t_game *game)
{
	int	res;

	res = 64;
	load_walls(game, res);
	load_extra_walls(game, res);
	load_obstacles(game, res);
	load_extra_obstacles(game, res);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, FLOOR, &res, &res);
	if (!game->img_floor)
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	game->img_player = mlx_xpm_file_to_image(game->mlx, PLAYER, &res, &res);
	if (!game->img_player)
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	game->img_player2 = mlx_xpm_file_to_image(game->mlx, PLAYER2, &res, &res);
	if (!game->img_player2)
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, EXIT, &res, &res);
	if (!game->img_exit)
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	game->img_collectable = mlx_xpm_file_to_image
		(game->mlx, COLLECTABLE, &res, &res);
	if (!game->img_collectable)
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	return (0);
}

int	load_walk_sprite(t_game *game)
{
	int	res;

	res = 64;
	game->sprite.walk_down1 = mlx_xpm_file_to_image(game->mlx,
			"textures/sprites/walk1.xpm", &res, &res);
	if (!game->sprite.walk_down1)
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	game->sprite.walk_down2 = mlx_xpm_file_to_image(game->mlx,
			"textures/sprites/walk2.xpm", &res, &res);
	if (!game->sprite.walk_down2)
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	game->sprite.walk_down3 = mlx_xpm_file_to_image(game->mlx,
			"textures/sprites/walk3.xpm", &res, &res);
	if (!game->sprite.walk_down3)
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	game->sprite.walk_down4 = mlx_xpm_file_to_image(game->mlx,
			"textures/sprites/walk4.xpm", &res, &res);
	if (!game->sprite.walk_down4)
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	return (0);
}
