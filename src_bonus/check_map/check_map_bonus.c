/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:24:07 by mefische          #+#    #+#             */
/*   Updated: 2025/07/28 14:24:07 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	check_args(int count)
{
	if (count != 2)
	{
		ft_printf("Error\nCompile with one map file :(\n");
		return (0);
	}
	return (1);
}

int	check_mapname(char *name)
{
	int	i;

	i = 0;
	if (ft_strrchr(name, '/'))
	{
		name = ft_strrchr(name, '/');
		name++;
	}
	if (!ft_strncmp(name, ".ber", 5))
	{
		ft_printf("Error\nWe dont want a file only named .ber!\n");
		return (0);
	}
	name = ft_strrchr(name, '.');
	if (!ft_strncmp(&name[i], ".ber", 5))
		return (1);
	ft_printf("Error\nPlease put a valid map name >.<\n");
	return (0);
}

int	check_characters(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->design[y][x] != 'P' && map->design[y][x] != 'E'
				&& map->design[y][x] != 'C' && map->design[y][x] != '1'
					&& map->design[y][x] != '0')
			{
				ft_printf("Error\nInvalid map characters :(\n");
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	check_min_characters(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height - 1)
	{
		x = 0;
		while (x < map->width - 1)
		{
			if (map->design[y][x] == 'C')
				map->is_collectable++;
			else if (map->design[y][x] == 'P')
				map->is_player++;
			else if (map->design[y][x] == 'E')
				map->is_exit++;
			x++;
		}
		y++;
	}
	if (map->is_collectable < 1 || map->is_exit != 1 || map->is_player != 1)
	{
		ft_printf("Error\nInvalid map characters :(\n");
		return (0);
	}
	return (1);
}

int	check_walls(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height - 1)
	{
		x = 0;
		while (x < map->width - 1)
		{
			if (map->design[y][0] != '1')
				return (0);
			if (map->design[y][map->width - 1] != '1')
				return (0);
			if (map->design[0][x] != '1')
				return (0);
			if (map->design[map->height - 1][x] != '1')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
