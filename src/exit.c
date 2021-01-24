/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <mokhames@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 11:26:12 by mokhames          #+#    #+#             */
/*   Updated: 2021/01/24 11:26:56 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers/cube3d.h"

void	free_paths(void)
{
	if (map.el.n_path)
	{
		free(map.el.n_path);
		map.el.n_path = 0;
	}
	if (map.el.s_path)
	{
		free(map.el.s_path);
		map.el.s_path = 0;
	}
	if (map.el.e_path)
	{
		free(map.el.e_path);
		map.el.e_path = 0;
	}
	if (map.el.w_path)
	{
		free(map.el.w_path);
		map.el.w_path = 0;
	}
}

void	free_elem(void)
{
	int i;

	i = -1;
	if (map.el.elem)
	{
		while (++i < 8)
		{
			free(map.el.elem[i]);
			map.el.elem[i] = 0;
		}
		free(map.el.elem);
		map.el.elem = 0;
	}
	free_paths();
	if (map.el.spr_path)
	{
		free(map.el.spr_path);
		map.el.spr_path = 0;
	}
}

void	free_win(void)
{
	if (mlx.mlx_ptr && mlx.win)
		mlx_destroy_window(mlx.mlx_ptr, mlx.win);
}

void	free_spr(void)
{
	int i;

	i = 0;
	while (i < map.numsprites)
	{
		free(map.spr[i]->ptr);
		map.spr[i]->ptr = 0;
		free(map.spr[i]->data);
		map.spr[i]->data = 0;
		free(map.spr[i]);
		map.spr[i] = 0;
		i++;
	}
	free(map.spr);
	map.spr = 0;
}

int		exit_all(void)
{
	free_win();
	free_map();
	free_parser();
	free_elem();
	free_spr();
	free_ray();
	exit(0);
	return (-1);
}
