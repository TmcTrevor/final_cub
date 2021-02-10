/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <mokhames@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 11:33:47 by mokhames          #+#    #+#             */
/*   Updated: 2021/02/10 16:30:32 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers/cube3d.h"

int		key_press(int key)
{
	if (key == MLXK_W || key == MLXK_UP)
		g_map.player.w_dir = 1;
	if (key == MLXK_S || key == MLXK_DOWN)
		g_map.player.w_dir = -1;
	if (key == MLXK_RIGHT)
		g_map.player.t_dir = 1;
	if (key == MLXK_LEFT)
		g_map.player.t_dir = -1;
	if (key == MLXK_A)
		g_map.player.rl_dir = -1;
	if (key == MLXK_D)
		g_map.player.rl_dir = 1;
	return (0);
}

void	ft_rl_dir(int x, int y)
{
	float	move;
	float	m;
	float	n;
	int		a;
	int		b;

	move = g_map.player.mov_speed * g_map.player.rl_dir;
	a = g_map.player.posx_p;
	b = g_map.player.posy_p;
	m = (cos(g_map.player.rotation_angle + M_PI / 6 + (M_PI / 2)) * move);
	n = (sin(g_map.player.rotation_angle + M_PI / 6 + (M_PI / 2)) * move);
	x = g_map.player.posx_p + n * 0.2;
	y = g_map.player.posy_p - m * 0.2;
	if (!is_wall2(x, b, '1'))
		g_map.player.posx_p += m * 0.2;
	if (!is_wall2(a, y, '1'))
		g_map.player.posy_p += n * 0.2;
}

int		after_press(int key)
{
	if (key == MLXK_W || key == MLXK_UP)
		g_map.player.w_dir = 0;
	if (key == MLXK_S || key == MLXK_DOWN)
		g_map.player.w_dir = 0;
	if (key == MLXK_RIGHT)
		g_map.player.t_dir = 0;
	if (key == MLXK_LEFT)
		g_map.player.t_dir = 0;
	if (key == MLXK_A)
		g_map.player.rl_dir = 0;
	if (key == MLXK_D)
		g_map.player.rl_dir = 0;
	return (0);
}

void	fking_move(void)
{
	int		x;
	int		y;
	float	m;
	float	n;

	g_map.player.rotation_angle += g_map.player.t_dir *
		g_map.player.rotation_speed;
	g_map.util.move = g_map.player.w_dir * g_map.player.mov_speed;
	m = (cos(g_map.player.rotation_angle + M_PI / 6) * g_map.util.move);
	n = (sin(g_map.player.rotation_angle + M_PI / 6) * g_map.util.move);
	g_map.util.a = g_map.player.posx_p;
	g_map.util.b = g_map.player.posy_p;
	if (g_map.player.rl_dir)
		ft_rl_dir(x, y);
	else
	{
		x = (g_map.player.posx_p + m * 0.2);
		y = (g_map.player.posy_p + n * 0.2);
	}
	if (!is_wall2(x, g_map.util.b, '1'))
		g_map.player.posx_p += m * 0.2;
	if (!is_wall2(g_map.util.a, y, '1'))
		g_map.player.posy_p += n * 0.2;
}

int		ft_key(int key)
{
	if (key == MLXK_ESC || key == MLXK_X)
		exit_all();
	key_press(key);
	fking_move();
	after_press(key);
	mlx_destroy_image(g_mlx.mlx_ptr, g_img.img_ptr);
	draw_map();
	return (0);
}
