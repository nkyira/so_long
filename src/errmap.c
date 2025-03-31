#include "so_long.h"

int len_no_nl(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			break;
		i++;
	}
	return (i);
}

int side_is_ones(char *line, int size)
{
	if (line[0] == '1' && line[size - 1] == '1')
		return (1);
	return (0);
}

int all_ones(char *line)
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

int make_map(t_map *map, int fd)
{
	char *line;

	line = get_next_line(fd);
	if (!all_ones(line))
	{
		free(line);
		return (0);
	}
	ft_printf("len = %d : %s", len_no_nl(line), line);
	map->xsize = len_no_nl(line);
	map->ysize = 0;
	free(line);
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		ft_printf("len = %d, all_ones = %d : %s", len_no_nl(line), all_ones(line), line);
		if (len_no_nl(line) != map->xsize)
		{
			free(line);
			return (1);
		}
		if (!side_is_ones(line, map->xsize))
		{
			free(line);
			return (1);
		}
		free(line);
		map->ysize++;
	}
	return 0;
}
