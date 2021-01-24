/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <mokhames@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:55:49 by mokhames          #+#    #+#             */
/*   Updated: 2021/01/24 18:21:25 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers/cube3d.h"

void	ray_horz_collision(int x)
{
	while (g_util.nextx >= 0 && g_util.nextx <= g_map.el.res_x &&
		g_util.nexty >= 0 && g_util.nexty <= g_map.el.res_y)
	{
		g_util.xtocheck = g_util.nextx;
		g_util.ytocheck = g_util.nexty + (g_map.ray[x].ray_up ? -1 : 0);
		if (is_wall2(g_util.xtocheck, g_util.ytocheck, '1'))
		{
			g_map.ray[x].horzwallhit = 1;
			g_map.ray[x].h_wallhitx = g_util.nextx;
			g_map.ray[x].h_wallhity = g_util.nexty;
			break ;
		}
		else
		{
			g_util.nextx += g_util.xstep;
			g_util.nexty += g_util.ystep;
		}
	}
}

void	ray_ver_collision(int x)
{
	while (g_util.nextx >= 0 && g_util.nextx <= g_map.el.res_x &&
		g_util.nexty >= 0 && g_util.nexty <= g_map.el.res_y)
	{
		g_util.xtocheck = g_util.nextx + (g_map.ray[x].ray_left ? -1 : 0);
		g_util.ytocheck = g_util.nexty;
		if (is_wall2(g_util.xtocheck, g_util.ytocheck, '1'))
		{
			g_map.ray[x].verwallhit = 1;
			g_map.ray[x].v_wallhitx = g_util.nextx;
			g_map.ray[x].v_wallhity = g_util.nexty;
			break ;
		}
		else
		{
			g_util.nextx += g_util.xstep;
			g_util.nexty += g_util.ystep;
		}
	}
}

void	cast_horizontal_inter_ray(float angle, int x)
{
	g_util.yintercept = floor(g_map.player.posy_p /
		g_map.wall_height) * g_map.wall_height;
	g_util.yintercept += (g_map.ray[x].ray_down) ? g_map.wall_height : 0;
	g_util.xintercept = g_map.player.posx_p +
		(g_util.yintercept - g_map.player.posy_p) / tan(angle);
	g_util.ystep = g_map.wall_height;
	g_util.ystep *= g_map.ray[x].ray_up ? -1 : 1;
	g_util.xstep = g_util.ystep / tan(angle);
	g_util.xstep *= (g_map.ray[x].ray_left && g_util.xstep > 0) ? -1 : 1;
	g_util.xstep *= (g_map.ray[x].ray_right && g_util.xstep < 0) ? -1 : 1;
	g_util.nextx = g_util.xintercept;
	g_util.nexty = g_util.yintercept;
	ray_horz_collision(x);
}

void	cast_vertical_inter_ray(float angle, int x)
{
	g_util.xintercept = floor(g_map.player.posx_p / g_map.wall_width)
		* g_map.wall_width;
	g_util.xintercept += (g_map.ray[x].ray_right) ? g_map.wall_width : 0;
	g_util.yintercept = g_map.player.posy_p +
		(g_util.xintercept - g_map.player.posx_p) * tan(angle);
	g_util.xstep = g_map.wall_width;
	g_util.xstep *= g_map.ray[x].ray_left ? -1 : 1;
	g_util.ystep = g_util.xstep * tan(angle);
	g_util.ystep *= (g_map.ray[x].ray_up && g_util.ystep > 0) ? -1 : 1;
	g_util.ystep *= (g_map.ray[x].ray_down && g_util.ystep < 0) ? -1 : 1;
	g_util.nextx = g_util.xintercept;
	g_util.nexty = g_util.yintercept;
	ray_ver_collision(x);
}

void	check_distance(int x, float angle)
{
	float p1;
	float p2;

	if (g_map.ray[x].horzwallhit)
		p1 = distance(g_map.player.posx_p, g_map.player.posy_p,
			g_map.ray[x].h_wallhitx, g_map.ray[x].h_wallhity);
	else
		p1 = INT_MAX;
	if (g_map.ray[x].verwallhit)
		p2 = distance(g_map.player.posx_p, g_map.player.posy_p,
			g_map.ray[x].v_wallhitx, g_map.ray[x].v_wallhity);
	else
		p2 = INT_MAX;
	g_map.ray[x].distance = (p1 < p2) ? p1 : p2;
	g_map.ray[x].wallhitx = (p1 < p2) ? g_map.ray[x].h_wallhitx :
		g_map.ray[x].v_wallhitx;
	g_map.ray[x].wallhity = (p1 < p2) ? g_map.ray[x].h_wallhity :
		g_map.ray[x].v_wallhity;
	g_map.ray[x].wasvertical = (p1 < p2) ? 0 : 1;
}
