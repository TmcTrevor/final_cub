/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <mokhames@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:30:38 by mokhames          #+#    #+#             */
/*   Updated: 2021/01/24 18:30:55 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers/cube3d.h"

float	distance(float x, float y, float x1, float y1)
{
	return (sqrt(pow(x1 - x, 2) + pow(y1 - y, 2)));
}

float	normalize_angle(float angle)
{
	angle = fmod(angle, (2 * M_PI));
	if (angle < 0)
		angle += (2 * M_PI);
	return (angle);
}

void	reset_all(void)
{
	int x;

	x = 0;
	while (x <= g_map.el.nb_rays - 2)
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
		g_map.ray[x].wallhitx = 0;
		g_map.ray[x].wallhity = 0;
		g_map.ray[x].h_wallhitx = 0;
		g_map.ray[x].h_wallhity = 0;
		g_map.ray[x].v_wallhitx = 0;
		g_map.ray[x].v_wallhity = 0;
		g_map.ray[x].wasvertical = 0;
		x++;
	}
}

void	draw_fov(void)
{
	double	angle;
	float	step;
	int		x;

	x = 0;
	step = M_PI / 180;
	angle = 0;
	angle = g_map.player.rotation_angle;
	reset_all();
	while (x <= g_map.el.nb_rays - 2)
	{
		angle = normalize_angle(angle);
		check_angle(angle, x);
		cast_horizontal_inter_ray(angle, x);
		cast_vertical_inter_ray(angle, x);
		check_distance(x, angle);
		g_map.ray[x].angle = angle;
		angle += (M_PI / 3) / g_map.el.nb_rays;
		x++;
	}
}

int		draw_map(void)
{
	int		i;
	int		j;
	float	x;
	float	y;

	i = 0;
	x = 0;
	y = 0;
	j = 0;
	g_img.img_ptr = mlx_new_image(g_mlx.mlx_ptr,
		g_map.el.res_x, g_map.el.res_y);
	g_img.data = (int *)mlx_get_data_addr(g_img.img_ptr, &g_img.bpp,
		&g_img.size_l, &g_img.endian);
	draw_fov();
	project_wall();
	ft_sprite();
	mlx_put_image_to_window(g_mlx.mlx_ptr, g_mlx.win, g_img.img_ptr, 0, 0);
	return (1);
}
