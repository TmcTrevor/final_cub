/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <mokhames@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:04:04 by mokhames          #+#    #+#             */
/*   Updated: 2021/01/24 18:29:10 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers/cube3d.h"

int		create_images2(void)
{
	if (!(g_map.tex1[3].color = mlx_xpm_file_to_image(g_mlx.mlx_ptr,
		g_map.el.e_path,
		&g_map.tex1[3].texwidth, &g_map.tex1[3].texheight)))
	{
		write(1, "Error\n", 6);
		write(1, "e wrong path texture", 20);
		return (exit_all());
	}
	return (1);
}

int		create_images1(void)
{
	if (!(g_map.tex1[0].color = mlx_xpm_file_to_image(g_mlx.mlx_ptr,
		g_map.el.n_path,
		&g_map.tex1[0].texwidth, &g_map.tex1[0].texheight)))
	{
		write(1, "Error\n", 6);
		write(1, "n wrong path texture\n", 20);
		return (exit_all());
	}
	if (!(g_map.tex1[1].color = mlx_xpm_file_to_image(g_mlx.mlx_ptr,
		g_map.el.s_path,
		&g_map.tex1[1].texwidth, &g_map.tex1[1].texheight)))
	{
		write(1, "Error\n", 6);
		write(1, "s wrong path texture", 20);
		return (exit_all());
	}
	if (!(g_map.tex1[2].color = mlx_xpm_file_to_image(g_mlx.mlx_ptr,
		g_map.el.w_path,
		&g_map.tex1[2].texwidth, &g_map.tex1[2].texheight)))
	{
		write(1, "Error\n", 6);
		write(1, "w wrong path texture", 20);
		return (exit_all());
	}
	return (1);
}

int		initialize_texture(void)
{
	create_images1();
	create_images2();
	g_map.tex1[0].color = (int*)mlx_get_data_addr(g_map.tex1[0].color,
		&g_img.bpp, &g_img.size_l, &g_img.bpp);
	g_map.tex1[1].color = (int*)mlx_get_data_addr(g_map.tex1[1].color,
		&g_img.bpp, &g_img.size_l, &g_img.bpp);
	g_map.tex1[2].color = (int*)mlx_get_data_addr(g_map.tex1[2].color,
		&g_img.bpp, &g_img.size_l, &g_img.bpp);
	g_map.tex1[3].color = (int*)mlx_get_data_addr(g_map.tex1[3].color,
		&g_img.bpp, &g_img.size_l, &g_img.bpp);
	return (1);
}
