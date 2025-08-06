/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_position_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:45:11 by mefische          #+#    #+#             */
/*   Updated: 2025/08/04 16:45:11 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	player_move(t_game *game)
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

void	*image_enemy(t_game *game, int x, int y)
{
	int	player_left;
	int	player_right;
	int	player_near;

	game->enemy.x = x;
	game->enemy.y = y;
	player_left = game->map.design[game->player.y][game->player.x + 1] == 'N';
	player_right = game->map.design[game->player.y][game->player.x - 1] == 'N';
	player_near = is_near(game);
	if (player_near)
		alert_enemy_anim(game);
	else if (player_left)
		attack_left_anim(game);
	else if (player_right)
		attack_right_anim(game);
	else
		enemy_idle_anim(game);
	return (game->enemy.img_enemy);
}

int	is_near(t_game *game)
{
	if ((game->player.y == game->enemy.y - 1
			|| game->player.y == game->enemy.y + 1)
		&& (game->player.x >= game->enemy.x - 2
			&& game->player.x <= game->enemy.x + 2))
		return (1);
	if ((game->player.y == game->enemy.y - 2
			|| game->player.y == game->enemy.y + 2)
		&& (game->player.x >= game->enemy.x - 2
			&& game->player.x <= game->enemy.x + 2))
		return (1);
	if (game->player.y == game->enemy.y)
	{
		if (game->player.x == game->enemy.x - 2
			|| game->player.x == game->enemy.x + 2)
			return (1);
		if (game->player.x == game->enemy.x - 3
			|| game->player.x == game->enemy.x + 3)
			return (1);
	}
	return (0);
}

void	render_enemy(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.design[y][x] == 'N')
			{
				render_map(game, x, y);
				game->enemy.x = x;
				game->enemy.y = y;
			}
			x++;
		}
		y++;
	}
}
