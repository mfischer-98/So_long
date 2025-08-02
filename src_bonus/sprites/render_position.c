#include "../so_long_bonus.h"

int	render_position(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img_player,
		game->player.x * SIZE, game->player.y * SIZE);
	return (0);
}