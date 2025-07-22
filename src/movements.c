#include "so_long.h"

int	check_walls() //check if its possible to go to new position

int	player_right(t_map *map, t_game *game)
{
	if (map->design[y][x] == '0')
	{
		mlx_destroy_image();
		img_floor();
		t_game->x += SIZE;
		img_player(t_game, game);
	}
	return (0);
}
/* 
int	player_left()
{

}
int	player_down()
{

}

int	player_up()
{

} */

int	player_moves(int keysym, t_game *game, t_player *player, t_map *map)
{
	game->img_x = player->x;
	game->img_y = player->y;
	if (keysym == XK_Right)
		player_right(map, game);
	return (0);
}