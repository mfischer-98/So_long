#include "../so_long_bonus.h"

int	player_idle(t_game *game)
{
	game->img_player = game->player.idle[game->enemy.anim_frame % 3];
	game->enemy.anim_frame++;
	return (0);
}

int	player_walk_right(t_game *game)
{
	game->img_player = game->player.walk_right[game->enemy.anim_frame % 3];
	game->enemy.anim_frame++;
	return (0);
}

int	player_walk_left(t_game *game)
{
	game->img_player = game->player.walk_left[game->enemy.anim_frame % 3];
	game->enemy.anim_frame++;
	return (0);
}

int	player_walk_down(t_game *game)
{	
	game->img_player = game->player.walk_down[game->enemy.anim_frame % 3];
	game->enemy.anim_frame++;
	return (0);
}

int	player_walk_up(t_game *game)
{
	game->img_player = game->player.walk_up[game->enemy.anim_frame % 3];
	game->enemy.anim_frame++;
	return (0);
}
