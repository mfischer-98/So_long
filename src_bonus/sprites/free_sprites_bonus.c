/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_sprites_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 08:29:00 by mefische          #+#    #+#             */
/*   Updated: 2025/08/05 15:46:11 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	free_sprite(t_game *game, void **sprite, int i)
{
	if (sprite[i])
	{
		mlx_destroy_image(game->mlx, sprite[i]);
		//ft_printf("\nsprite [%d]\n", i);
	}
}

void	free_player(t_game *game)
{
	//ft_printf("player idle");
	free_sprite(game, game->player.idle, 0);
	free_sprite(game, game->player.idle, 1);
	free_sprite(game, game->player.idle, 2);
	//ft_printf("player walk down");
	free_sprite(game, game->player.walk_down, 0);
	free_sprite(game, game->player.walk_down, 1);
	free_sprite(game, game->player.walk_down, 2);
	//ft_printf("player walk up");
	free_sprite(game, game->player.walk_up, 0);
	free_sprite(game, game->player.walk_up, 1);
	free_sprite(game, game->player.walk_up, 2);
	//ft_printf("player walk right");
	free_sprite(game, game->player.walk_right, 0);
	free_sprite(game, game->player.walk_right, 1);
	free_sprite(game, game->player.walk_right, 2);
	//ft_printf("player walk left");
	free_sprite(game, game->player.walk_left, 0);
	free_sprite(game, game->player.walk_left, 1);
	free_sprite(game, game->player.walk_left, 2);
	//ft_printf("player attacked");
	free_sprite(game, game->player.attacked, 0);
	free_sprite(game, game->player.attacked, 1);
	free_sprite(game, game->player.attacked, 2);
	free_sprite(game, game->player.attacked, 3);
}

void	free_enemy(t_game *game)
{
	//ft_printf("enemy idle");
	free_sprite(game, game->enemy.idle, 0);
	free_sprite(game, game->enemy.idle, 1);
	//ft_printf("enemy alert");
	free_sprite(game, game->enemy.alert, 0);
	free_sprite(game, game->enemy.alert, 1);
	free_sprite(game, game->enemy.alert, 2);
	//ft_printf("enemy attack");
	free_sprite(game, game->enemy.attack, 0);
	free_sprite(game, game->enemy.attack, 1);
	free_sprite(game, game->enemy.attack, 2);
	free_sprite(game, game->enemy.attack, 3);
}
