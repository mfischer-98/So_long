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

int		game_loop(t_game *game)
{
	if (game->player.is_moving)
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
	else
		player_idle(game);
	render_position(game);
	//game->player.is_moving = 0;
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
