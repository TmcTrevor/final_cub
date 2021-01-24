/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_elements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <mokhames@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:58:41 by mokhames          #+#    #+#             */
/*   Updated: 2021/01/15 18:35:54 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/cube3d.h"

int		error(void)
{
	printf("wrong argument in resolution line");
	return (exit_all());
}

int		get_resolution(char *c)
{
	int i;

	i = 1;
	if (*c == 'R')
	{
		c++;
		while (c[i] == ' ')
			i++;
		if (*c == '\0' || !(isdigit(c[i])))
			return (error());
		map.el.res_x = ft_atoi(c);
		while (*c == ' ')
			c++;
		while (ft_isdigit(*c))
			c++;
		i = 1;
		while (c[i] == ' ')
			i++;
		if (*c == '\0' || !(isdigit(c[i])))
			return (error());
		map.el.res_y = ft_atoi(c);
	}
	return (1);
}

int		check_letters(int i, int j)
{
	if (map.el.elem[i][j] == 'R')
		map.el.resolution_line = i;
	if (map.el.elem[i][j] == 'N')
		map.el.north_line = i;
	if (map.el.elem[i][j] == 'S')
	{
		if (map.el.elem[i][j + 1] == 'O')
			map.el.south_line = i;
		else
			map.el.sprite_line = i;
	}
	if (map.el.elem[i][j] == 'W')
		map.el.west_line = i;
	if (map.el.elem[i][j] == 'E')
		map.el.east_line = i;
	if (map.el.elem[i][j] == 'F')
		map.el.f_l = i;
	if (map.el.elem[i][j] == 'C')
		map.el.c_l = i;
	return (1);
}

int		create_elements_lines(void)
{
	int i;
	int j;

	i = 0;
	while (map.el.elem[i] != NULL)
	{
		j = 0;
		while (map.el.elem[i][j] != '\0')
		{
			if (check_letters(i, j) < 0)
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int		get_elements(void)
{
	map.el.elem = ft_split(map.parser->data, '\n');
	if (create_elements_lines() < 0)
		return (-1);
	if (get_resolution(map.el.elem[map.el.resolution_line]) < 0)
		return (-1);
	if (get_floor_color() < 0)
		return (-1);
	if (get_ceilling_color() < 0)
		return (-1);
	create_hex_color();
	if (!get_sprite_texture())
		return (-1);
	if (!get_north_texture())
		return (-1);
	if (!get_south_texture())
		return (-1);
	if (!get_west_texture())
		return (-1);
	if (!get_east_texture())
		return (-1);
	return (1);
}
