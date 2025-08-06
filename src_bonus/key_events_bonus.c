/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:45:31 by mefische          #+#    #+#             */
/*   Updated: 2025/08/04 16:45:31 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_exit(t_game *game, int dir_x, int dir_y)
{
	game->exit_y = dir_y;
	game->exit_x = dir_x;
	game->map.design[dir_y][dir_x] = 'P';
}

int	reached_goal(t_game *game)
{
	if (game->map.is_collectable == game->player.collected)
		return (1);
	return (0);
}

int	handle_key_press(int keysym, t_game *game)
{
	int	dir_x;
	int	dir_y;

	dir_x = game->player.x;
	dir_y = game->player.y;
	if (keysym == XK_Escape)
		close_window(game);
	else if (keysym == XK_Right || keysym == XK_d)
		move_right(game, dir_x, dir_y);
	else if (keysym == XK_Left || keysym == XK_a)
		move_left(game, dir_x, dir_y);
	else if (keysym == XK_Up || keysym == XK_w)
		move_up(game, dir_x, dir_y);
	else if (keysym == XK_Down || keysym == XK_s)
		move_down(game, dir_x, dir_y);
	return (0);
}
