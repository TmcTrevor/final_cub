/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <mokhames@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:02:57 by mokhames          #+#    #+#             */
/*   Updated: 2021/01/24 18:20:02 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/cube3d.h"

int		transform_to_hex(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	create_hex_color(void)
{
	g_map.el.c_color_hex = transform_to_hex(g_map.el.c_r,
		g_map.el.c_g, g_map.el.c_b);
	g_map.el.f_color_hex = transform_to_hex(g_map.el.f_r,
		g_map.el.f_g, g_map.el.f_b);
}
