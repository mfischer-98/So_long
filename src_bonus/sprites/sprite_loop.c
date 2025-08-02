#include "../so_long_bonus.h"

int	player_idle(t_game *game)
{
	game->img_player = game->player.idle[game->player.frame_count % 3];
	game->player.frame_count++;
	return (0);
}

int	player_walk_right(t_game *game)
{
	game->img_player = game->player.walk_right[game->player.frame_count % 3];
	game->player.frame_count++;
	return (0);
}

int	player_walk_left(t_game *game)
{
	game->img_player = game->player.walk_left[game->player.frame_count % 3];
	game->player.frame_count++;
	return (0);
}

int	player_walk_down(t_game *game)
{	
	game->img_player = game->player.walk_down[game->player.frame_count % 3];
	game->player.frame_count++;
	return (0);
}

int	player_walk_up(t_game *game)
{
	game->img_player = game->player.walk_up[game->player.frame_count % 3];
	game->player.frame_count++;
	return (0);
}
