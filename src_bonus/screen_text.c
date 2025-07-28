#include "so_long_bonus.h"

void	str_message(t_game *game)
{
	char	*str;
	char	*moves;
	char	*full_str;
	int		x;
	int		y;

	str = "Moves: ";
	moves = ft_itoa(game->player.move_counter);
	full_str = ft_strjoin(str, moves);
	x = 70;
	y = (game->map.height * 64) - 10;
	mlx_string_put(game->mlx, game->win, x, y, 0xFFFFFF, full_str);
	if (full_str)
		free(full_str);
	if (moves)
		free(moves);
	x = 70;
	y = (game->map.height * 64) - 30;
	if (game->map.width > 7)
		mlx_string_put(game->mlx, game->win, x, y, 0xFFFFFF, "It's moving day! Help Max gather all his precious socks!");
}
