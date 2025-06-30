#include "so_long.h"

int handle_input(int keysym, t_mlx_data *data) //keysym 
{
	if (keysym == XK_Escape) //escape key in X11 library
	{
		printf("The %d key (ESC) has been pressed\n", keysym);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(1);
	}
	printf("The %d key has been pressed\n", keysym);
	return (0);
}

int	main(void)
{
	//void	*mlx;
	void	*wind;
	t_img	img;
	t_mlx_data	data;

	data.mlx = mlx_init(); //aloca memoria com malloc
	if (data.mlx == NULL)
		return (MALLOC_ERROR);
	wind = mlx_new_window(data.mlx, WIDTH, HEIGHT, "so_long");
	if (wind == NULL)
	{
		mlx_destroy_display(data.mlx); //clean up mlx connection
		free(data.mlx);
		return (MALLOC_ERROR);
	}

	mlx_loop(data.mlx); //keeps the game going
	return (0);
}