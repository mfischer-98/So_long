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
	t_data		data;
	t_player	player;

	if (!parsing_map(argc, argv, &map))
	{
		free_map(&map);
		return (1);
	}
	game.mlx = mlx_init();
	if (!game.mlx)
		return (MALLOC_ERROR);
	game.win = mlx_new_window(game.mlx, WIDTH, HEIGHT, "so_long");
	if (!game.win)
	{
		mlx_destroy_display(game.mlx);//clean up mlx connection
		free(game.mlx);
		return (MALLOC_ERROR);
	}
	render_map(&map, &data, &game, &player);
	//mouse_hook(game.win, &mlx_mouse_hook, &game);
	mlx_key_hook(game.win, &handle_input, &game);
	mlx_loop_hook(game.mlx, &handle_input, &game);
	mlx_loop(game.mlx);
	return (0);
}
