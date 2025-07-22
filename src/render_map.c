/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:22:33 by mefische          #+#    #+#             */
/*   Updated: 2025/07/22 17:27:28 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render_map(t_map *map, t_game *game, t_player *player)
{
	game->img_y = 0;
	while (game->img_y < map->height)
	{
		game->img_x = 0;
		while (game->img_x < map->width)
		{
			if (map->design[game->img_y][game->img_x] == '0')
				img_floor(game);
			else if (map->design[game->img_y][game->img_x] == '1')
				img_obstacles(game);
			else if (map->design[game->img_y][game->img_x] == 'P')
			{
				img_player(game);
				player->x = game->img_x;
				player->y = game->img_y;
			}
			else if (map->design[game->img_y][game->img_x] == 'E')
				img_exit(game);
			else if (map->design[game->img_y][game->img_x] == 'C')
				img_collectable(game);
			game->img_x++;
		}
		game->img_y++;
	}
	return (0);
}

