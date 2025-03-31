#include "so_long.h"

int		key_win1(int key, t_data* data)
{
	ft_printf("Key %d, p = %p\n",key, data);
	if (key ==  65307)
	{
		mlx_destroy_image(data->mlxp, data->images->im1);
		mlx_destroy_window(data->mlxp, data->winp);
		mlx_loop_end(data->mlxp);
		mlx_destroy_display(data->mlxp);
		free(data->mlxp);
		free(data->map);
		free(data->images);
		free(data);
		exit(0);
	}
	return (0);
}

int		mouse_win1(int button, int x, int y, void *p)
{
	ft_printf("Mouse, button : %d, at (%d,%d), p : %p\n", button, x, y, p);
	return (0);
}

int main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		return (1);
	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	data->map = malloc(sizeof(t_map));
	if (!data->map)
	{
		free(data);
		return (1);
	}
	data->images = malloc(sizeof(t_map));
	if (!data->map)
	{
		free(data);
		return (1);
	}
	if(make_map(data->map, open(argv[1], O_RDONLY)))
	{
		free(data->mlxp);
		free(data->map);
		free(data->images);
		free(data);
		return (1);
	}
	
	if (!(data->mlxp = mlx_init()))
		exit (1);
	data->winp = mlx_new_window(data->mlxp, 1000, 1000, "win1");
	data->images->im1 = mlx_xpm_file_to_image(data->mlxp,"src/Capture.xpm",&data->images->xpm1_x, &data->images->xpm1_y);
	if (!data->images->im1)
	{
		ft_printf("image error\n");
		exit (1);
	}
	mlx_put_image_to_window(data->mlxp, data->winp, data->images->im1, 200, 200);
	mlx_mouse_hook(data->winp, mouse_win1, 0);
	mlx_key_hook(data->winp, key_win1, data);
	mlx_loop(data->mlxp);
}
