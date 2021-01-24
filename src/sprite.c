/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <mokhames@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 15:51:29 by mokhames          #+#    #+#             */
/*   Updated: 2021/01/24 18:28:31 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers/cube3d.h"

void	sprite_sort(void)
{
	int		i;
	int		j;
	t_spr	*tmp;

	i = 0;
	while (i < g_map.numsprites)
	{
		j = 0;
		while (j < g_map.numsprites - i - 1)
		{
			if (g_map.spr[j]->distance <= g_map.spr[j + 1]->distance)
			{
				tmp = g_map.spr[j];
				g_map.spr[j] = g_map.spr[j + 1];
				g_map.spr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	update_sprite(void)
{
	int i;
	int j;
	int spt_id;

	i = -1;
	spt_id = 0;
	while (++i < g_map.parser->line_nbr)
	{
		j = -1;
		while (++j < g_map.parser->len)
		{
			if (g_map.parser->grid[i][j] == '2')
			{
				g_map.spr[spt_id]->y = (i * g_map.wall_width) +
				g_map.wall_width / 2;
				g_map.spr[spt_id]->x = (j * g_map.wall_width) +
				g_map.wall_width / 2;
				g_map.spr[spt_id]->distance = distance(
					g_map.player.posx_p, g_map.player.posy_p,
					g_map.spr[spt_id]->x, g_map.spr[spt_id]->y);
				spt_id++;
			}
		}
	}
	sprite_sort();
}

void	render_sprite(int k, float x_fs, float y_fs, int sp_size)
{
	int			i;
	int			j;
	int			color;

	i = -1;
	while (++i < sp_size)
	{
		if (x_fs + i < 0 || x_fs + i > g_map.el.res_x)
			continue ;
		if (x_fs + i < g_map.el.res_x)
			if (g_map.ray[(int)x_fs + i].distance < g_map.spr[k]->distance)
				continue ;
		j = -1;
		while (++j < sp_size)
		{
			if (y_fs + j < 0 || y_fs + j > g_map.el.res_y)
				continue ;
			color = g_map.spr[k]->data[g_map.tex1[4].texwidth * (j *
					g_map.tex1[4].texheight / sp_size) +
				(i * g_map.tex1[4].texwidth / sp_size)];
			if (color)
				g_img.data[(int)(y_fs + j) * g_map.el.res_x +
					(int)(x_fs + i)] = color;
		}
	}
}

void	sprite_data(int spt_id)
{
	float		x_offset;
	float		y_offset;
	float		sp_angle;
	float		sp_size;
	float		angle;

	angle = normalize_angle(g_map.player.rotation_angle) + M_PI / 6;
	sp_angle = atan2((g_map.spr[spt_id]->y) - g_map.player.posy_p,
			(g_map.spr[spt_id]->x) - g_map.player.posx_p);
	while (sp_angle - angle > M_PI)
		sp_angle -= 2 * M_PI;
	while (sp_angle - angle < -M_PI)
		sp_angle += 2 * M_PI;
	sp_size = (g_map.el.res_x / g_map.spr[spt_id]->distance) * g_map.wall_width;
	x_offset = (sp_angle - angle) /
		FOV_ANGLE * g_map.el.res_x + (g_map.el.res_x / 2 - sp_size / 2);
	y_offset = ((g_map.el.res_y / 2) - (sp_size / 2));
	render_sprite(spt_id, x_offset, y_offset, sp_size);
}

void	ft_sprite(void)
{
	int id;

	id = -1;
	update_sprite();
	while (++id < g_map.numsprites)
	{
		sprite_data(id);
	}
}
