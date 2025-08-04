/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:45:06 by mefische          #+#    #+#             */
/*   Updated: 2025/08/04 16:45:06 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	animation_sprite(t_game *game, int res)
{
	walk_down_sprite(game, res);
	walk_up_sprite(game, res);
	walk_right_sprite(game, res);
	walk_left_sprite(game, res);
	player_idle_sprite(game, res);
	player_attacked(game, res);
	enemy_idle(game, res);
	enemy_alert(game, res);
	enemy_attack(game, res);
	return (0);
}

int	walk_down_sprite(t_game *game, int res)
{
	game->player.walk_down[0] = mlx_xpm_file_to_image
		(game->mlx, "textures/sprites_player/walk_down1.xpm", &res, &res);
	if (!game->player.walk_down[0])
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	game->player.walk_down[1] = mlx_xpm_file_to_image
		(game->mlx, "textures/sprites_player/walk_down2.xpm", &res, &res);
	if (!game->player.walk_down[1])
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	game->player.walk_down[2] = mlx_xpm_file_to_image
		(game->mlx, "textures/sprites_player/walk_down3.xpm", &res, &res);
	if (!game->player.walk_down[2])
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	return (0);
}

int	walk_up_sprite(t_game *game, int res)
{
	game->player.walk_up[0] = mlx_xpm_file_to_image
		(game->mlx, "textures/sprites_player/walk_up1.xpm", &res, &res);
	if (!game->player.walk_up[0])
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	game->player.walk_up[1] = mlx_xpm_file_to_image
		(game->mlx, "textures/sprites_player/walk_up2.xpm", &res, &res);
	if (!game->player.walk_up[1])
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	game->player.walk_up[2] = mlx_xpm_file_to_image
		(game->mlx, "textures/sprites_player/walk_up3.xpm", &res, &res);
	if (!game->player.walk_up[2])
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	return (0);
}

int	walk_right_sprite(t_game *game, int res)
{
	game->player.walk_right[0] = mlx_xpm_file_to_image
		(game->mlx, "textures/sprites_player/walk_right1.xpm", &res, &res);
	if (!game->player.walk_right[0])
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	game->player.walk_right[1] = mlx_xpm_file_to_image
		(game->mlx, "textures/sprites_player/walk_right2.xpm", &res, &res);
	if (!game->player.walk_right[1])
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	game->player.walk_right[2] = mlx_xpm_file_to_image
		(game->mlx, "textures/sprites_player/walk_right3.xpm", &res, &res);
	if (!game->player.walk_right[2])
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	return (0);
}

int	walk_left_sprite(t_game *game, int res)
{
	game->player.walk_left[0] = mlx_xpm_file_to_image
		(game->mlx, "textures/sprites_player/walk_left1.xpm", &res, &res);
	if (!game->player.walk_left[0])
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	game->player.walk_left[1] = mlx_xpm_file_to_image
		(game->mlx, "textures/sprites_player/walk_left2.xpm", &res, &res);
	if (!game->player.walk_left[1])
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	game->player.walk_left[2] = mlx_xpm_file_to_image
		(game->mlx, "textures/sprites_player/walk_left3.xpm", &res, &res);
	if (!game->player.walk_left[2])
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	return (0);
}
