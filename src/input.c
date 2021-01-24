/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <mokhames@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 11:33:47 by mokhames          #+#    #+#             */
/*   Updated: 2021/01/24 12:51:56 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers/cube3d.h"

int		key_press(int key)
{
	if (key == MLXK_W || key == MLXK_UP)
		map.player.w_dir = 1;
	if (key == MLXK_S || key == MLXK_DOWN)
		map.player.w_dir = -1;
	if (key == MLXK_RIGHT)
		map.player.t_dir = 1;
	if (key == MLXK_LEFT)
		map.player.t_dir = -1;
	if (key == MLXK_A)
		map.player.rl_dir = -1;
	if (key == MLXK_D)
		map.player.rl_dir = 1;
	return (0);
}

void	ft_rl_dir(int *x, int *y)
{
	float move;
	float m;
	float n;
	

	move = map.player.mov_speed * map.player.rl_dir;
	m = (cos(map.player.rotation_angle + M_PI / 6) * move);
	n = (sin(map.player.rotation_angle + M_PI / 6) * move);
	*x = map.player.posx_p + n * 0.2;
	*y = map.player.posy_p - m * 0.2; 
}

int		after_press(int key)
{
	if (key == MLXK_W || key == MLXK_UP)
		map.player.w_dir = 0;
	if (key == MLXK_S || key == MLXK_DOWN)
		map.player.w_dir = 0;
	if (key == MLXK_RIGHT)
		map.player.t_dir = 0;
	if (key == MLXK_LEFT)
		map.player.t_dir = 0;
	if (key == MLXK_A)
		map.player.rl_dir = 0;
	if (key == MLXK_D)
		map.player.rl_dir = 0;
	return (0);
}

int		fking_move(void)
{
	float	move;
	int		x;
	int		y;
	int		a;
	int		b;
	float	m;
	float	n;

	map.player.rotation_angle += map.player.t_dir * map.player.rotation_speed;
	move = map.player.w_dir * map.player.mov_speed;
	m = (cos(map.player.rotation_angle + M_PI / 6 ) * move);
	n = (sin(map.player.rotation_angle + M_PI / 6) * move);
	a = map.player.posx_p;
	b = map.player.posy_p;
	if (map.player.rl_dir)
	{
			ft_rl_dir(&x,&y);
	}
	else
	{	
		x = (map.player.posx_p + m * 0.2);
		y = (map.player.posy_p + n  * 0.2);
	}
	if (!is_wall2(x, b, '1') && !is_wall2(x , b, '2'))
		map.player.posx_p += m  * 0.2;
	if (!is_wall2(a, y, '1') && !is_wall2(a, y , '2')) 
		map.player.posy_p += n * 0.2;
	return 0;
}

int		ft_key(int key)
{
	
	if (key == MLXK_ESC || key == MLXK_X)
		exit_all();
	key_press(key);
	fking_move();
	after_press(key);
	mlx_destroy_image(mlx.mlx_ptr,img.img_ptr);
	draw_map();
	return 0;
}
