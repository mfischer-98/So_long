/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:23:01 by mefische          #+#    #+#             */
/*   Updated: 2025/07/28 14:23:01 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	game_over(t_game *game)
{
	// int	wait;
	// int	middle_w;
	// int	middle_h;

	// wait = 0;
	// middle_w = (game->map.width * 64) / 2 - 80;
	// middle_h = (game->map.height * 64) / 2 - 20;
	// while (wait < 30000)
	// {
	// 	mlx_clear_window(game->mlx, game->win);
	// 	mlx_string_put(game->mlx, game->win, middle_w,
	// 		middle_h, 0xFFFFFF, "YOU LOST :(");
	// 	wait++;
	// }
	ft_printf("GAME OVER\nStay away from cats next time :(\n");
	close_window(game);
}

int	game_loop(t_game *game)
{
	if (game->player.is_moving)
		player_move(game);
	else
		player_idle(game);
	if (++game->enemy.anim_delay >= ANIM_SPEED)
	{
		game->enemy.anim_delay = 0;
		game->enemy.anim_frame++;
	}
	if (game->game_over)
		player_attacked_anim(game);
	else
	{
		render_player(game);
		render_enemy(game);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_game		game;
	t_map		map;
	t_player	player;
	t_enemy		enemy;

	if (!parsing_map(argc, argv, &map))
	{
		if (map.design)
			free_map(&map);
		return (1);
	}
	game.mlx = mlx_init();
	if (!game.mlx)
		return (MALLOC_ERROR);
	game.win = mlx_new_window(game.mlx, map.width * SIZE,
			map.height * SIZE, "so_long");
	if (!game.win)
		return (close_window(&game), MALLOC_ERROR);
	player.move_counter = 0;
	render_init(&game, &map, &player, &enemy);
	mlx_hook(game.win, 17, 0, &close_window, &game);
	mlx_key_hook(game.win, &handle_key_press, &game);
	mlx_loop_hook(game.mlx, &game_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
