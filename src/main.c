#include "so_long.h"

int	main(void)
{
	char	*floor_path = "img/floor.xpm";
	char	*player_path = "img/player.xpm";
	t_mlx_data	data;
	int	x;
	int	y;

// Inicializando
	data.mlx = mlx_init(); //aloca memoria com malloc
	if (!data.mlx)
		return (MALLOC_ERROR);

	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "so_long");
	if (!data.win)
	{
		mlx_destroy_display(data.mlx); //clean up mlx connection
		free(data.mlx);
		return (MALLOC_ERROR);
	}

	// Formando a imagem de fundo
	data.img_floor = mlx_xpm_file_to_image(data.mlx, floor_path, &data.img_width, &data.img_height);
	if (!data.img_floor)
		return (MALLOC_ERROR);

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx_put_image_to_window(data.mlx, data.win, data.img_floor, x, y);
			x += data.img_width;
		}
		y += data.img_height;
	}

	// Formando a imagem player
	data.img_player = mlx_xpm_file_to_image(data.mlx, player_path, &data.img_width, &data.img_height);
	if (!data.img_player)
		return (MALLOC_ERROR);

	mlx_put_image_to_window(data.mlx, data.win, data.img_player, data.x, data.y);
	
	// Key events
	mlx_key_hook(data.win, &handle_input, &data); //lembrar que uso a janela nesse
	mlx_loop_hook(data.mlx, &handle_input, &data); //fecha o loop

	// Game loop
	mlx_loop(data.mlx); //keeps the game going
	return (0);
}