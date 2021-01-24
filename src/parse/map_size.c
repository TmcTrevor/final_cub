/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <mokhames@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 18:03:05 by mokhames          #+#    #+#             */
/*   Updated: 2021/01/24 11:00:07 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/cube3d.h"

char	*create_new_line(char *str, int diff)
{
	int		i;
	char	*new;

	i = 0;
	if (!(new = malloc(sizeof(char *) * (ft_strlen(str) + diff + 1))))
		return (NULL);
	while (str[i] != '\0')
	{
		new[i] = str[i];
		i++;
	}
	while (diff > 0)
	{
		new[i] = ' ';
		i++;
		diff--;
	}
	
	new[i] = '\0';
	//free(new);
	return (new);
}

int		calcul_len(int len, int i)
{
	while (map.parser->grid[i] != NULL)
	{
		if (ft_strlen(map.parser->grid[i]) > len)
			len = ft_strlen(map.parser->grid[i]);
		i++;
	}
	map.parser->len = len;
	return (len);
}

int		create_good_size_map(void)
{
	int i;
	int len;
	int diff;

	i = 0;
	diff = 0;
	len = ft_strlen(map.parser->grid[i]);
	len = calcul_len(len, i);
	i = 0;
	while (map.parser->grid[i] != NULL)
	{
		if (ft_strlen(map.parser->grid[i]) < len)
		{
			diff = len - ft_strlen(map.parser->grid[i]);
			if (!(map.parser->grid[i] =
				create_new_line(map.parser->grid[i], diff)))
				return (-1);
		}
		i++;
	}
	return (1);
}
