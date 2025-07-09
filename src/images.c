/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:43:08 by mefische          #+#    #+#             */
/*   Updated: 2025/07/09 14:57:41 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	img_floor(t_data *data, t_game *game)
{
	char	*relative_path;

	relative_path = "img/floor.xpm";
	data->img = mlx_xpm_file_to_image(game->mlx, relative_path, &data->img_width, &data->img_height);
	if (!data->img)
		return (MALLOC_ERROR);
	mlx_put_image_to_window(game->mlx, game->win, data->img,
				data->x * data->img_width, data->y * data->img_height);
	return (0);
}

int	img_obstacles(t_data *data, t_game *game)
{
	char	*relative_path;

	relative_path = "img/obstacles.xpm";
	data->img = mlx_xpm_file_to_image(game->mlx, relative_path, &data->img_width, &data->img_height);
	if (!data->img)
		return (MALLOC_ERROR);
	mlx_put_image_to_window(game->mlx, game->win, data->img,
				data->x * data->img_width, data->y * data->img_height);
	return (0);
}

int	img_player(t_data *data, t_game *game)
{
	char	*relative_path;

	relative_path = "img/player.xpm";
	data->img = mlx_xpm_file_to_image(game->mlx,relative_path, &data->img_width, &data->img_height);
	if (!data->img)
		return (MALLOC_ERROR);
	mlx_put_image_to_window(game->mlx, game->win, data->img,
				data->x * data->img_width, data->y * data->img_height);
	return (0);
}

int	img_collectable(t_data *data, t_game *game)
{
	char	*relative_path;

	relative_path = "img/collectable.xpm";
	data->img = mlx_xpm_file_to_image(game->mlx,relative_path, &data->img_width, &data->img_height);
	if (!data->img)
		return (MALLOC_ERROR);
	mlx_put_image_to_window(game->mlx, game->win, data->img,
				data->x * data->img_width, data->y * data->img_height);
	return (0);
}

int	img_exit(t_data *data, t_game *game)
{
	char	*relative_path;

	relative_path = "img/exit.xpm";
	data->img = mlx_xpm_file_to_image(game->mlx,relative_path, &data->img_width, &data->img_height);
	if (!data->img)
		return (MALLOC_ERROR);
	mlx_put_image_to_window(game->mlx, game->win, data->img,
				data->x * data->img_width, data->y * data->img_height);
	return (0);
}