/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <mokhames@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 15:35:41 by mokhames          #+#    #+#             */
/*   Updated: 2021/01/25 07:43:59 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers/cube3d.h"

void	render_ceiling(float top, int x)
{
	int e;

	e = -1;
	while (++e < top)
		g_img.data[e * g_map.el.res_x + x] = g_map.el.c_color_hex;
}

void	render_floor(float bot, int i)
{
	while (bot < g_map.el.res_y)
	{
		g_img.data[(int)bot * g_map.el.res_x + i] = g_map.el.f_color_hex;
		bot++;
	}
}

void	render_wall(float bot, float top, int x, int t)
{
	float	texx;
	float	texy;
	int		color;
	int		distancefromtop;
	float	w_height;

	w_height = g_util.wallstripheight;
	texx = g_map.ray[x].wasvertical ? g_map.ray[x].wallhity / g_map.wall_width :
		g_map.ray[x].wallhitx / g_map.wall_width;
	texx -= (int)texx;
	texx *= g_map.tex1[t].texwidth;
	while (top < bot)
	{
		distancefromtop = top + (w_height / 2) - (g_map.el.res_y / 2);
		texy = distancefromtop * (float)(g_map.tex1[t].texheight / w_height);
		color = g_map.tex1[t].color[(int)texy *
			g_map.tex1[t].texwidth + (int)texx];
		g_img.data[(int)top * g_map.el.res_x + x] = color;
		top++;
	}
}

int		set_t(int t, int x)
{
	if (g_map.ray[x].ray_down && !g_map.ray[x].wasvertical)
		t = 0;
	else if (g_map.ray[x].ray_right && g_map.ray[x].wasvertical)
		t = 2;
	else if (g_map.ray[x].ray_left && g_map.ray[x].wasvertical)
		t = 3;
	else if (g_map.ray[x].ray_up && !g_map.ray[x].wasvertical)
		t = 1;
	return (t);
}

void	project_wall(void)
{
	float	walltoppixel;
	float	wallbottompixel;
	float	len;
	int		x;
	int		t;

	x = 0;
	t = 1;
	while (x <= g_map.el.nb_rays - 2)
	{
		len = g_map.ray[x].distance * cos(normalize_angle(g_map.ray[x].angle -
			g_map.player.rotation_angle - (M_PI / 6)));
		g_util.wallstripheight = floor((g_map.wall_height / len) *
			g_map.distanceprojplane);
		walltoppixel = (g_map.el.res_y / 2) - (g_util.wallstripheight / 2);
		walltoppixel = (walltoppixel < 0) ? 0 : walltoppixel;
		wallbottompixel = (g_map.el.res_y / 2) + (g_util.wallstripheight / 2);
		wallbottompixel = (wallbottompixel > g_map.el.res_y) ?
			g_map.el.res_y : wallbottompixel;
		render_ceiling(walltoppixel, x);
		t = set_t(t, x);
		render_wall(wallbottompixel, walltoppixel, x, t);
		render_floor(wallbottompixel, x);
		x++;
	}
}
