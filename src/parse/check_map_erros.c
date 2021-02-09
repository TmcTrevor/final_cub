/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_erros.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <mokhames@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 09:39:54 by mokhames          #+#    #+#             */
/*   Updated: 2021/02/09 17:29:14 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/cube3d.h"

int		check_map_characters(void)
{
	int i;

	i = 0;
	while (g_map.parser->map_string[i] != '\0')
	{
		if (g_map.parser->map_string[i] != '1' &&
			g_map.parser->map_string[i] != '2' &&
			g_map.parser->map_string[i] != '0' &&
			g_map.parser->map_string[i] != 'N' &&
			g_map.parser->map_string[i] != 'S' &&
			g_map.parser->map_string[i] != 'E' &&
			g_map.parser->map_string[i] != 'W' &&
			g_map.parser->map_string[i] != ' ' &&
			g_map.parser->map_string[i] != '\n')
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
	/*if (g_map.parser->grid[i - 1][j + 1] == ' ')
		return (-1);
	if (g_map.parser->grid[i - 1][j - 1] == ' ')
		return (-1);
	if (g_map.parser->grid[i + 1][j - 1] == ' ')
		return (-1);
	if (g_map.parser->grid[i + 1][j + 1] == ' ')
		return (-1);*/
	if (g_map.parser->grid[i][j - 1] == ' ')
		return (-1);
	if (g_map.parser->grid[i][j + 1] == ' ')
		return (-1);
	if (g_map.parser->grid[i - 1][j] == ' ')
		return (-1);
	if (g_map.parser->grid[i + 1][j] == ' ')
		return (-1);
	return (1);
}

int		check_spaces_algo(void)
{
	int i;
	int j;

	i = 1;
	while (i < (g_map.parser->line_nbr - 1))
	{
		j = 1;
		while (g_map.parser->grid[i][j] != '\0')
		{
			if ((g_map.parser->grid[i][j] == '0' && (check_around(i, j) < 0)))
				return (return_error_exit(5));
			if ((g_map.parser->grid[i][j] == '2' && (check_around(i, j) < 0)))
				return (return_error_exit(6));
			j++;
		}
		i++;
	}
	return (1);
}

int		check_dir_letter(void)
{
	if (g_map.parser->dir == 'N' || g_map.parser->dir == 'S' ||
		g_map.parser->dir == 'E' || g_map.parser->dir == 'W')
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
