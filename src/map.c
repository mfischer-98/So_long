#include "so_long.h"

/*  Function to read map file:

1. open and read file .ber
2. use gnl -> free -> find out size in lines (strings)
3. allocate memory with malloc
4. open file again and use gnl to put each line inside **map
5. NULL in the end and close

	Validate map function (int x for columns and int y for rows)
1. see if walls are all around
2. see if there is one player, at least one collectable, one exit
3. see if there is no empty lines in the middle

	Load textures in struct
		game->wall = mlx_xpm_file_to_image(game->mlx, "file_name.xpm", &size, &size);
		...

	Render map
1. while game rows and columns, if 1, put wall, if 0 put floor, etc
*/

