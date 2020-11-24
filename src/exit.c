#include "Headers/cube3d.h"

void	free_paths()
{
	if (map.el.n_path)
	{
		free(map.el.n_path);
		map.el.n_path = 0;
	}
	if (map.el.s_path)
	{
		free(map.el.s_path);
		map.el.s_path = 0;
	}
	if (map.el.e_path)
	{
		free(map.el.e_path);
		map.el.e_path = 0;
	}
	if (map.el.w_path)
	{
		free(map.el.w_path);
		map.el.w_path = 0;
	}
}

void	free_elem()
{
	int i;

	i = -1;
	if (map.el.elem)
	{
		while (++i < 8)
		{
			free(map.el.elem[i]);
			map.el.elem[i] = 0;
		}
		free(map.el.elem);
		map.el.elem = 0;
	}
	free_paths();
	if (map.el.spr_path)
	{
		free(map.el.spr_path);
		map.el.spr_path = 0;
	}
}

void	free_map()
{
	int i;

	i = -1;
	if (map.parser->grid)
	{
		while (++i < map.parser->line_nbr)
		{
			free(map.parser->grid[i]);
			map.parser->grid[i] = 0;
		}
		free(map.parser->grid);
		map.parser->grid = 0;
	}
	free(map.parser->map_string);
	map.parser->map_string = 0;
}

void	free_win()
{
	if (mlx.mlx_ptr && mlx.win)
		mlx_destroy_window(mlx.mlx_ptr, mlx.win);
}

int		exit_all()
{
	free_win();
	free_map();
	free_elem();
	free_tex();
	free_spr();
	exit(0);
	return (-1);
}