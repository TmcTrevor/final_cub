/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <mokhames@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 18:32:24 by mokhames          #+#    #+#             */
/*   Updated: 2021/01/24 18:20:40 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/cube3d.h"

int		get_position2(int i, int j)
{
	if ((ft_isalpha(g_map.parser->grid[i][j])))
	{
		g_map.parser->pos_x_init = j + 0.5;
		g_map.parser->pos_y_init = i + 0.5;
		if (g_map.parser->dir == 0)
			g_map.parser->dir = g_map.parser->grid[i][j];
		else
			return (0);
		g_map.parser->grid[i][j] = '0';
	}
	if (g_map.parser->grid[i][j] == '2')
		g_map.numsprites += 1;
	return (1);
}

int		get_position(void)
{
	int i;
	int j;

	i = 0;
	while (g_map.parser->grid[i] != NULL)
	{
		j = 0;
		while (g_map.parser->grid[i][j] != '\0')
		{
			get_position2(i, j);
			j++;
		}
		i++;
	}
	g_map.parser->line_nbr = i;
	g_map.parser->column_nbr = j;
	return (1);
}

int		create_map(void)
{
	if (!(g_map.parser->grid = ft_split(g_map.parser->map_string, '\n')))
		return (-1);
	if (get_position() < 0)
		return (-1);
	if (check_borders_lines() < 0)
		return (-1);
	if (check_borders_columns() < 0)
		return (-1);
	return (1);
}
