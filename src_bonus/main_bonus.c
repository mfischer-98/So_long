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

int	reached_goal(t_game *game)
{
	if (game->map.is_collectable == game->player.collected)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game		game;
	t_map		map;
	t_player	player;

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
	{
		close_window(&game);
		return (MALLOC_ERROR);
	}
	player.move_counter = 0;
	render_init(&game, &map, &player);
	mlx_hook(game.win, 17, 0, &close_window, &game);
	mlx_key_hook(game.win, &handle_input, &game);
	mlx_loop(game.mlx);
	return (0);
}
