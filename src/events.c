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

 int	player_moves(int keysym, t_game *game, t_data *data, t_player *player)
{
	return (0); //function not working
	data->x = player->x;
	data->y = player->y;
	if (keysym == XK_Right)
	{
		img_floor(data, game);
		data->x += data->img_width;
		img_player(data, game);
	}
	if (keysym == XK_Left)
	{
		img_floor(data, game);
		data->x -= data->img_width;
		img_player(data, game);
	}
	if (keysym == XK_Up)
	{
		img_floor(data, game);
		data->y -= data->img_width;
		img_player(data, game);
	}
	if (keysym == XK_Down)
	{
		img_floor(data, game);
		data->y += data->img_width;
		img_player(data, game);
	}
	return (0);
}

/* int	mouse_hook(int event, t_game *game)
{
	if (event == 17)
	{
		int close_window(game);
		free(game->mlx);
		exit(1);
	}
}*/

int	handle_input(int keysym, t_game *game, t_data *data, t_player *player)
{

	if (keysym == XK_Escape) //escape key in X11 library
	{
 		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit(1);
	}
	else
		player_moves(keysym, game, data, player);
	return (0);
}