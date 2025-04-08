#include "so_long.h"

static void	search_p(char *line, int *pxy, int x, int y)
{
	while (x--)
	{
		if (line[x] == 'P')
		{
			pxy[0] = x;
			pxy[1] = y;
		}
	}
}

static void	search_e(char *line, int *exy, int x, int y)
{
	while (x--)
	{
		if (line[x] == 'E')
		{
			exy[0] = x;
			exy[1] = y;
		}
	}
}

static int free_map(char ***map, int y)
{
	while (y--)
		free(*map[y]);
	free(*map);
	*map = NULL;
	return (1);
}

/* print debug stuff
	ft_printf("0,0 : %c\n", map->mapxy[0][0]);
	ft_printf("1,1 : %c\n", map->mapxy[1][1]);
	ft_printf("2,2 : %c\n", map->mapxy[2][2]);
	ft_printf("player pos : (%d,%d)\n", map->pxy[0], map->pxy[1]);
	ft_printf("exit pos : (%d,%d)\n", map->exy[0], map->exy[1]);
*/
int	make_map(t_map *map, int fd)
{
	char	*line;
	int		y;

	map->mapxy = malloc(sizeof(char *) * map->ysize);
	y = -1;
	while (y++ < map->ysize - 1)
	{
		map->mapxy[y] = malloc(sizeof(char) * map->xsize);
		if (!map->mapxy[y])
			return (free_map(&map->mapxy, y));
		line = get_next_line(fd);
		if (!line)
			return (free_map(&map->mapxy, y + 1));
		ft_memcpy(map->mapxy[y], line, map->xsize);
		search_p(line, map->pxy, map->xsize, y);
		search_e(line, map->exy, map->xsize, y);
		free(line);
	}
	return (0);
}
