/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:22:33 by mefische          #+#    #+#             */
/*   Updated: 2025/07/09 15:57:36 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	put_background(t_map *map, t_data *data, t_game *game)
{
	data->y = 0;
	while (data->y < map->height)
	{
		data->x = 0;
		while (data->x < map->width)
		{
			if (map->design[data->y][data->x] == '0') //change data->x
				img_floor(data, game);
			else if (map->design[data->y][data->x] == '1')
				img_obstacles(data, game);
			data->x++;
		}
		data->y++;
	}
	return (0);
}

int	put_objects(t_map *map, t_data *data, t_game *game, t_player *player)
{
	data->y = 0;
	while (data->y < map->height)
	{
		data->x = 0;
		while (data->x < map->width)
		{
			if (map->design[data->y][data->x] == 'P') //change data->x
			{
				img_player(data, game);
				player->x = data->x;
				player->y = data->y;
			}
			else if (map->design[data->y][data->x] == 'E')
				img_exit(data, game);
			else if (map->design[data->y][data->x] == 'C')
				img_collectable(data, game);
			data->x++;
		}
		data->y++;
	}
	return (0);
}

void	render_map(t_map *map, t_data *data, t_game *game, t_player *player)
{
	put_background(map, data, game);
	put_objects(map, data, game, player);
}
