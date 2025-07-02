#include "../so_long.h"

int parsing_map(int argc, char **argv)
{
	//t_map	map;
	int		fd;
	int		size;
	//int		y;
	
	if(argc != 2)
	{
		printf("Have only one map file.");
		return (0);
	}
	if (check_mapname(argv[1]))
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			return (0);
		size = 0;
		while (get_next_line(fd) != NULL)
			size++;
/* 		map.design = malloc (sizeof(char *) * size);
		y = 0;
		while (y < size)
			map.design[y++] = get_next_line(fd);
		//Lembrar de dar free ao array e a cada string no fim
		close(fd); //free
		//ver se tem linha em branco no mapa tbm
		check_mapvalid(&map);
		check_walls(&map); */
		return (0);
	}
	printf("Error in map\n");
	return (0);
}