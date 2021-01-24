/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <mokhames@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:30:16 by mokhames          #+#    #+#             */
/*   Updated: 2021/01/24 18:30:17 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers/cube3d.h"

int		ft_check_ext(char *str)
{
	int		i;

	i = ft_strlen(str) - 4;
	if (ft_strncmp(str + i, ".cub", 5) != 0)
	{
		write(1, "Error\n", 7);
		write(1, "file do not end with .cub", 25);
		return (-1);
	}
	return (1);
}

int		new_parser(char **argv, int argc)
{
	int fd;

	if (argc == 1 || argc > 3)
	{
		write(1, "Error\nInvalid arguments\n", 24);
		return (-1);
	}
	else if (argc == 3 && (ft_strncmp(argv[2], "--save", 6)))
	{
		write(1, "Error\nInvalid option\n", 21);
		return (-1);
	}
	else if ((g_map.parser->fd = open(argv[1], O_RDONLY)) <= 0)
	{
		write(1, "Error\nNo such file or directory\n", 32);
		return (-1);
	}
	else if (ft_check_ext(argv[1]) < 0)
		return (-1);
	return (1);
}

int		new_map(char **argv, int argc)
{
	g_map.parser = (t_parser *)malloc(sizeof(t_parser));
	if (new_parser(argv, argc) < 0)
		return (-1);
	return (1);
}
