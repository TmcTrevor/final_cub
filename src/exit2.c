/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <mokhames@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 10:25:59 by mokhames          #+#    #+#             */
/*   Updated: 2021/01/24 19:25:39 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers/cube3d.h"

void	free_parser(void)
{
	free(g_map.parser);
	g_map.parser = 0;
}

void	free_ray(void)
{
	free(g_map.ray);
	g_map.ray = 0;
}

void	free_map(void)
{
	int i;

	i = -1;
	if (g_map.parser->grid)
	{
		while (++i < g_map.parser->line_nbr)
		{
			free(g_map.parser->grid[i]);
			g_map.parser->grid[i] = 0;
		}
		free(g_map.parser->grid);
		g_map.parser->grid = 0;
	}
	free(g_map.parser->map_string);
	g_map.parser->map_string = 0;
}
