#include "so_long.h"

int		movements(t_game *game, int dir_x, int dir_y)
{
	if (dir_x < 0 || dir_y < 0 || dir_y > game->map.height || dir_x > game->map.width)
		return (0);
	if (game->map.design[dir_y][dir_x] == '1')
		return (0);
	if (game->map.design[dir_y][dir_x] == 'C')
		game->player.collected++;
	if (game->map.design[dir_y][dir_x] == 'E' && reached_goal(game))
	{
		game->player.move_counter++;
		ft_printf("Congratulations!\nYou finished with %d moves :)", game->player.move_counter);
		close_window(game);
		return (0);
	}
	 //se for saida vai ser = player with exit behind
	game->player.move_counter++;
	ft_printf("Moves: %d\n", game->player.move_counter);
	game->map.design[dir_y][dir_x] = 'P';
	game->player.x = dir_x;
	game->player.y = dir_y;
	return (1);
}

void	move_right(t_game *game, int x, int y)
{
	if(movements(game, x + 1, y))
		game->map.design[y][x] = '0';
	clear_window(game);
	load_map(game);
}

void	move_left(t_game *game, int x, int y)
{
	if(movements(game, x - 1, y))
		game->map.design[y][x] = '0';
	clear_window(game);
	load_map(game);
}

void	move_up(t_game *game, int x, int y)
{
	if(movements(game, x, y - 1))
		game->map.design[y][x] = '0';
	clear_window(game);
	load_map(game);
}

void	move_down(t_game *game, int x, int y)
{
	if(movements(game, x, y + 1))
		game->map.design[y][x] = '0';
	clear_window(game);
	load_map(game);
}
