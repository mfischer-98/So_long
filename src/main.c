/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 10:30:45 by mefische          #+#    #+#             */
/*   Updated: 2025/07/09 10:30:45 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map		map;
	t_game		game;
	t_player	player;

	if (!parsing_map(argc, argv, &map))
	{
		free_map(&map);
		return (1);
	}
	game.mlx = mlx_init();
	if (!game.mlx)
		return (MALLOC_ERROR);
	game.win = mlx_new_window(game.mlx, map.width * SIZE, map.height * SIZE, "so_long");
	if (!game.win)
	{
		close_window(&game);
		return (MALLOC_ERROR);
	}
	render_map(&map, &game, &player);
	mlx_hook(game.win, 17, 0, &close_window, &game); //close window
	mlx_key_hook(game.win, &handle_input, &game);
	mlx_loop_hook(game.mlx, &handle_input, &game);
	mlx_loop(game.mlx);
	return (0);
}
