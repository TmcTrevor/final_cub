#include "../Headers/cube3d.h"



int		get_position2(int i, int j)
{
	if ((ft_isalpha(map.parser->grid[i][j])))
	{
		map.parser->pos_x_init = j + 0.5;
		map.parser->pos_y_init = i + 0.5;
		if (map.parser->dir == 0)
			map.parser->dir = map.parser->grid[i][j];
		else
			return (0);
		map.parser->grid[i][j] = '0';
	}
	if (map.parser->grid[i][j] == '2')
		map.spr.numsprites += 1;
	return (1);
}

int		get_position()
{
	int i;
	int j;

	i = 0;
	while (map.parser->grid[i] != NULL)
	{
		j = 0;
		while (map.parser->grid[i][j] != '\0')
		{
			get_position2(i, j);
			j++;
		}
		i++;
	}
	map.parser->line_nbr = i;
	map.parser->column_nbr = j;
	return (1);
}

int		create_map()
{
	if (!(map.parser->grid = ft_split(map.parser->map_string, '\n')))
		return (-1);
	if (get_position() < 0)
		return (-1);
	if (check_borders_lines() < 0)
		return (-1);
	if (check_borders_columns() < 0)
		return (-1);
      
	return (1);
}