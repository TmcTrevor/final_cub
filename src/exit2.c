/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <mokhames@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 10:25:59 by mokhames          #+#    #+#             */
/*   Updated: 2021/01/24 11:28:07 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers/cube3d.h"

void	free_parser(void)
{
	free(map.parser);
	map.parser = 0;
}

void	free_ray(void)
{
	free(map.ray);
	map.ray = 0;
}

void	free_map(void)
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
