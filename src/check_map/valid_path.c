#include "../so_long.h"

void	player_position (t_map &map)
{
	int	x;
	int y;

	y = 0;
	while (y < map->height - 1)
	{
		x = 0;
		while (x < map->width - 1)
		{
			if (map->design[y][x] == 'P')
			{
				map->start_x = x;
				map->start_y = y;
				break ;
			}
			x++;
		}
		y++;
	}
}

void flood_fill(t_map *map, int x, int y)
{
	int exit_reach;

	exit_reach = 0;
	if (x < 0 || y < 0 || x > map->width || y > map->height)
		return ;
	if (map->desig[y][x] == '1' || map->design[y][x] == 'F')
		return ;
	if (map->design[y][x] == 'C')
	{
		map->design[y][x] = 'F';
		map->is_collectable -= 1;
	}
	if (map->design[y][x] == 'E')
	{
		map->design[y][x] = 'F';
		map->is_exit -= 1;
		return ;
	}
	map->design[y][x] = 'F';
	flood_fill(map, x - 1, y);
	flood_fill(map, x + 1, y);
	flood_fill(map, x, y - 1);
	flood_fill(map, x, y + 1);
}

int	valid_exit(t_map *map)
{
	int	collectables;
	int	x;
	int	y;

	collectables = map->is_collectable;
	player_position(&map);
	x = map->start_x;
	y = map->start_y;
	flood_fill(&map, x, y);
	//dar free do design e ler mapa de novo
	free_map(&map);
	map_read(argv[1], &map);
	//se o numero de collectables for maior que 0 nao pega tudo e se saida for 1 nao chegou la
	if (map->is_collectable != 0 || map->is_exit)
	{
		ft_printf("Error\nNo valid path\n");
		return (0);
	}
	map->is_collectable = collectables;
	map->is_exit = 1;
	return (1); //deu tudo certo
}