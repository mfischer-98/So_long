/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 10:30:22 by mefische          #+#    #+#             */
/*   Updated: 2025/07/09 10:30:22 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_height(char *map_file, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return ;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
		map->height++;
	}
	close(fd);
}

void	map_read(char *map_file, t_map *map)
{
	int	fd;
	int	i;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return ;
	map->design = malloc(sizeof(char *) * (map->height + 1));
	if (!map->design)
	{
		close(fd);
		return ;
	}
	i = 0;
	while (i < map->height)
	{
		map->design[i] = get_next_line(fd);
		i++;
	}
	map->design[i] = NULL;
	close(fd);
}

int	map_format(t_map *map)
{
	int	i;
	int	width;

	i = -1;
	while (++i < map->height - 1)
		line_trim(map->design[i]);
	i = 0;
	width = line_len(map->design[i]);
	while (i < map->height)
	{
		if ((width != line_len(map->design[i])) && (map->design[i] != NULL))
		{
			ft_printf("Error\nNot rectangular :(\n");
			return (0);
		}
		i++;
	}
	map->width = width;
	if ((map->width < 5 && map->height < 3)
		|| (map->width < 3 && map->height < 5))
	{
		ft_printf("Error\nNot rectangular :(\n");
		return (0);
	}
	return (1);
}

/*Remember to add return 
(free(map), 0) before exit*/
int	parsing_map(int argc, char **argv, t_map *map)
{
	if (!check_args(argc))
		return (0);
	if (!check_fd(argv[1]))
		return (0);
	if (!check_mapname(argv[1]))
		return (0);
	ft_initialize(map);
	map_height(argv[1], map);
	map_read(argv[1], map);
	if (!map_format(map))
		return (0);
	if (!check_characters(map))
		return (0);
	if (!check_min_characters(map))
		return (0);
	if (!check_walls(map))
	{
		ft_printf ("Error\nInvalid walls :(\n");
		return (0);
	}
	if (!valid_exit(map, argv[1]))
		return (0);
	return (1);
}
