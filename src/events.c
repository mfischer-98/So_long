#include "so_long.h"

int player_moves(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Right)
	{
		data->x += data->img_width;
		mlx_clear_window(data->mlx, data->win);
		mlx_put_image_to_window(data->mlx, data->win, data->img, data->x, data->y);
	}
	if (keysym == XK_Left)
	{
		data->x -= data->img_width;
		mlx_clear_window(data->mlx, data->win);
		mlx_put_image_to_window(data->mlx, data->win, data->img, data->x, data->y);
	}
	if (keysym == XK_Up)
	{
		data->y -= data->img_width;
		mlx_clear_window(data->mlx, data->win);
		mlx_put_image_to_window(data->mlx, data->win, data->img, data->x, data->y);
	}
	if (keysym == XK_Down)
	{
		data->y += data->img_width;
		mlx_clear_window(data->mlx, data->win);
		mlx_put_image_to_window(data->mlx, data->win, data->img, data->x, data->y);
	}
	return (0);
}

int handle_input(int keysym, t_mlx_data *data) //keysym 
{
	if (keysym == XK_Escape) //escape key in X11 library
	{
		mlx_destroy_window(data->mlx, data->win);
		//mlx_destroy_display(data->mlx);
		//free(data->mlx);
		//exit(1);
	}
	else
		player_moves(keysym, data);
	return (0);
	//printf("The %d key has been pressed\n", keysym);
}