#include "so_long.h"

static int len_no_nl(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			break;
		i++;
	}
	return (i);
}

static int all_ones(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			break;
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	check_pce(char *line, int size, int *p, int *c, int *e)
{
	if (line[0] != '1' || line[size - 1] != '1')
		return (1);
	while (*line)
	{
		if (*line == '\n')
			break;
		else if (*line == 'P')
			(*p)++;
		else if (*line == 'E')
			(*e)++;
		else if (*line == 'C')
			(*c)++;
		else if (*line != '1' && *line != '0')
			return (1);
		line++;
	}
	return (0);
}

static int	free_line(char *line)
{
	free(line);
	return (1);
}

/*	print debug stuff :
	ft_printf("len = %d, all_ones = %d : %s", len_no_nl(line), all_ones(line), line);
	ft_printf("len = %d, all_ones = %d : %s", len_no_nl(line), all_ones(line), line);
	ft_printf("players : %d\n", pce[0]);
	ft_printf("exits : %d\n", pce[2]);
	ft_printf("collectibles : %d\n", pce[1]);
*/
int err_map(t_map *map, int fd)
{
	char	*line;
	int		pce[3] = {0};
	bool	last_line_ones;

	line = get_next_line(fd);
	if (!all_ones(line))
		return (free_line(line));
	map->xsize = len_no_nl(line);
	map->ysize = 1;
	free(line);
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		if (len_no_nl(line) != map->xsize)
			return (free_line(line));
		if (check_pce(line, map->xsize, &pce[0], &pce[1], &pce[2]))
			return (free_line(line));
		last_line_ones = all_ones(line);
		free(line);
		map->ysize++;
	}
	map->cnum = pce[1];
	return (pce[0] != 1 || pce[2] != 1 || pce[1] < 1 || !last_line_ones);
}
