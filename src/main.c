#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;
/* 	char		*floor_path = "img/floor.xpm";
	char		*player_path = "img/player.xpm";
	t_player	player;
	t_data		data; */

	parsing_map(argc, argv, &map);
	free_map(&map); //mudar de lugar depois

	/* // Iniciatializing
	data.mlx = mlx_init();
	if (!data.mlx)
		return (MALLOC_ERROR);

	// Creating window
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "so_long");
	if (!data.win)
	{
		mlx_destroy_display(data.mlx); //clean up mlx connection
		free(data.mlx);
		return (MALLOC_ERROR);
	}

	// Background image
	data.img = mlx_xpm_file_to_image(data.mlx, floor_path, &data.img_width, &data.img_height);
	if (!data.img)
		return (MALLOC_ERROR);

	data.y = 0;
	while (data.y < HEIGHT)
	{
		data.x = 0;
		while (data.x < WIDTH)
		{
			mlx_put_image_to_window(data.mlx, data.win, data.img, data.x, data.y);
			data.x += data.img_width;
		}
		data.y += data.img_height;
	}

	// Formando a imagem player
	player.img = mlx_xpm_file_to_image(data.mlx, player_path, &player.img_width, &player.img_height);
	if (!player.img)
		return (MALLOC_ERROR);
	player.x = 0;
	player.y = 0;
	mlx_put_image_to_window(data.mlx, data.win, player.img, player.x, player.y);
	
	// Key events
	mlx_key_hook(data.win, &handle_input, &data);
	mlx_loop_hook(data.mlx, &handle_input, &data);

	// Game loop
	mlx_loop(data.mlx); //keeps the game going
	return (0); */
}
