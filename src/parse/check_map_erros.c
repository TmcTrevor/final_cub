/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_erros.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <mokhames@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 09:39:54 by mokhames          #+#    #+#             */
/*   Updated: 2021/01/24 10:21:52 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/cube3d.h"

int		check_map_characters(void)
{
	int i;

	i = 0;
	while (map.parser->map_string[i] != '\0')
	{
		if (map.parser->map_string[i] != '1' &&
			map.parser->map_string[i] != '2' &&
			map.parser->map_string[i] != '0' &&
			map.parser->map_string[i] != 'N' &&
			map.parser->map_string[i] != 'S' &&
			map.parser->map_string[i] != 'E' &&
			map.parser->map_string[i] != 'W' &&
			map.parser->map_string[i] != ' ' &&
			map.parser->map_string[i] != '\n')
		{
			write(1, "Error\n", 6);
			write(1, "Map countains wrong characters\n", 20);
			return (exit_all());
		}
		i++;
	}
	return (1);
}

int		check_around(int i, int j)
{
	if (map.parser->grid[i - 1][j + 1] == ' ')
		return (-1);
	if (map.parser->grid[i - 1][j - 1] == ' ')
		return (-1);
	if (map.parser->grid[i + 1][j - 1] == ' ')
		return (-1);
	if (map.parser->grid[i + 1][j + 1] == ' ')
		return (-1);
	if (map.parser->grid[i][j - 1] == ' ')
		return (-1);
	if (map.parser->grid[i][j + 1] == ' ')
		return (-1);
	if (map.parser->grid[i - 1][j] == ' ')
		return (-1);
	if (map.parser->grid[i + 1][j] == ' ')
		return (-1);
	return (1);
}

int		check_spaces_algo(void)
{
	int i;
	int j;

	i = 1;
	while (i < (map.parser->line_nbr - 1))
	{
		j = 1;
		while (map.parser->grid[i][j] != '\0')
		{
			if ((map.parser->grid[i][j] == '0' && (check_around(i, j) < 0)))
				return (return_error_exit());
			if ((map.parser->grid[i][j] == '2' && (check_around(i, j) < 0)))
				return (return_error_exit());
			j++;
		}
		i++;
	}
	return (1);
}

int		check_dir_letter(void)
{
	if (map.parser->dir == 'N' || map.parser->dir == 'S' ||
		map.parser->dir == 'E' || map.parser->dir == 'W')
		return (0);
	return (-1);
}

int		check_map_errors(void)
{
	if (check_spaces_algo() < 0)
		return (-1);
	if (check_dir_letter() < 0)
		return (-1);
	if (check_map_characters() < 0)
		return (-1);
	return (1);
}
