/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   borders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <mokhames@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 15:55:07 by mokhames          #+#    #+#             */
/*   Updated: 2021/02/10 12:30:03 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/cube3d.h"

int		return_error_exit(void)
{
	write(1, "Error\n", 6);
	write(1, "Map not surrounded by 1\n", 24);
	return (exit_all());
}

int		check_borders_columns(void)
{
	int i;
	int j;

	i = 0;
	while (g_map.parser->grid[i] != NULL)
	{
		j = 0;
		while (g_map.parser->grid[i][j] != '\0')
			j++;
		if (g_map.parser->grid[i][j - 1] != '1' &&
			g_map.parser->grid[i][j - 1] != ' ')
			return_error_exit();
		i++;
	}
	i = 0;
	while (g_map.parser->grid[i] != NULL)
	{
		if (g_map.parser->grid[i][0] != '1' && g_map.parser->grid[i][0] != ' ')
			return_error_exit();
		i++;
	}
	return (1);
}

int		check_borders_lines(void)
{
	int i;

	i = 0;
	while (g_map.parser->grid[0][i] != '\0')
	{
		if (g_map.parser->grid[0][i] != '1' && g_map.parser->grid[0][i] != ' ')
			return_error_exit();
		i++;
	}
	i = 0;
	while (g_map.parser->grid[g_map.parser->line_nbr - 1][i] != '\0')
	{
		if ((g_map.parser->grid[g_map.parser->line_nbr - 1][i] != '1') &&
			(g_map.parser->grid[g_map.parser->line_nbr - 1][i] != ' '))
			return_error_exit();
		i++;
	}
	return (1);
}
