#include "so_long.h"

static void	*ctop(t_xpms *images, char c)
{
	if (c == 'P')
		return (images->player); 
	else if (c == '1')
		return (images->wall); 
	else if (c == '0')
		return (images->backround); 
	else if (c == 'C')
		return (images->collectible); 
	else if (c == 'E')
		return (images->exit); 
	return (NULL);
}

static void	draw_map1(void *mlxp, void *winp, t_xpms *images, t_map *map)
{
	int x;
	int y;
	char **draw_m;

	y = map->ysize;
	draw_m = map->mapxy;

	while (y--)
	{
		x = map->xsize;
		while (x--)
		{
			mlx_put_image_to_window(mlxp, winp, ctop(images, draw_m[y][x]), x * 100, y * 100);
		}
	}
}

void	draw_map(t_data *data)
{
	draw_map1(data->mlxp, data->winp, data->images, data->map);
}
