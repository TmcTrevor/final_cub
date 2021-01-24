/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <mokhames@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 18:02:21 by mokhames          #+#    #+#             */
/*   Updated: 2021/01/24 18:20:26 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/cube3d.h"

char	*get_east_texture(void)
{
	int	i;
	int	j;
	int	count;

	i = 2;
	count = 0;
	while (g_map.el.elem[g_map.el.east_line][i] == ' ')
		i++;
	j = i;
	i = i - 1;
	while (g_map.el.elem[g_map.el.east_line][i++] != '\0')
		count++;
	i = j;
	j = 0;
	if (!(g_map.el.e_path = malloc(sizeof(char) * count + 1)))
		return (NULL);
	while (g_map.el.elem[g_map.el.east_line][i] != '\0')
	{
		g_map.el.e_path[j] = g_map.el.elem[g_map.el.east_line][i];
		i++;
		j++;
	}
	g_map.el.e_path[j] = '\0';
	return ("");
}

char	*get_west_texture(void)
{
	int	i;
	int	j;
	int	count;

	i = 2;
	count = 0;
	while (g_map.el.elem[g_map.el.west_line][i] == ' ')
		i++;
	j = i;
	i = i - 1;
	while (g_map.el.elem[g_map.el.west_line][i++] != '\0')
		count++;
	i = j;
	j = 0;
	if (!(g_map.el.w_path = malloc(sizeof(char) * count + 1)))
		return (NULL);
	while (g_map.el.elem[g_map.el.west_line][i] != '\0')
	{
		g_map.el.w_path[j] = g_map.el.elem[g_map.el.west_line][i];
		i++;
		j++;
	}
	g_map.el.w_path[j] = '\0';
	return ("");
}

char	*get_south_texture(void)
{
	int	i;
	int	j;
	int	count;

	i = 2;
	count = 0;
	while (g_map.el.elem[g_map.el.south_line][i] == ' ')
		i++;
	j = i;
	i = i - 1;
	while (g_map.el.elem[g_map.el.south_line][i++] != '\0')
		count++;
	i = j;
	j = 0;
	if (!(g_map.el.s_path = malloc(sizeof(char) * count + 1)))
		return (NULL);
	while (g_map.el.elem[g_map.el.south_line][i] != '\0')
	{
		g_map.el.s_path[j] = g_map.el.elem[g_map.el.south_line][i];
		i++;
		j++;
	}
	g_map.el.s_path[j] = '\0';
	return ("");
}

char	*get_north_texture(void)
{
	int	i;
	int	j;
	int	count;

	i = 2;
	count = 0;
	while (g_map.el.elem[g_map.el.north_line][i] == ' ')
		i++;
	j = i;
	i = i - 1;
	while (g_map.el.elem[g_map.el.north_line][i++] != '\0')
		count++;
	i = j;
	j = 0;
	if (!(g_map.el.n_path = malloc(sizeof(char) * count + 1)))
		return (NULL);
	while (g_map.el.elem[g_map.el.north_line][i] != '\0')
	{
		g_map.el.n_path[j] = g_map.el.elem[g_map.el.north_line][i];
		i++;
		j++;
	}
	g_map.el.n_path[j] = '\0';
	return ("");
}

char	*get_sprite_texture(void)
{
	int	i;
	int	j;
	int	count;

	i = 2;
	count = 0;
	while (g_map.el.elem[g_map.el.sprite_line][i] == ' ')
		i++;
	j = i;
	i = i - 1;
	while (g_map.el.elem[g_map.el.sprite_line][i++] != '\0')
		count++;
	i = j;
	j = 0;
	if (!(g_map.el.spr_path = malloc(sizeof(char) * count + 1)))
		return (NULL);
	while (g_map.el.elem[g_map.el.sprite_line][i] != '\0')
	{
		g_map.el.spr_path[j] = g_map.el.elem[g_map.el.sprite_line][i];
		i++;
		j++;
	}
	g_map.el.spr_path[j] = '\0';
	return ("");
}
