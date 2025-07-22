/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 10:30:42 by mefische          #+#    #+#             */
/*   Updated: 2025/07/09 10:30:42 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	//dar free a tudo mapa, imagens etc
	free(game->mlx);
	exit(1);
}

int	handle_input(int keysym, t_game *game)
{
	int	dir_x;
	int	dir_y;

	dir_x = 0;
	dir_y = 0;
	if (keysym == XK_Escape) //escape key in X11 library
		close_window(game);
	else if (keysym == XK_Right)
	{
		dir_x += 1;
	}
	return (0);
}