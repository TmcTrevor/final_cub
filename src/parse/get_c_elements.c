/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_c_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <mokhames@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:06:05 by mokhames          #+#    #+#             */
/*   Updated: 2021/01/24 18:31:57 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/cube3d.h"

int		write_error_ceilling(int i)
{
	if (g_map.el.elem[g_map.el.c_l][i] == '\0' ||
		g_map.el.elem[g_map.el.c_l][i] != ' ')
	{
		write(1, "Error\n", 6);
		write(1, "Wrong ceilling arguments\n", 25);
		exit_all();
	}
	return (-1);
}

int		write_error_end_ceilling(int i)
{
	if (g_map.el.elem[g_map.el.c_l][i] != ' ')
	{
		write(1, "Error\n", 6);
		write(1, "Wrong ceilling arguments\n", 25);
		exit_all();
	}
	return (-1);
}

int		simple_atoi(int i)
{
	while (g_map.el.elem[g_map.el.c_l][i] >= '0' &&
		g_map.el.elem[g_map.el.c_l][i] <= '9')
		g_map.el.c_r = (g_map.el.c_r * 10) +
			g_map.el.elem[g_map.el.c_l][i++] - '0';
	i = i - 1;
	while (g_map.el.elem[g_map.el.c_l][++i] != ',')
		write_error_ceilling(i);
	while (!ft_isdigit(g_map.el.elem[g_map.el.c_l][++i]))
		write_error_ceilling(i);
	return (i);
}

int		get_ceilling_color(void)
{
	int i;

	i = 1;
	while (g_map.el.elem[g_map.el.c_l][i] == ' ')
		i++;
	i = simple_atoi(i);
	while (g_map.el.elem[g_map.el.c_l][i] >= '0' &&
		g_map.el.elem[g_map.el.c_l][i] <= '9')
		g_map.el.c_g = (g_map.el.c_g * 10) +
			g_map.el.elem[g_map.el.c_l][i++] - '0';
	i = i - 1;
	while (g_map.el.elem[g_map.el.c_l][++i] != ',')
		write_error_ceilling(i);
	while (!ft_isdigit(g_map.el.elem[g_map.el.c_l][++i]))
		write_error_ceilling(i);
	while (g_map.el.elem[g_map.el.c_l][i] >= '0' &&
		g_map.el.elem[g_map.el.c_l][i] <= '9')
		g_map.el.c_b = (g_map.el.c_b * 10) +
			g_map.el.elem[g_map.el.c_l][i++] - '0';
	i = i - 1;
	while (g_map.el.elem[g_map.el.c_l][++i] != '\0')
		write_error_end_ceilling(i);
	return (0);
}
