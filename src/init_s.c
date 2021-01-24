/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <mokhames@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 11:29:15 by mokhames          #+#    #+#             */
/*   Updated: 2021/01/24 12:43:12 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers/cube3d.h"

void	init_mlx(void)
{
	mlx.mlx_ptr = NULL;
	mlx.win = NULL;
}

void	init_image(void)
{
	img.img_ptr = NULL;
	img.data = NULL;
	img.bpp = 0;
	img.size_l = 0;
	img.endian = 0;
}

void	init_parser(void)
{
	map.parser->data = NULL;
	map.parser->map_string = NULL;
	map.parser->grid = NULL;
	map.parser->line_nbr = 0;
	map.parser->column_nbr = 0;
	map.parser->pos_x_init = 0;
	map.parser->pos_y_init = 0;
	map.parser->dir = 0;
}

void	reset_ray2(void)
{
	int x;

	x = 0;
	while (x < map.el.nb_rays)
	{
		map.ray[x].len = 0;
		map.ray[x].posx = map.player.posx_p;
		map.ray[x].posy = map.player.posy_p;
		map.ray[x].angle = 0;
		map.ray[x].wallstripheight = 0;
		map.ray[x].ray_down = 0;
		map.ray[x].ray_up = 0;
		map.ray[x].ray_right = 0;
		map.ray[x].ray_left = 0;
		map.ray[x].horzwallhit = 0;
		map.ray[x].verwallhit = 0;
		x++;
	}
}

void	init_struct(void)
{
	init_mlx();
	init_image();
	init_parser();
	map.player.w_dir = 0;
	map.player.w_dir = 0;
	map.player.t_dir = 0;
	map.player.t_dir = 0;
}
