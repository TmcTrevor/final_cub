#include "Headers/cube3d.h"

void	ft_cube(int *x, int *y)
{
	int i;
	int j;
	int a;
	//x *= (map.el.res_x / map.parser->line_nbr) ;
	//y *= (map.el.res_y / map.parser->column_nbr);
	i = *x + (map.el.res_x / map.parser->line_nbr);
	a = *y + (map.el.res_y / map.parser->column_nbr);
	j = *y;
	while (*x < i)
	{
		*y = j;
		while (*y < a)
		{
			img.data[(int)(*y * map.el.res_x + *x)] =0x00ff00;
			(*y)++;
		}
		(*x)++;

	}
}
int draw_map()
{
	int i;
	int j;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	j = 0;
	while(map.parser->grid[i])
	{
		j = 0;
		while(map.parser->grid[i][j])
		{
			if(map.parser->grid[i][j] == '1')
			{
				ft_cube(&x,&y);
				
			}
			if(map.parser->grid[i][j] == '0' || map.parser->grid[i][j] == ' ')
				y += (map.el.res_y / map.parser->column_nbr);

			j++;
		}
		i++;

	}
    return (1);
}