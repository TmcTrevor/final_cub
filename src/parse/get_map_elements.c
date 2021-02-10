/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_elements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <mokhames@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:58:41 by mokhames          #+#    #+#             */
/*   Updated: 2021/02/10 16:06:34 by mokhames         ###   ########.fr       */
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
	g_a = ft_split(c, ' ');
	if (len_of_line(g_a) != 3)
		error();
	mlx_get_screen_size(g_mlx.mlx_ptr, &g_winmax, &g_heightmax);
	if (ft_digit2(g_a[1]) < 0 || ft_digit2(g_a[2]) < 0)
		error();
	if (check_digits(g_a[1]) > 0)
	{
		g_map.el.res_x = ft_atoi(g_a[1]);
		if (g_map.el.res_x > g_winmax)
			g_map.el.res_x = g_winmax;
	}
	else
		g_map.el.res_x = g_winmax;
	if (check_digits(g_a[2]) > 0)
	{
		g_map.el.res_y = ft_atoi(g_a[2]);
		if (g_map.el.res_y > g_heightmax)
			g_map.el.res_y = g_heightmax;
	}
	else
		g_map.el.res_y = g_heightmax;
	free_str_1(g_a, len_of_line(g_a));
	return (1);
}

int		check_letters(int i, int j)
{
	if (g_map.el.elem[i][j] == 'R')
		g_map.el.resolution_line = i;
	if (g_map.el.elem[i][j] == 'N')
		g_map.el.north_line = i;
	if (g_map.el.elem[i][j] == 'S')
	{
		if (g_map.el.elem[i][j + 1] == 'O')
			g_map.el.south_line = i;
		else
			g_map.el.sprite_line = i;
	}
	if (g_map.el.elem[i][j] == 'W')
		g_map.el.west_line = i;
	if (g_map.el.elem[i][j] == 'E')
		g_map.el.east_line = i;
	if (g_map.el.elem[i][j] == 'F')
		g_map.el.f_l = i;
	if (g_map.el.elem[i][j] == 'C')
		g_map.el.c_l = i;
	return (1);
}

int		create_elements_lines(void)
{
	int i;
	int j;

	i = 0;
	while (g_map.el.elem[i] != NULL)
	{
		j = 0;
		while (g_map.el.elem[i][j] != '\0')
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
	if (g_map.parser->data[0] == '\0')
		empty_file();
	g_map.el.elem = ft_split(g_map.parser->data, '\n');
	if (create_elements_lines() < 0)
		return (-1);
	if (get_resolution(g_map.el.elem[g_map.el.resolution_line]) < 0)
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
