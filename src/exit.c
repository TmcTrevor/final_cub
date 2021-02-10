/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <mokhames@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 11:26:12 by mokhames          #+#    #+#             */
/*   Updated: 2021/02/10 12:12:13 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers/cube3d.h"

void	free_paths(void)
{
	if (g_map.el.n_path)
	{
		free(g_map.el.n_path);
		g_map.el.n_path = 0;
	}
	if (g_map.el.s_path)
	{
		free(g_map.el.s_path);
		g_map.el.s_path = 0;
	}
	if (g_map.el.e_path)
	{
		free(g_map.el.e_path);
		g_map.el.e_path = 0;
	}
	if (g_map.el.w_path)
	{
		free(g_map.el.w_path);
		g_map.el.w_path = 0;
	}
}

void	free_elem(void)
{
	int i;

	i = -1;
	if (g_map.el.elem)
	{
		while (++i < 8)
		{
			free(g_map.el.elem[i]);
			g_map.el.elem[i] = 0;
		}
		free(g_map.el.elem);
		g_map.el.elem = 0;
	}
	free_paths();
	if (g_map.el.spr_path)
	{
		free(g_map.el.spr_path);
		g_map.el.spr_path = 0;
	}
}

void	free_win(void)
{
	if (g_mlx.mlx_ptr && g_mlx.win)
		mlx_destroy_window(g_mlx.mlx_ptr, g_mlx.win);
}

void	free_spr(void)
{
	int i;

	i = 0;
	if (g_map.spr)
	{
		free(g_map.spr);
		g_map.spr = 0;
	}
}

int		exit_all(void)
{
	free_win();
	free_map();
	free_parser();
	free_elem();
	if (g_map.spr)
		free_spr();
	if (g_map.ray)
		free_ray();
	exit(0);
	return (-1);
}
