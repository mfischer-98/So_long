#include "../so_long_bonus.h"

int	enemy_idle_anim(t_game *game)
{
	game->enemy.img_enemy = game->enemy.idle[game->enemy.anim_frame % 2];
	return (0);
}

int alert_enemy_anim(t_game *game)
{
	game->enemy.img_enemy = game->enemy.alert[game->enemy.anim_frame % 3];
	return (0);
}

void	attack_left_anim(t_game *game)
{
	game->enemy.attack_count = 1;
    game->enemy.anim_frame = 0;
    game->player.frame_count = 0;
    game->game_over = 1;
}

void	attack_right_anim(t_game *game)
{
	game->enemy.attack_count = 2;
    game->enemy.anim_frame = 0;
    game->player.frame_count = 0;
    game->game_over = 1;
}

void	player_attacked_anim(t_game *game)
{
	int frame;

    if (++game->enemy.attack_delay < 200)
		return ;
    game->enemy.attack_delay = 0;
    frame = game->enemy.attack_frame_counter % 2;
    if (game->enemy.attack_count == 2)
		frame += 2;
    game->enemy.img_enemy = game->enemy.attack[frame];
    game->img_player = game->player.attacked[frame];
	game->enemy.attack_frame_counter++;
    mlx_clear_window(game->mlx, game->win);
    load_map(game);
    if (game->enemy.attack_frame_counter >= 20)
        game_over(game);
}
