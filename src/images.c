/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:43:08 by mefische          #+#    #+#             */
/*   Updated: 2025/07/22 17:56:02 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	img_floor(t_game *game)
{
	int	res;

	res = 64;
	game->img = mlx_xpm_file_to_image(game->mlx, FLOOR, &res, &res);
	if (!game->img)
		return (MALLOC_ERROR);
	mlx_put_image_to_window(game->mlx, game->win, game->img,
				game->img_x * SIZE, game->img_y * SIZE);
	return (0);
}

int	img_obstacles(t_game *game)
{
	int	res;

	res = 64;
	game->img = mlx_xpm_file_to_image(game->mlx, WALL, &res, &res);
	if (!game->img)
		return (MALLOC_ERROR);
	mlx_put_image_to_window(game->mlx, game->win, game->img,
				game->img_x * SIZE, game->img_y * SIZE);
	return (0);
}

int	img_player(t_game *game)
{
	int	res;

	res = 64;
	game->img = mlx_xpm_file_to_image(game->mlx, PLAYER, &res, &res);
	if (!game->img)
		return (MALLOC_ERROR);
	mlx_put_image_to_window(game->mlx, game->win, game->img,
				game->img_x * SIZE, game->img_y * SIZE);
	return (0);
}

int	img_collectable(t_game *game)
{
	int	res;

	res = 64;
	game->img[game->pos] = mlx_xpm_file_to_image(game->mlx, WALL, &res, &res);
	if (!game->img)
		return (MALLOC_ERROR);
	mlx_put_image_to_window(game->mlx, game->win, game->img,
				game->img_x * SIZE, game->img_y * SIZE);
	return (0);
}

int	img_exit(t_game *game)
{
	int	res;

	res = 64;
	game->img = mlx_xpm_file_to_image(game->mlx, EXIT, &res, &res);
	if (!game->img)
		return (MALLOC_ERROR);
	mlx_put_image_to_window(game->mlx, game->win, game->img,
				game->img_x * SIZE, game->img_y * SIZE);
	return (0);
}