#include "so_long.h"

void flood_fill(char **map, int x, int y, int *c, int *e)
{
	if (map[y][x] == '1' || map[y][x] == 'F')
		return;
	if (map[y][x] == 'C')
		(*c)++;
	if (map[y][x] == 'E')
		(*e)++;
	map[y][x] = 'F';

	flood_fill(map, x + 1, y, c, e);
	flood_fill(map, x - 1, y, c, e);
	flood_fill(map, x, y + 1, c, e);
	flood_fill(map, x, y - 1, c, e);
}

int valid_path_check(t_map *map)
{
	char **map_cpy;
	int y;
	int	c;
	int e;

	c = 0;
	e = 0;
	map_cpy = malloc(sizeof(char *) * map->ysize);
	y = -1;
	while (y++ < map->ysize - 1)
	{
		map_cpy[y] = malloc(sizeof(char) * map->xsize);
		if (!map->mapxy[y])
		{
			freesplit(map->mapxy, y);
			return (1);
		}
		ft_memcpy(map_cpy[y], map->mapxy[y], map->xsize);
	}
	flood_fill(map_cpy, map->pxy[0], map->pxy[1], &c, &e);
	freesplit(map_cpy, y);
	return (c == map->cnum && e == 1);
}
