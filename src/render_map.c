/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:22:33 by mefische          #+#    #+#             */
/*   Updated: 2025/07/24 13:23:38 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_init(t_game *game, t_map *map, t_player *player)
{
	game->map = *map;
	game->player = *player;
	game->img = NULL;
	game->exit_x = 0;
	game->exit_y = 0;
	player->move_counter = 0;
	player->collected = 0;
	load_images(game);
	load_map(game);
}

void	clear_window(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
}

void	load_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			render_map(game, x, y);
			x++;
		}
		y++;
	}
	if (game->exit_x && game->exit_y > 0 && game->map.design[game->exit_y ][game->exit_x] != 'P')
	{
		game->map.design[game->exit_y ][game->exit_x] = 'E';
		render_map(game, game->exit_x, game->exit_y);
	}
}

int		render_map(t_game *game, int x, int y)
{
	if (game->map.design[y][x] == '1')
		game->img = game->img_wall;
	else if (game->map.design[y][x] == '0')
		game->img = game->img_floor;
	else if (game->map.design[y][x] == 'P')
	{
		game->img = game->img_player;
		game->player.x = x;
		game->player.y = y;
	}
	else if (game->map.design[y][x] == 'C')
		game->img = game->img_collectable;
	else if (game->map.design[y][x] == 'E')
		game->img = game->img_exit;
	else
		return (1); //image invalid
	mlx_put_image_to_window(game->mlx, game->win, game->img,
				x * SIZE, y * SIZE);
	return (0);
}

