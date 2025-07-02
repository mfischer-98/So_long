#include "../so_long.h"

void	map_size(char *map_file, t_map *map) //ver size, height, se tem linha em branco e se e retangular
{
	int	fd;

	map->height = 0;
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (0);
	while (get_next_line(fd) != NULL)
		map->height++;
	close(fd);//dar free
}

void map_read(char *map_file, t_map *map)
{
		int	fd;
		int	i;

		i = 0;
		fd = open(map_file, O_RDONLY);
		if (fd < 0)
			return (0);
	 	map->design = malloc (sizeof(char *) * size);
		if (!map->design)
		{
			close(fd);
			return ;
		}
		while (i < map->height)
			map->design[i++] = get_next_line(fd);
		close(fd);//dar free
}

int parsing_map(int argc, char **argv)
{
	t_map	map;
	
	if(argc != 2)
	{
		printf("Have only one map file.");
		return (0);
	}
	if (check_mapname(argv[1]))
	{
		map_size(argv[1], &map);
		map_read(argv[1], &map);
		if (check_mapvalid(&map))
			printf("Amazing structure <3\n");
		if (check_walls(&map))
			printf ("Walls securely closed <3\n");
		return (0);
	}
	printf("Error in map\n");
	return (0);
}
