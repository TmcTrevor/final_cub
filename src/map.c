/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <mokhames@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 14:32:14 by mokhames          #+#    #+#             */
/*   Updated: 2021/01/24 09:35:38 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers/cube3d.h"


static void		*ft_memalloc(size_t size)
{
	void	*mem;

	if (!(mem = malloc(size)))
		return (NULL);
	ft_bzero(mem, size);
	return (mem);
}

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
	return 1;
}

int new_parser(char **argv,int argc)
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

	else if ((map.parser->fd = open(argv[1], O_RDONLY)) <= 0)
	{
		write(1, "Error\nNo such file or directory\n", 32);
		return (-1);
	}
	else if (ft_check_ext(argv[1]) < 0)
		return -1;
	//printf("%d\n",map.parser->fd);
	return (1);
}

int new_map(char **argv, int argc)
{
   map.parser = (t_parser *)ft_memalloc(sizeof(t_parser));
   
   if (new_parser(argv ,argc) < 0 )
	return (-1);
   
   
   return (1);
}