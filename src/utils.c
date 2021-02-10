/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <mokhames@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 15:17:56 by mokhames          #+#    #+#             */
/*   Updated: 2021/02/10 11:33:30 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers/cube3d.h"

void	init_ray(void)
{
	int x;

	x = 0;
	g_map.ray = (t_ray *)malloc((g_map.el.nb_rays * sizeof(t_ray)));
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
		g_map.ray[x].issprite = 0;
		x++;
	}
}

void	reset_ray(int x)
{
	g_map.ray[x].ray_down = 0;
	g_map.ray[x].ray_up = 0;
	g_map.ray[x].ray_right = 0;
	g_map.ray[x].ray_left = 0;
}

void	init_spr(void)
{
	int i;
	int us;

	i = 0;
	if (!(g_map.spr = malloc(sizeof(t_spr) * (g_map.numsprites + 1))))
		return ;
	while (i < g_map.numsprites)
	{
		if (!(g_map.spr[i] = malloc(sizeof(t_spr))))
			return ;
		if (!(g_map.spr[i]->ptr = mlx_xpm_file_to_image(
			g_mlx.mlx_ptr, g_map.el.spr_path,
			&g_map.tex1[4].texwidth, &g_map.tex1[4].texheight)))
		{
			write(1, "Error\n", 6);
			write(1, "s wrong path texture\n", 20);
			exit_all();
		}
		g_map.spr[i]->data = (int *)mlx_get_data_addr(g_map.spr[i]->ptr,
													&us,
													&us,
													&us);
		i++;
	}
	g_map.spr[i] = NULL;
}

void	check_angle(float angle, int x)
{
	if (angle > 0 && angle < M_PI)
		g_map.ray[x].ray_down = 1;
	else
		g_map.ray[x].ray_up = 1;
	if (angle < M_PI / 2 || angle > ((3 * M_PI) / 2))
		g_map.ray[x].ray_right = 1;
	else
		g_map.ray[x].ray_left = 1;
}

int		is_wall2(float a, float b, char c)
{
	int x;
	int y;

	x = (int)(a / g_map.wall_width);
	y = (int)(b / g_map.wall_height);
	if (x < 0 || y < 0 || x > g_map.parser->len - 1 ||
		y > g_map.parser->line_nbr - 1)
		return (1);
	if (g_map.parser->grid[y][x] == c)
		return (1);
	return (0);
}
