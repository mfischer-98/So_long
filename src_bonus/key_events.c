#include "so_long_bonus.h"

int	handle_key_press(int keysym, t_game *game)
{
	int	dir_x;
	int	dir_y;

	dir_x = game->player.x;
	dir_y = game->player.y;
	if (keysym == XK_Escape)
		close_window(game);
	else if (keysym == XK_Right)
		move_right(game, dir_x, dir_y);
	else if (keysym == XK_Left)
		move_left(game, dir_x, dir_y);
	else if (keysym == XK_Up)
		move_up(game, dir_x, dir_y);
	else if (keysym == XK_Down)
		move_down(game, dir_x, dir_y);
	return (0);
}