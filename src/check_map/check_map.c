#include "../so_long.h"

int	check_mapname(char *name)
{
	int	i;

	i = 0;
 	if (ft_strrchr(name, '/')) //se tiver uma /, i = posicao da ultima barra
	{
		name = ft_strrchr(name, '/');
		name++;
		
	}
	if (!ft_strncmp(name, ".ber", 5))
	{
		printf("We dont want a file only named .ber!\n");
		return (0);
	}
	name = ft_strrchr(name, '.');
	if (!ft_strncmp(&name[i], ".ber", 5))
	{
		printf("Yay, this is a valid name!\n");
		return (1);
	}
	printf("Please put a valid map name >.<\n");
	return (0);
}

int	check_mapvalid(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height - 1)
	{
		x = 0;
		while (x < map->width - 1)
		{
			if(map->design[y][x] == 'C')
				map->is_collectable++;
			else if(map->design[y][x] == 'P')
				map->is_player++;
			else if(map->design[y][x] == 'E')
				map->is_exit++;
			x++;
		}
		y++;
	}
	if (map->is_collectable < 1 || map->is_exit != 1 || map->is_player != 1)
	{
		printf("Invalid map :(\n");
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
			if(map->design[y][0] != '1')
			{
				printf("Walls invalid :(");
				return (0);
			}
			if(map->design[y][map->width - 1] != '1')
			{
				printf("Walls invalid :(");
				return (0);
			}
			if(map->design[0][x] != '1')
			{
				printf("Walls invalid :(");
				return (0);
			}
			if(map->design[map->height - 1][x] != '1')
			{
				printf("Walls invalid :(");
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

