/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hefen.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <mokhames@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 09:36:35 by mokhames          #+#    #+#             */
/*   Updated: 2021/02/10 16:46:10 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/cube3d.h"

void	free_str_1(char **str, int o)
{
	if (str)
	{
		while (o >= 0)
		{
			free(str[o]);
			str[o] = 0;
			o--;
		}
		free(str);
		str = 0;
	}
}

void	empty_file(void)
{
	write(1, "Empty file\n", 11);
	exit_all();
}

void	color_range_error(void)
{
	write(1, "RGB COLOR NOT WELL SET\n", 24);
	exit_all();
}

int		check_color_range(void)
{
	if (g_map.el.c_r < 0 || g_map.el.c_r > 255)
		color_range_error();
	if (g_map.el.c_g < 0 || g_map.el.c_g > 255)
		color_range_error();
	if (g_map.el.c_b < 0 || g_map.el.c_b > 255)
		color_range_error();
	if (g_map.el.f_r < 0 || g_map.el.f_r > 255)
		color_range_error();
	if (g_map.el.f_g < 0 || g_map.el.f_g > 255)
		color_range_error();
	if (g_map.el.f_b < 0 || g_map.el.f_b > 255)
		color_range_error();
	return (1);
}
