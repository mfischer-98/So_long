#include "../so_long_bonus.h"

int	enemy_idle_anim(t_game *game)
{
	game->enemy.img_enemy = game->enemy.idle[game->enemy.anim_frame % 2];
	mlx_put_image_to_window(game->mlx, game->win, game->enemy.img_enemy,
		game->enemy.x * SIZE, game->enemy.y * SIZE);
	game->enemy.anim_frame++;
	return (0);
}

int alert_enemy_anim(t_game *game)
{
	game->enemy.img_enemy = game->enemy.idle[game->enemy.anim_frame % 2];
	mlx_put_image_to_window(game->mlx, game->win, game->enemy.img_enemy,
		game->enemy.x * SIZE, game->enemy.y * SIZE);
	game->enemy.anim_frame++;
	return (0);
}

int enemy_attack_anim(t_game *game, int side)
{
	if (side == 1)
		attack_left_anim(game);
	if (side == 2)
		attack_right_anim(game);
	return (0);
}

void	attack_left_anim(t_game *game)
{
	game->enemy.img_enemy = game->enemy.attack[0];
	mlx_put_image_to_window(game->mlx, game->win, game->enemy.img_enemy,
		game->enemy.x * SIZE, game->enemy.y * SIZE);
	game->img_player = game->player.attacked[0];
	render_position(game);
	game->enemy.img_enemy = game->enemy.attack[1];
	mlx_put_image_to_window(game->mlx, game->win, game->enemy.img_enemy,
		game->enemy.x * SIZE, game->enemy.y * SIZE);
	game->img_player = game->player.attacked[1];
	render_position(game);
	//mlx_string_put(game->mlx, game->win, 10, 10, 0xFFFFFF, "YOU LOST :(");
	ft_printf("You lost :(\n");
	close_window(game);
}

void	attack_right_anim(t_game *game)
{
	game->enemy.img_enemy = game->enemy.attack[2];
	mlx_put_image_to_window(game->mlx, game->win, game->enemy.img_enemy,
		game->enemy.x * SIZE, game->enemy.y * SIZE);
	game->img_player = game->player.attacked[2];
	render_position(game);
	game->enemy.img_enemy = game->enemy.attack[3];
	mlx_put_image_to_window(game->mlx, game->win, game->enemy.img_enemy,
		game->enemy.x * SIZE, game->enemy.y * SIZE);
	game->img_player = game->player.attacked[3];
	render_position(game);
	//mlx_string_put(game->mlx, game->win, 10, 10, 0xFFFFFF, "YOU LOST :(");
	ft_printf("You lost :(\n");	
	close_window(game);
}
