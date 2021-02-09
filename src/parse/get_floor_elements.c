/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_floor_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <mokhames@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:58:15 by mokhames          #+#    #+#             */
/*   Updated: 2021/02/09 17:19:02 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/cube3d.h"

int				write_error_floor(int i)
{
	if (g_map.el.elem[g_map.el.f_l][i] == '\0' ||
		g_map.el.elem[g_map.el.f_l][i] != ' ')
	{
		write(1, "Error\n", 6);
		write(1, "Wrong floor arguments\n", 21);
		exit_all();
	}
	return (-1);
}

int				write_error_end_floor(int i)
{
	if (g_map.el.elem[g_map.el.f_l][i] != ' ')
	{
		write(1, "Error\n", 6);
		write(1, "Wrong floor arguments\n", 21);
		exit_all();
	}
	return (-1);
}

static int		simple_atoi(int i)
{
	while (g_map.el.elem[g_map.el.f_l][i] >= '0' &&
		g_map.el.elem[g_map.el.f_l][i] <= '9')
		g_map.el.f_r = (g_map.el.f_r * 10) +
			g_map.el.elem[g_map.el.f_l][i++] - '0';
	i = i - 1;
	while (g_map.el.elem[g_map.el.f_l][++i] != ',')
		write_error_floor(i);
	while (!ft_isdigit(g_map.el.elem[g_map.el.f_l][++i]))
		write_error_floor(i);
	return (i);
}

int				get_floor_color(void)
{
	int i;

	i = 1;
	while (g_map.el.elem[g_map.el.f_l][i] == 32)
		i++;
	i = simple_atoi(i);
	while (g_map.el.elem[g_map.el.f_l][i] >= '0' &&
		g_map.el.elem[g_map.el.f_l][i] <= '9')
		g_map.el.f_g = (g_map.el.f_g * 10) +
			g_map.el.elem[g_map.el.f_l][i++] - '0';
	i = i - 1;
	while (g_map.el.elem[g_map.el.f_l][++i] != ',')
		write_error_floor(i);
	while (!ft_isdigit(g_map.el.elem[g_map.el.f_l][++i]))
		write_error_floor(i);
	while (g_map.el.elem[g_map.el.f_l][i] >= '0' &&
		g_map.el.elem[g_map.el.f_l][i] <= '9')
		g_map.el.f_b = (g_map.el.f_b * 10) +
			g_map.el.elem[g_map.el.f_l][i++] - '0';
	i = i - 1;
	while (g_map.el.elem[g_map.el.f_l][++i] != '\0')
		write_error_end_floor(i);
	return (0);
}
