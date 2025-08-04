/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_sprites_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:45:01 by mefische          #+#    #+#             */
/*   Updated: 2025/08/04 16:45:01 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	player_idle_sprite(t_game *game, int res)
{
	game->player.idle[0] = mlx_xpm_file_to_image
		(game->mlx, "textures/sprites_player/idle1.xpm", &res, &res);
	if (!game->player.idle[0])
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	game->player.idle[1] = mlx_xpm_file_to_image
		(game->mlx, "textures/sprites_player/idle2.xpm", &res, &res);
	if (!game->player.idle[1])
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	game->player.idle[2] = mlx_xpm_file_to_image
		(game->mlx, "textures/sprites_player/idle3.xpm", &res, &res);
	if (!game->player.idle[2])
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	return (0);
}

int	player_attacked(t_game *game, int res)
{
	game->player.attacked[0] = mlx_xpm_file_to_image
		(game->mlx, "textures/sprites_player/player_attack1_left.xpm",
			&res, &res);
	if (!game->player.attacked[0])
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	game->player.attacked[1] = mlx_xpm_file_to_image
		(game->mlx, "textures/sprites_player/player_attack2_left.xpm",
			&res, &res);
	if (!game->player.attacked[1])
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	game->player.attacked[2] = mlx_xpm_file_to_image
		(game->mlx, "textures/sprites_player/player_attack1_right.xpm",
			&res, &res);
	if (!game->player.attacked[2])
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	game->player.attacked[3] = mlx_xpm_file_to_image
		(game->mlx, "textures/sprites_player/player_attack2_right.xpm",
			&res, &res);
	if (!game->player.attacked[3])
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	return (0);
}

int	enemy_idle(t_game *game, int res)
{
	game->enemy.idle[0] = mlx_xpm_file_to_image
		(game->mlx, "textures/sprites_enemy/cat_idle1.xpm", &res, &res);
	if (!game->enemy.idle[0])
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	game->enemy.idle[1] = mlx_xpm_file_to_image
		(game->mlx, "textures/sprites_enemy/cat_idle2.xpm", &res, &res);
	if (!game->enemy.idle[1])
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	return (0);
}

int	enemy_alert(t_game *game, int res)
{
	game->enemy.alert[0] = mlx_xpm_file_to_image
		(game->mlx, "textures/sprites_enemy/cat_alert1.xpm", &res, &res);
	if (!game->enemy.alert[0])
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	game->enemy.alert[1] = mlx_xpm_file_to_image
		(game->mlx, "textures/sprites_enemy/cat_alert2.xpm", &res, &res);
	if (!game->enemy.alert[1])
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	game->enemy.alert[2] = mlx_xpm_file_to_image
		(game->mlx, "textures/sprites_enemy/cat_alert3.xpm", &res, &res);
	if (!game->enemy.alert[2])
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	return (0);
}

int	enemy_attack(t_game *game, int res)
{
	game->enemy.attack[0] = mlx_xpm_file_to_image
		(game->mlx, "textures/sprites_enemy/cat_attack1_left.xpm", &res, &res);
	if (!game->enemy.attack[0])
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	game->enemy.attack[1] = mlx_xpm_file_to_image
		(game->mlx, "textures/sprites_enemy/cat_attack2_left.xpm", &res, &res);
	if (!game->enemy.attack[1])
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	game->enemy.attack[2] = mlx_xpm_file_to_image
		(game->mlx, "textures/sprites_enemy/cat_attack1_right.xpm", &res, &res);
	if (!game->enemy.attack[2])
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	game->enemy.attack[3] = mlx_xpm_file_to_image
		(game->mlx, "textures/sprites_enemy/cat_attack2_right.xpm", &res, &res);
	if (!game->enemy.attack[3])
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	return (0);
}
