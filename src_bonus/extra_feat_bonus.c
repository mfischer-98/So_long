/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_feat_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:56:20 by mefische          #+#    #+#             */
/*   Updated: 2025/08/06 15:59:26 by mefische         ###   ########.fr       */
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
	game->img_obstacles[0] = mlx_xpm_file_to_image
		(game->mlx, BOX, &res, &res);
	if (!game->img_obstacles[0])
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	game->img_obstacles[1] = mlx_xpm_file_to_image
		(game->mlx, OPEN_BOX, &res, &res);
	if (!game->img_obstacles[1])
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	game->img_obstacles[2] = mlx_xpm_file_to_image
		(game->mlx, BOOKS, &res, &res);
	if (!game->img_obstacles[2])
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	game->img_obstacles[3] = mlx_xpm_file_to_image
		(game->mlx, CHAIR, &res, &res);
	if (!game->img_obstacles[3])
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	game->img_obstacles[4] = mlx_xpm_file_to_image
		(game->mlx, JAR, &res, &res);
	if (!game->img_obstacles[4])
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	game->img_obstacles[5] = mlx_xpm_file_to_image
		(game->mlx, LAMP, &res, &res);
	if (!game->img_obstacles[5])
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	return (0);
}

int	load_extra_obstacles(t_game *game, int res)
{
	game->img_obstacles[6] = mlx_xpm_file_to_image
		(game->mlx, LOW_CHAIR, &res, &res);
	if (!game->img_obstacles[6])
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	game->img_obstacles[7] = mlx_xpm_file_to_image
		(game->mlx, PLANT, &res, &res);
	if (!game->img_obstacles[7])
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	game->img_obstacles[8] = mlx_xpm_file_to_image
		(game->mlx, TABLE, &res, &res);
	if (!game->img_obstacles[8])
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	game->img_sock_dots = mlx_xpm_file_to_image
		(game->mlx, SOCK_DOTS, &res, &res);
	if (!game->img_sock_dots )
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	game->img_sock_dirty = mlx_xpm_file_to_image
		(game->mlx, SOCK_DIRTY, &res, &res);
	if (!game->img_sock_dirty)
		return (ft_printf("Error\nFailed image.\n"), close_window(game), 1);
	return (0);
}

void	*random_obstacles(t_game *game)
{
	int	num;

	num = rand() % 9;
	return(game->img_obstacles[num]);
}

void	*select_collectable(t_game *game, int x, int y)
{
	game->num_socks = x + y;
	if (game->num_socks % 2 == 0)
		return (game->img_collectable);
	if (game->num_socks % 5 == 0)
		return (game->img_sock_dirty);
	if (game->num_socks % 3 == 0)
		game->num_socks = 0;
	return (game->img_sock_dots);
}
