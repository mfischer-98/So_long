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
			ft_printf("Error\nNot rectangular :(\n");
			return (0);
		}
		i++;
	}
	map->width = width;
	if ((map->width < 5 && map->height < 3) || (map->width < 3 && map->height < 5))
	{
			ft_printf("Error\nNot rectangular :(\n");
			return (0);
	}
	return (1);
}

int parsing_map(int argc, char **argv)
{
	t_map	map;
	
	if (!check_args)
		return (0);
	if (!open_fd(argv[1])) //checking fd and content
		return (0);
	ft_initialize(&map);
	map_height(argv[1], &map);
	map_read(argv[1], &map);
	if (!check_characters(&map)) //checking if there is non wanted characters
		return (0);
	if (!map_format(&map)) //check rectangular
		return (0);
	if (!check_min_characters(&map)) //check character rules
		return (0);
	if (!check_walls(&map))
	{
		ft_printf ("Error\nInvalid walls :(\n");
		return (0);
	}
	if (!valid_path(&map))
		return (0);
	return (0);
}
