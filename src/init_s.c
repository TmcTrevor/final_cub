/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <mokhames@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 11:29:15 by mokhames          #+#    #+#             */
/*   Updated: 2021/01/24 18:24:52 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers/cube3d.h"

void	init_mlx(void)
{
	g_mlx.mlx_ptr = NULL;
	g_mlx.win = NULL;
}

void	init_image(void)
{
	g_img.img_ptr = NULL;
	g_img.data = NULL;
	g_img.bpp = 0;
	g_img.size_l = 0;
	g_img.endian = 0;
}

void	init_parser(void)
{
	g_map.parser->data = NULL;
	g_map.parser->map_string = NULL;
	g_map.parser->grid = NULL;
	g_map.parser->line_nbr = 0;
	g_map.parser->column_nbr = 0;
	g_map.parser->pos_x_init = 0;
	g_map.parser->pos_y_init = 0;
	g_map.parser->dir = 0;
}

void	reset_ray2(void)
{
	int x;

	x = 0;
	while (x < g_map.el.nb_rays)
	{
		g_map.ray[x].len = 0;
		g_map.ray[x].posx = g_map.player.posx_p;
		g_map.ray[x].posy = g_map.player.posy_p;
		g_map.ray[x].angle = 0;
		g_map.ray[x].wallstripheight = 0;
		g_map.ray[x].ray_down = 0;
		g_map.ray[x].ray_up = 0;
		g_map.ray[x].ray_right = 0;
		g_map.ray[x].ray_left = 0;
		g_map.ray[x].horzwallhit = 0;
		g_map.ray[x].verwallhit = 0;
		x++;
	}
}

void	init_struct(void)
{
	init_mlx();
	init_image();
	init_parser();
	g_map.player.w_dir = 0;
	g_map.player.w_dir = 0;
	g_map.player.t_dir = 0;
	g_map.player.t_dir = 0;
}
