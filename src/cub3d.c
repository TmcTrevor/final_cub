/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <mokhames@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 14:32:28 by mokhames          #+#    #+#             */
/*   Updated: 2021/01/24 18:31:16 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers/cube3d.h"

int		start_game(void)
{
	init_struct();
	if (parse_main() < 0)
		return (-1);
	if (!(g_mlx.mlx_ptr = mlx_init()))
		return (-1);
	player_data();
	g_mlx.win = mlx_new_window(g_mlx.mlx_ptr, g_map.el.res_x,
		g_map.el.res_y, "TreVor");
	g_img.img_ptr = mlx_new_image(g_mlx.mlx_ptr, g_map.el.res_x,
		g_map.el.res_y);
	g_img.data = (int *)mlx_get_data_addr(g_img.img_ptr, &g_img.bpp,
		&g_img.size_l, &g_img.endian);
	initialize_texture();
	draw_map();
	return (1);
}

int		red_button(void)
{
	exit_all();
	return (0);
}

int		main(int argc, char **argv)
{
	if (new_map(argv, argc) < 0)
		exit_all();
	else if (argc == 2)
	{
		if (start_game() < 0)
			exit_all();
		mlx_hook(g_mlx.win, 2, 1L >> 1, ft_key, (void *)0);
		mlx_hook(g_mlx.win, 17, 0, red_button, (void *)0);
		mlx_loop(g_mlx.mlx_ptr);
	}
	else if (argc == 3 && !ft_strncmp(argv[2], "--save", 5))
	{
		if (start_game() < 0)
			return (exit_all());
		if (screen_shot() < 0)
			exit_all();
	}
	else
		exit_all();
	return (0);
}
