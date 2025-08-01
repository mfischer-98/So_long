#include "../so_long_bonus.h"

int	animation_sprite(t_game *game, int res)
{
	walk_down_sprite(game, res);
	return (0);
}


int	walk_down_sprite(t_game *game, int res)
{

	game->player.walk_down[0] = mlx_xpm_file_to_image
		(game->mlx, "textures/sprites/walk_down2.xpm", &res, &res);
	if (!game->player.walk_down[0])
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);

	game->player.walk_down[1] = mlx_xpm_file_to_image
		(game->mlx, "textures/sprites/walk_down4.xpm", &res, &res);
	if (!game->player.walk_down[1])
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	return (0);
}