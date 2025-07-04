typedef struct  s_point
{
	int	x;
	int	y;
}			t_point;

void fill(char **map, char target, t_point size, int x, int y)
{
	if (map[x][y] != target || map[x][y] == 'F')
		return ;
	if (x >= size.x || x < 0)
		return ;
	if (y >= size.y || y < 0)
		return ;
	map[x][y] = 'F';
	fill (map, target, size, x + 1, y);
	fill (map, target, size, x - 1, y);
	fill (map, target, size, x , y + 1);
	fill (map, target, size, x, y - 1);
}

void flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, tab[begin.x][begin.y], size, begin.x, begin.y);
}