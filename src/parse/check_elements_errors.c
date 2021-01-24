/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements_errors.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <mokhames@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:00:36 by mokhames          #+#    #+#             */
/*   Updated: 2021/01/15 18:34:57 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/cube3d.h"

int		check_west_and_east(void)
{
	if (map.el.elem[map.el.west_line][0] != 'W' ||
		map.el.elem[map.el.west_line][1] != 'E')
	{
		write(1, "Error\n", 6);
		write(1, "Wrong west texture path\n", 24);
		return (exit_all());
	}
	if (map.el.elem[map.el.east_line][0] != 'E' ||
		map.el.elem[map.el.east_line][1] != 'A')
	{
		write(1, "Error\n", 6);
		write(1, "Wrong east texture path\n", 24);
		return (exit_all());
	}
	return (1);
}

int		check_north_and_south(void)
{
	if (map.el.elem[map.el.north_line][0] != 'N' ||
		map.el.elem[map.el.north_line][1] != 'O')
	{
		write(1, "Error\n", 6);
		write(1, "Wrong north texture path\n", 25);
		return (exit_all());
	}
	if (map.el.elem[map.el.south_line][0] != 'S' ||
		map.el.elem[map.el.south_line][1] != 'O')
	{
		write(1, "Error\n", 6);
		write(1, "Wrong south texture path\n", 25);
		return (exit_all());
	}
	return (1);
}

int		check_path(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
		{
			write(1, "Error\n", 6);
			write(1, "Wrong texture path\n", 19);
			return (-1);
		}
		i++;
	}
	return (1);
}

int		check_resolution(void)
{
	if (map.el.elem[map.el.resolution_line][0] != 'R')
	{
		write(1, "Error\n", 6);
		write(1, "--> Wrong resolution letter\n", 28);
		return (exit_all());
	}
	if (map.el.elem[map.el.resolution_line][1] != ' ' &&
		!ft_isdigit(map.el.elem[map.el.resolution_line][1]))
	{
		write(1, "Error\n", 6);
		write(1, "--> Wrong resolution details\n", 28);
		return (exit_all());
	}
	if (map.el.res_x > 2560)
		map.el.res_x = 2560;
	if (map.el.res_y > 1440)
		map.el.res_y = 1440;
	return (1);
}

int		check_elements_errors(void)
{
	if (check_north_and_south() < 0)
		return (-1);
	if (check_west_and_east() < 0)
		return (-1);
	if (check_path(map.el.n_path) < 0)
		return (-1);
	if (check_path(map.el.s_path) < 0)
		return (-1);
	if (check_path(map.el.w_path) < 0)
		return (-1);
	if (check_path(map.el.e_path) < 0)
		return (-1);
	if (check_path(map.el.spr_path) < 0)
		return (-1);
	if (check_resolution() < 0)
		return (-1);
	return (1);
}
