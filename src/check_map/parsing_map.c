#include "../so_long.h"

void	map_height(char *map_file, t_map *map)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return ;
	while (get_next_line(fd) != NULL)
		map->height++;
	close(fd);
}

void	map_read(char *map_file, t_map *map)
{
	int	fd;
	int	i;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return ;
	map->design = malloc (sizeof(char *) * map->height);
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

	i = 0;
	while (i < map->height)
		str_trim(map->design[i++]);
	i = 0;
	width = line_len(map->design[i]);
	while (i < map->height)
	{
		if ((width != line_len(map->design[i])) && (map->design[i] != NULL))
		{
			ft_printf("The lines are not all the same size :(\n");
			return (0);
		}
		ft_printf("%s\n", map->design[i]);
		i++;
	}
	map->width = width;
	return (1);
}

int parsing_map(int argc, char **argv)
{
	t_map	map;
	
	if(argc != 2)
	{
		ft_printf("Have only one map file.");
		return (0);
	}
	ft_initialize(&map);
	if (check_mapname(argv[1]))
	{	
		if (!check_fd(argv[1]))
			ft_printf("Error\nInvalid file\n");
		map_height(argv[1], &map);
		map_read(argv[1], &map);
		if (!check_characters(&map))
			ft_printf("Error\nInvalid characters\n");
		if (!map_format(&map))
			ft_printf("Error\nLines are not same size\n");
		if (!check_mapvalid(&map))
			ft_printf("Error\nInvalid map characters\n");
		if (!check_walls(&map))
			ft_printf ("Error\nInvalid walls\n");
		return (0);
	}
	else
		ft_printf("Error\nInvalid map name");
	return (0);
}
