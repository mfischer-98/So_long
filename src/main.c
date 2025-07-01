#include "so_long.h"

int	main(void)
{
	char	*relative_path = "img/player.xpm";
	t_mlx_data	data;
/* 	int	x;
	int	y; */

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
	data.img = mlx_xpm_file_to_image(data.mlx, relative_path, &data.img_width, &data.img_height);
	if (!data.img)
		return (MALLOC_ERROR);

	mlx_put_image_to_window(data.mlx, data.win, data.img, data.x, data.y);

/* 	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx_put_image_to_window(data.mlx, data.win, data.img, x, y);
			x += data.img_width;
		}
		y += data.img_height;
	} */
	
// Key events
	mlx_key_hook(data.win, &handle_input, &data); //lembrar que uso a janela nesse
	mlx_loop_hook(data.mlx, &handle_input, &data); //fecha o loop

// Game loop
	mlx_loop(data.mlx); //keeps the game going
	return (0);
}