/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:32:27 by mefische          #+#    #+#             */
/*   Updated: 2025/07/24 13:32:51 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_images(t_game *game)
{
	int	res;

	res = 64;
	game->img_floor = mlx_xpm_file_to_image(game->mlx, FLOOR, &res, &res);
	if (!game->img_floor)
		return (MALLOC_ERROR);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, WALL, &res, &res);
	if (!game->img_wall)
		return (MALLOC_ERROR);
	game->img_player = mlx_xpm_file_to_image(game->mlx, PLAYER, &res, &res);
	if (!game->img_player)
		return (MALLOC_ERROR);
	game->img_player2 = mlx_xpm_file_to_image(game->mlx, PLAYER2, &res, &res);
	if (!game->img_player2)
		return (MALLOC_ERROR);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, EXIT, &res, &res);
	if (!game->img_exit)
		return (MALLOC_ERROR);
	game->img_collectable = mlx_xpm_file_to_image
		(game->mlx, COLLECTABLE, &res, &res);
	if (!game->img_collectable)
		return (MALLOC_ERROR);
	return (0);
}
