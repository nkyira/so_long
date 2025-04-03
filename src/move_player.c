#include "so_long.h"

void	move_up(t_data* data)
{
	int *px;
	int *py;
	char **m;

	m = data->map->mapxy;
	px = &data->map->pxy[0];
	py = &data->map->pxy[1];
	if (m[*py - 1][*px] != '1')
	{
		m[*py][*px] = '0';
		m[*py - 1][*px] = 'P';
		(*py)--;
	}
	draw_map(data);
}

void	move_down(t_data* data)
{
	int *px;
	int *py;
	char **m;

	m = data->map->mapxy;
	px = &data->map->pxy[0];
	py = &data->map->pxy[1];
	if (m[*py + 1][*px] != '1')
	{
		m[*py][*px] = '0';
		m[*py + 1][*px] = 'P';
		(*py)++;
	}
	draw_map(data);
}

void	move_right(t_data* data)
{
	int *px;
	int *py;
	char **m;

	m = data->map->mapxy;
	px = &data->map->pxy[0];
	py = &data->map->pxy[1];
	if (m[*py][*px + 1] != '1')
	{
		m[*py][*px] = '0';
		m[*py][*px + 1] = 'P';
		(*px)++;
	}
	draw_map(data);
}

void	move_left(t_data* data)
{
	int *px;
	int *py;
	char **m;

	m = data->map->mapxy;
	px = &data->map->pxy[0];
	py = &data->map->pxy[1];
	if (m[*py][*px - 1] != '1')
	{
		m[*py][*px] = '0';
		m[*py][*px - 1] = 'P';
		(*px)--;
	}
	draw_map(data);
}

