#include "../Headers/cube3d.h"

int		return_error_exit()
{
	write(1, "Error\n", 6);
	write(1, "Map not surrounded by 1\n", 24);
	//exit_all(m);
	return (-1);
}

int     check_borders_columns()
{
    int i;
	int j;

	i = 0;
	while (map.parser->grid[i] != NULL)
	{
		j = 0;
		while (map.parser->grid[i][j] != '\0')
			j++;
		if (map.parser->grid[i][j - 1] != '1')
			return_error_exit();
		i++;
	}
	i = 0;
	while (map.parser->grid[i] != NULL)
	{
		if (map.parser->grid[i][0] != '1' && map.parser->grid[i][0] != ' ')
			return_error_exit();
		i++;
	}
	return (1);
}
int     check_borders_lines()
{
    int i;

    i = 0;

    while (map.parser->grid[0][i] != '\0')
	{
		if (map.parser->grid[0][i] != '1' && map.parser->grid[0][i] != ' ')
			return_error_exit();
		i++;
	}
	i = 0;
	while (map.parser->grid[map.parser->line_nbr - 1][i] != '\0')
	{
		if ((map.parser->grid[map.parser->line_nbr - 1][i] != '1') &&
			(map.parser->grid[map.parser->line_nbr - 1][i] != ' '))
			return_error_exit();
		i++;
	}

    return (1);
}