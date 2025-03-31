#ifndef SO_LONG_H
# define SO_LONG_H
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
#include <fcntl.h>
# include <math.h>

typedef struct s_xpms
{
	void	*im1;
	int		xpm1_x;
	int		xpm1_y;
}	t_xpms;

typedef struct s_map
{
	char	**mapxy;
	int		xsize;
	int		ysize;
	int		pxy[2];
	int		exy[2];
	int		cnum;
}	t_map;

typedef struct s_data
{
	void	*winp;
	void	*mlxp;
	t_map	*map;
	t_xpms	*images;
}	t_data;

int		make_map(t_map *map, int fd);

#endif
