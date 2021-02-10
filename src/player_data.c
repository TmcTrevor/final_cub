/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <mokhames@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:51:28 by mokhames          #+#    #+#             */
/*   Updated: 2021/02/10 16:35:42 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers/cube3d.h"

void	data_e_w(void)
{
	if (g_map.parser->dir == 'E')
	{
		g_map.player.rotation_angle = 2 * M_PI / 3 + M_PI / 6;
		g_map.player.planex = 0;
		g_map.player.planey = 0.66;
		g_map.player.dirx = 1;
		g_map.player.diry = 0;
	}
	if (g_map.parser->dir == 'W')
	{
		g_map.player.rotation_angle = -M_PI / 6;
		g_map.player.planex = 0;
		g_map.player.planey = -0.66;
		g_map.player.dirx = -1;
		g_map.player.diry = 0;
	}
}

void	data_n_s(void)
{
	if (g_map.parser->dir == 'S')
	{
		g_map.player.rotation_angle = M_PI / 3;
		g_map.player.planex = -0.66;
		g_map.player.planey = 0;
		g_map.player.dirx = 0;
		g_map.player.diry = 1;
	}
	if (g_map.parser->dir == 'N')
	{
		g_map.player.rotation_angle = -2 * M_PI / 3;
		g_map.player.planex = 0.66;
		g_map.player.planey = 0;
		g_map.player.dirx = 0;
		g_map.player.diry = -1;
	}
}

int		player_data(void)
{
	data_e_w();
	data_n_s();
	g_map.wall_width = 64 * 0.2;
	g_map.wall_height = 64 * 0.2;
	g_map.player.posx = g_map.parser->pos_x_init;
	g_map.player.posy = g_map.parser->pos_y_init;
	g_map.player.posx_p = g_map.player.posx * g_map.wall_width;
	g_map.player.posy_p = g_map.player.posy * g_map.wall_height;
	g_map.player.posx_p += g_map.wall_width / 2;
	g_map.player.posy_p += g_map.wall_height / 2;
	g_map.player.mov_speed = 30;
	g_map.player.rotation_speed = 40 * (M_PI / 180);
	g_map.el.wsw = 1;
	g_map.el.nb_rays = g_map.el.res_x / g_map.el.wsw;
	g_map.distanceprojplane = (g_map.el.res_x / 2) / tan(FOV_ANGLE / 2);
	init_ray();
	init_spr();
	return (1);
}
