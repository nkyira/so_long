#ifndef SO_LONG_H
# define SO_LONG_H
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include <math.h>

typedef struct s_xpms
{
	void	*player;
	int		player_x;
	int		player_y;
	void	*wall;
	int		wall_x;
	int		wall_y;
	void	*backround;
	int		backround_x;
	int		backround_y;
	void	*collectible;
	int		collectible_x;
	int		collectible_y;
	void	*exit;
	int		exit_x;
	int		exit_y;
}	t_xpms;

typedef struct s_map
{
	char	**mapxy;
	int		xsize;
	int		ysize;
	int		pxy[2];
	int		exy[2];
	int		cnum;
	int		moves;
}	t_map;

typedef struct s_data
{
	void	*winp;
	void	*mlxp;
	t_map	*map;
	t_xpms	*images;
}	t_data;

int		err_map(t_map *map, int fd);
int		make_map(t_map *map, int fd);
int		valid_path_check(t_map *map);
void	draw_map(t_data *data);

void	move_up(t_data* data);
void	move_down(t_data* data);
void	move_right(t_data* data);
void	move_left(t_data* data);
int		check_exit(t_data* data);

int		setup_xpms(t_xpms *images, void *mlxp);
void	destroy_images(t_xpms *images, void *mlxp);

#endif
