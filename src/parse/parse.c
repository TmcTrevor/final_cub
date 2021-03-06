/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <mokhames@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 18:19:25 by mokhames          #+#    #+#             */
/*   Updated: 2021/02/10 17:40:43 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/cube3d.h"

int		return_error(void)
{
	write(1, "Error\n", 6);
	write(1, "Multiple initial positions\n", 27);
	return (exit_all());
}

int		write_error_one(void)
{
	write(1, "Error\n", 6);
	write(1, "Error in parsing\n", 17);
	return (exit_all());
}

int		parse_map(int fd)
{
	char *line;
	char *tmp;

	line = ft_strdup("");
	g_map.parser->map_string = ft_strdup("");
	while (line[0] == '\0')
	{
		tmp = line;
		get_next_line(fd, &line);
		free(tmp);
	}
	ft_join(line, "\n");
	while (get_next_line(fd, &line))
	{
		if (line[0] == '\0')
			write_error_one();
		ft_join(line, "\n");
		line = NULL;
	}
	ft_join(line, "\0");
	line = NULL;
	return (1);
}

int		parse_line(int fd)
{
	char	*line;
	int		i;
	char	*tmp;
	int     j;

	i = 0;
	j = 0;
	g_map.parser->data = ft_strdup("");
	while (get_next_line(fd, &line) && i < 7)
	{
		while (line[0] == '\0')
			get_next_line(fd, &line);
		/*if (!ft_isdigit(line[0]))
		{
			while (line[j] == ' ')
				j++;
			if (!ft_isdigit(line[j]))
			{
				ft_join2(line, "\n");
				line = NULL;
				i++;
		 	}
		}*/
		while (line[j] == ' ')
			j++;
		if (!ft_isdigit(line[j]))
		{
			ft_join2(line, "\n");
				line = NULL;
				i++;
		}
		else 
			break;
	j = 0;
	}
	if (i < 7)
	{
		write(1, "element missing\n", 16);
		exit_all();
	}
	ft_join2(line, "\0");
	line = NULL;
	return (1);
}

int		parse_main(void)
{
	int fd;

	fd = g_map.parser->fd;
	if (parse_line(fd) < 0)
		return (-1);
	if (parse_map(fd) < 0)
		return (-1);
	close(fd);
	//printf("%s\n------------------------------\n",g_map.parser->data);
	printf("%s\n",g_map.parser->map_string);
	if (get_elements() < 0)
		return (-1);
	if (check_color_range() < 0)
		return (-1);
	if (create_map() < 0)
		return (-1);
	if (create_good_size_map() < 0)
		return (-1);
	if (check_elements_errors() < 0)
		return (-1);
	if (check_map_errors() < 0)
		return (-1);
	return (1);
}
