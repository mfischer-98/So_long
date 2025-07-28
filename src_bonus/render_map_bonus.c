/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:22:50 by mefische          #+#    #+#             */
/*   Updated: 2025/07/28 14:22:50 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	render_init(t_game *game, t_map *map, t_player *player)
{
	game->map = *map;
	game->player = *player;
	game->img = NULL;
	game->exit_x = 0;
	game->exit_y = 0;
	game->player.move_counter = 0;
	game->player.collected = 0;
	load_images(game);
	load_map(game);
}

void	check_exit(t_game *game, int dir_x, int dir_y)
{
	game->exit_y = dir_y;
	game->exit_x = dir_x;
	game->map.design[dir_y][dir_x] = 'P';
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
	if (game->exit_x && game->exit_y > 0
		&& game->map.design[game->exit_y][game->exit_x] != 'P')
	{
		game->map.design[game->exit_y][game->exit_x] = 'E';
		render_map(game, game->exit_x, game->exit_y);
		game->exit_y = 0;
		game->exit_x = 0;
	}
}

void	*render_walls(t_game *game, int x, int y)
{
	if (y == 0 && x == 0)
		return (game->img_wall_left1);
	else if (y == 0 && x == game->map.width - 1)
		return (game->img_wall_right1);
	else if (y == game->map.height - 1 && x == 0)
		return (game->img_wall_left3);
	else if (y == game->map.height - 1 && x == game->map.width - 1)
		return (game->img_wall_right3);
	else if (y == 0 && x < game->map.width - 1)
		return (game->img_wall_center1);
	else if (y < game->map.height - 1 && x == 0)
		return (game->img_wall_left2);
	else if (y == game->map.height - 1 && (x > 0 && x < game->map.width - 1))
		return (game->img_wall_center2);
	else if ((y > 0 && y < game->map.height - 1) && x == game->map.width - 1)
		return (game->img_wall_right2);
	return (game->img_obstacle);
}

int	render_map(t_game *game, int x, int y)
{
	if (game->map.design[y][x] == '1')
		game->img = render_walls(game, x, y);
	else if (game->map.design[y][x] == '0')
		game->img = game->img_floor;
	else if (game->map.design[y][x] == 'P')
	{
		if ((game->exit_y && game->exit_x != 0)
			&& (game->map.design[game->exit_y][game->exit_x] == 'P'))
			game->img = game->img_player2;
		else
			game->img = game->img_player;
		game->player.x = x;
		game->player.y = y;
	}
	else if (game->map.design[y][x] == 'C')
		game->img = game->img_collectable;
	else if (game->map.design[y][x] == 'E')
		game->img = game->img_exit;
	else
		return (1);
	mlx_put_image_to_window(game->mlx, game->win, game->img,
		x * SIZE, y * SIZE);
	str_message(game);
	return (0);
}
