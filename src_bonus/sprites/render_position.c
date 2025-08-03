#include "../so_long_bonus.h"

void init_enemy(t_game *game)
{
    game->enemy.anim_frame = 0;
    game->enemy.anim_delay = 0;
    game->enemy.state = 0;
}

void	*image_enemy(t_game *game, int x, int y)
{
	game->enemy.x = x;
	game->enemy.y = y;
	game->enemy.img_enemy = game->enemy.idle[0];
	return(game->enemy.idle[0]);
}

int	render_position(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img_player,
		game->player.x * SIZE, game->player.y * SIZE);
	return (0);
}

int	enemy_animation(t_game *game)
{
	if (++game->enemy.anim_delay < 8)
		return (0);
	game->enemy.anim_delay = 0;
	if ((game->player.x == game->enemy.x - 2
		|| game->player.x == game->enemy.x + 2) && (game->player.y == game->enemy.y))
		alert_enemy_anim(game);
	else if ((game->player.y == game->enemy.y - 1) && (game->player.x == game->enemy.x
		|| game->player.x == game->enemy.x - 1 || game->player.x == game->enemy.x + 1))
		alert_enemy_anim(game);
	else if ((game->player.y == game->enemy.y + 1) && (game->player.x == game->enemy.x
		|| game->player.x == game->enemy.x - 1 || game->player.x == game->enemy.x + 1))
		alert_enemy_anim(game);
	else if ((game->player.x == game->enemy.x - 1) && (game->player.y == game->enemy.y))
		enemy_attack_anim(game, 1);
	else if ((game->player.x == game->enemy.x + 1) && (game->player.y == game->enemy.y))
		enemy_attack_anim(game, 2);
	else
		enemy_idle_anim(game);
    return (0);
}
