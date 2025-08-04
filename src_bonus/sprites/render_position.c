#include "../so_long_bonus.h"

void	player_move(t_game *game)
{
	if (game->player.is_moving == 1)
		player_walk_right(game);
	else if (game->player.is_moving == 2)
		player_walk_left(game);
	else if (game->player.is_moving == 3)
		player_walk_up(game);
	else if (game->player.is_moving == 4)
			player_walk_down(game);	
}

void	*image_enemy(t_game *game, int x, int y)
{
	 int	player_left ;
	 int	player_right;
	int player_near;

	game->enemy.x = x;
	game->enemy.y = y;
	player_left = (game->player.x == game->enemy.x - 1 && game->player.y == game->enemy.y);
	player_right = (game->player.x == game->enemy.x + 1 && game->player.y == game->enemy.y);
	player_near = is_near(game);
	if (player_near)
		alert_enemy_anim(game);
	else if (player_left)
		attack_left_anim(game);
	else if (player_right)
		attack_right_anim(game);
	else
		enemy_idle_anim(game);
	return(game->enemy.img_enemy);
}

int is_near(t_game *game)
{
	if ((game->player.y == game->enemy.y - 1) || (game->player.y == game->enemy.y + 1) )
	{
		if (game->player.x == game->enemy.x - 2 || game->player.x == game->enemy.x + 2)
			return (1);
		if (game->player.x == game->enemy.x - 1 || game->player.x == game->enemy.x + 1)
			return (1);
		if (game->player.x == game->enemy.x)
			return (1);
	}
	if ((game->player.y == game->enemy.y - 2) || (game->player.y == game->enemy.y + 2) )
	{
		if (game->player.x == game->enemy.x - 2 || game->player.x == game->enemy.x + 2)
			return (1);
		if (game->player.x == game->enemy.x - 1 || game->player.x == game->enemy.x + 1)
			return (1);
		if (game->player.x == game->enemy.x)
			return (1);
	}
	if ((game->player.y == game->enemy.y) && (game->player.x == game->enemy.x - 2 || game->player.x == game->enemy.x + 2))
		return (1);
	if ((game->player.y == game->enemy.y) && (game->player.x == game->enemy.x - 3 || game->player.x == game->enemy.x + 3))
		return (1);
	return (0);
}
