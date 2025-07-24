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

int	reached_goal(t_game *game)
{
	if (game->map.is_collectable == game->player.collected)
		return (1);
	return (0);
}

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

	dir_x = game->player.x; //ou so usar game->img_x e img_y
	dir_y = game->player.y;
	if (keysym == XK_Escape)
		close_window(game);
 	else if (keysym == XK_Right) //&& check_walls(game, right)
		move_right(game, dir_x, dir_y);
	else if (keysym == XK_Left)
		move_left(game, dir_x, dir_y);
	else if (keysym == XK_Up)
		move_up(game, dir_x, dir_y);
	else if (keysym == XK_Down)
		move_down(game, dir_x, dir_y);
	return (0);
}
