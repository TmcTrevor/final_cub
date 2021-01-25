/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <mokhames@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 07:11:37 by mokhames          #+#    #+#             */
/*   Updated: 2021/01/25 09:29:25 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/cube3d.h"

void	ft_join(char *line, char *c)
{
	char *tmp;

	tmp = g_map.parser->map_string;
	g_map.parser->map_string = ft_strjoin(g_map.parser->map_string, line);
	free(tmp);
	tmp = g_map.parser->map_string;
	g_map.parser->map_string = ft_strjoin(g_map.parser->map_string, c);
	free(tmp);
	free(line);
}

void	ft_join2(char *line, char *c)
{
	char *tmp;

	tmp = g_map.parser->data;
	g_map.parser->data = ft_strjoin(g_map.parser->data, line);
	free(tmp);
	tmp = g_map.parser->data;
	g_map.parser->data = ft_strjoin(g_map.parser->data, c);
	free(tmp);
	free(line);
}

int		ft_digit2(char *c)
{
	int i;

	i = 0;
	while (c[i])
	{
		if (!ft_isdigit(c[i]))
			return (-1);
		i++;
	}
	return (1);
}

int		check_digits(char *c)
{
	int i;

	i = 0;
	while (ft_isdigit(c[i]))
		i++;
	if (i > 4)
		return (-1);
	return (1);
}

int		len_of_line(char **str)
{
	int o;

	o = 0;
	while (*(str + o))
		o++;
	return (o);
}
