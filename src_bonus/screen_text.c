#include "so_long_bonus.h"

void	str_message(t_game *game)
{
	char	*str;
	char	*moves;
	char	*full_str;

	str = "Moves: ";
	moves = ft_itoa(game->player.move_counter);
	full_str = ft_strjoin(str, moves);
	mlx_string_put(game->mlx, game->win, 64, 1000, 0xFFFFFF, full_str);
	if (full_str)
		free(full_str);
	if (moves)
		free(moves);
}