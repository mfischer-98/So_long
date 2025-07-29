/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_feat_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:56:20 by mefische          #+#    #+#             */
/*   Updated: 2025/07/29 16:57:45 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	str_message(t_game *game)
{
	char	*str;
	char	*moves;
	char	*full_str;
	int		x;
	int		y;

	str = "Moves: ";
	moves = ft_itoa(game->player.move_counter);
	full_str = ft_strjoin(str, moves);
	x = 70;
	y = (game->map.height * 64) - 10;
	mlx_string_put(game->mlx, game->win, x, y, 0xFFFFFF, full_str);
	if (full_str)
		free(full_str);
	if (moves)
		free(moves);
	x = 70;
	y = (game->map.height * 64) - 30;
	if (game->map.width > 7)
		mlx_string_put(game->mlx, game->win, x, y, 0xFFFFFF,
			"It's moving day! Help Max gather all his precious socks!");
}

int	load_obstacles(t_game *game, int res)
{
	game->extra.img_box = mlx_xpm_file_to_image
		(game->mlx, BOX, &res, &res);
	if (!game->extra.img_box)
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	game->extra.img_open_box = mlx_xpm_file_to_image
		(game->mlx, OPEN_BOX, &res, &res);
	if (!game->extra.img_open_box)
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	game->extra.img_books = mlx_xpm_file_to_image
		(game->mlx, BOOKS, &res, &res);
	if (!game->extra.img_books)
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	game->extra.img_chair = mlx_xpm_file_to_image
		(game->mlx, CHAIR, &res, &res);
	if (!game->extra.img_chair)
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	game->extra.img_jar = mlx_xpm_file_to_image
		(game->mlx, JAR, &res, &res);
	if (!game->extra.img_jar)
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	game->extra.img_lamp = mlx_xpm_file_to_image
		(game->mlx, LAMP, &res, &res);
	if (!game->extra.img_lamp)
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	return (0);
}

int	load_extra_obstacles(t_game *game, int res)
{
	game->extra.img_low_chair = mlx_xpm_file_to_image
		(game->mlx, LOW_CHAIR, &res, &res);
	if (!game->extra.img_low_chair)
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	game->extra.img_plant = mlx_xpm_file_to_image
		(game->mlx, PLANT, &res, &res);
	if (!game->extra.img_plant)
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	game->extra.img_table = mlx_xpm_file_to_image
		(game->mlx, TABLE, &res, &res);
	if (!game->extra.img_table)
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	game->extra.img_sock_dots = mlx_xpm_file_to_image
		(game->mlx, SOCK_DOTS, &res, &res);
	if (!game->extra.img_sock_dots)
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	game->extra.img_sock_dirty = mlx_xpm_file_to_image
		(game->mlx, SOCK_DIRTY, &res, &res);
	if (!game->extra.img_sock_dirty)
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	return (0);
}

void	*random_obstacles(t_game *game)
{
	game->num += 1;
	if (game->num == 1)
		return (game->extra.img_box);
	else if (game->num == 2)
		return (game->extra.img_books);
	else if (game->num == 3)
		return (game->extra.img_low_chair);
	else if (game->num == 4)
		return (game->extra.img_plant);
	else if (game->num == 5)
		return (game->extra.img_open_box);
	else if (game->num == 6)
		return (game->extra.img_jar);
	else if (game->num == 7)
		return (game->extra.img_table);
	else if (game->num == 8)
		return (game->extra.img_chair);
	else if (game->num == 9)
		return (game->extra.img_lamp);
	if (game->num > 9)
		game->num = 0;
	return (game->extra.img_box);
}

void	*select_collectable(t_game *game)
{
	game->num_socks += 1;
	if (game->num_socks == 1)
		return (game->img_collectable);
	if (game->num_socks == 2)
		return (game->extra.img_sock_dirty);
	if (game->num_socks > 3)
		game->num_socks = 0;
	return (game->extra.img_sock_dots);
}
