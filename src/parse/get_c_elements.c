/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_c_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <mokhames@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:06:05 by mokhames          #+#    #+#             */
/*   Updated: 2021/01/14 16:37:35 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/cube3d.h"

int		write_error_ceilling(int i)
{
	if (map.el.elem[map.el.c_l][i] == '\0' ||
		map.el.elem[map.el.c_l][i] != ' ')
	{
		write(1, "Error\n", 6);
		write(1, "Wrong ceilling arguments\n", 25);
		exit_all();
	}
	return (-1);
}

int		write_error_end_ceilling(int i)
{
	if (map.el.elem[map.el.c_l][i] != ' ')
	{
		write(1, "Error\n", 6);
		write(1, "Wrong ceilling arguments\n", 25);
		exit_all();
	}
	return (-1);
}

int		simple_atoi(int i)
{
	while (map.el.elem[map.el.c_l][i] >= '0' &&
		map.el.elem[map.el.c_l][i] <= '9')
		map.el.c_r = (map.el.c_r * 10) + map.el.elem[map.el.c_l][i++] - '0';
	i = i - 1;
	while (map.el.elem[map.el.c_l][++i] != ',')
		write_error_ceilling(i);
	while (!ft_isdigit(map.el.elem[map.el.c_l][++i]))
		write_error_ceilling(i);
	return (i);
}

int		get_ceilling_color(void)
{
	int i;

	i = 1;
	while (map.el.elem[map.el.c_l][i] == ' ')
		i++;
	i = simple_atoi(i);
	while (map.el.elem[map.el.c_l][i] >= '0' &&
		map.el.elem[map.el.c_l][i] <= '9')
		map.el.c_g = (map.el.c_g * 10) + map.el.elem[map.el.c_l][i++] - '0';
	i = i - 1;
	while (map.el.elem[map.el.c_l][++i] != ',')
		write_error_ceilling(i);
	while (!ft_isdigit(map.el.elem[map.el.c_l][++i]))
		write_error_ceilling(i);
	while (map.el.elem[map.el.c_l][i] >= '0' &&
		map.el.elem[map.el.c_l][i] <= '9')
		map.el.c_b = (map.el.c_b * 10) + map.el.elem[map.el.c_l][i++] - '0';
	i = i - 1;
	while (map.el.elem[map.el.c_l][++i] != '\0')
		write_error_end_ceilling(i);
	return (0);
}
