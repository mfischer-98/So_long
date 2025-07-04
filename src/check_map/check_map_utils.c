#include "../so_long.h"

void	ft_initialize(t_map *map)
{
	 map->is_collectable = 0;
	 map->is_exit = 0;
	 map->is_floor = 0;
	 map->is_player = 0;
	 map->design = NULL;
	 map->height = 0;
	 map->width = 0;
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
