#include "so_long.h"

int	check_exit(t_data *data)
{
	int ex;
	int ey;
	int *p;
	char	**m;

	ex = data->map->exy[0];
	ey = data->map->exy[1];
	p = data->map->pxy;
	m = data->map->mapxy;
	if (ex != p[0] || ey != p[1])
	{
		m[ey][ex] = 'E';
	}
	draw_map(data);
	return(data->map->cnum <= 0 && ex == p[0] && ey == p[1]);
}
void	move_up(t_data* data)
{
	int		*px;
	int		*py;
	int		*cs;
	char	**m;

	m = data->map->mapxy;
	px = &data->map->pxy[0];
	py = &data->map->pxy[1];
	cs = &data->map->cnum;
	if (m[*py - 1][*px] == 'C')
		(*cs)--;
	if (m[*py - 1][*px] != '1')
	{
		m[*py][*px] = '0';
		m[*py - 1][*px] = 'P';
		(*py)--;
		data->map->moves++;
	}
}

void	move_down(t_data* data)
{
	int		*px;
	int		*py;
	int		*cs;
	char	**m;

	m = data->map->mapxy;
	px = &data->map->pxy[0];
	py = &data->map->pxy[1];
	cs = &data->map->cnum;
	if (m[*py + 1][*px] == 'C')
		(*cs)--;
	if (m[*py + 1][*px] != '1')
	{
		m[*py][*px] = '0';
		m[*py + 1][*px] = 'P';
		(*py)++;
		data->map->moves++;
	}
}

void	move_right(t_data* data)
{
	int		*px;
	int		*py;
	int		*cs;
	char	**m;

	m = data->map->mapxy;
	px = &data->map->pxy[0];
	py = &data->map->pxy[1];
	cs = &data->map->cnum;
	if (m[*py][*px + 1] == 'C')
		(*cs)--;
	if (m[*py][*px + 1] != '1')
	{
		m[*py][*px] = '0';
		m[*py][*px + 1] = 'P';
		(*px)++;
		data->map->moves++;
	}
}

void	move_left(t_data* data)
{
	int		*px;
	int		*py;
	int		*cs;
	char	**m;

	m = data->map->mapxy;
	px = &data->map->pxy[0];
	py = &data->map->pxy[1];
	cs = &data->map->cnum;
	if (m[*py][*px - 1] == 'C')
		(*cs)--;
	if (m[*py][*px - 1] != '1')
	{
		m[*py][*px] = '0';
		m[*py][*px - 1] = 'P';
		(*px)--;
		data->map->moves++;
	}
}

