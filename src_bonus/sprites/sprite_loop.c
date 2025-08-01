#include "../so_long_bonus.h"

int	player_walk_down(t_game *game)
{
    game->player.frame_count++;
    
    if (game->player.frame_count % 2 == 0)
        game->img_player = game->player.walk_down[0];
	else
        game->img_player = game->player.walk_down[1];
	return (0);
}