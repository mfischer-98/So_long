#include "../so_long.h"

int	check_fd(int fd)
{
	open(fd, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nInvalid map file\n");
		return (0);
	}
	if (get_next_line(fd) == NULL)
	{
		ft_printf("Error\nInvalid map file\n");
		return (0);
	}
	close(fd);
	return (1);
}

void	ft_initialize(t_map *map)
{
	 map->is_collectable = 0;
	 map->is_exit = 0;
	 map->is_floor = 0;
	 map->is_player = 0;
	 map->design = NULL;
	 map->height = 0;
	 map->width = 0;
	 map->start_x = 0;
	 map->start_y = 0;
}

void	str_trim(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '\n') && (str[i + 1] == '\0'))
			str[i] = '\0';
		i++;
	}
}

int	line_len(char *str)
{
	int	len;

	len = 0;
	if (str)
	{
		while (str[len])
			len++;
	}
	return (len);
}

int	free_map (t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
		free(map->design[i]);
	free(map->design)
	return (0);
}
