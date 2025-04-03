#include "so_long.h"

int	setup_xpms(t_xpms *images, void *mlxp)
{
	images->player = mlx_xpm_file_to_image(mlxp, "assets/player.xpm",
		&images->player_x, &images->player_y);
	images->wall = mlx_xpm_file_to_image(mlxp, "assets/wall.xpm",
		&images->wall_x, &images->wall_y);
	images->backround = mlx_xpm_file_to_image(mlxp, "assets/backround.xpm",
		&images->backround_x, &images->backround_y);
	images->collectible = mlx_xpm_file_to_image(mlxp, "assets/collectible.xpm",
		&images->collectible_x, &images->collectible_y);
	images->exit = mlx_xpm_file_to_image(mlxp, "assets/exit.xpm",
		&images->exit_x, &images->exit_y);
	return (0);
}

void	destroy_images(t_xpms *images, void *mlxp)
{
	if (images->player)
		mlx_destroy_image(mlxp, images->player);
	if (images->wall)
		mlx_destroy_image(mlxp, images->wall);
	if (images->backround)
		mlx_destroy_image(mlxp, images->backround);
	if (images->collectible)
		mlx_destroy_image(mlxp, images->collectible);
	if (images->exit)
		mlx_destroy_image(mlxp, images->exit);
}
