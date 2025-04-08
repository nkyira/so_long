#include "so_long.h"

static int	free_data(t_data* data);

static int	key_win1(int key, t_data* data)
{
	if (key == 'w')
		move_up(data);
	else if (key == 's')
		move_down(data);
	else if (key == 'd')
		move_right(data);
	else if (key == 'a')
		move_left(data);
	ft_printf("Key %d, col : %d, %d moves\n",key, data->map->cnum, data->map->moves);
	if (key ==  65307 || check_exit(data))
	{
		destroy_images(data->images, data->mlxp);
		mlx_destroy_window(data->mlxp, data->winp);
		mlx_loop_end(data->mlxp);
		mlx_destroy_display(data->mlxp);
		free(data->mlxp);
		free_data(data);
		exit(0);
	}
	return (0);
}

static int	close_window(t_data* data)
{
	destroy_images(data->images, data->mlxp);
	freesplit(data->map->mapxy, data->map->ysize);
	mlx_destroy_window(data->mlxp, data->winp);
	mlx_loop_end(data->mlxp);
	mlx_destroy_display(data->mlxp);
	free(data->mlxp);
	free(data->map);
	free(data->images);
	free(data);
	exit(0);
}

static int	free_data(t_data* data)
{
	if (data->map->mapxy)
		freesplit(data->map->mapxy, data->map->ysize);
	if (data->map)
		free(data->map);
	if (data->images)
		free(data->images);
	free(data);
	return (1);
}

static int	setup_map(t_data *data, char **argv)
{
	int		fd;

	data->map = malloc(sizeof(t_map));
	if (!data->map)
		return (free_data(data));
	ft_memset(data->map, 0, sizeof(*data->map));
	data->images = malloc(sizeof(t_xpms));
	if (!data->images)
		return (free_data(data));
	ft_memset(data->images, 0, sizeof(*data->images));
	fd = open(argv[1], O_RDONLY);
	if(fd < 0 || err_map(data->map, fd))
		return (free_data(data));
	fd = open(argv[1], O_RDONLY);
	if (make_map(data->map, fd))
		return (free_data(data));
	if (!valid_path_check(data->map))
		return (free_data(data));
	return (0);
}

int main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2 || ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4))
	{
		ft_printf("Please enter one *.ber file!\n");
		return (1);
	}
	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	ft_memset(data, 0, sizeof(*data));
	if (setup_map(data, argv))
		return(1);

	data->mlxp = mlx_init();
	if (!data->mlxp)
		return (free_data(data));
	setup_xpms(data->images, data->mlxp);
	data->winp = mlx_new_window(data->mlxp, data->map->xsize * 100, data->map->ysize * 100, "win1");

	draw_map(data);

	mlx_key_hook(data->winp, key_win1, data);
	mlx_hook(data->winp, 17, 0, close_window, data);
	mlx_loop(data->mlxp);
}
