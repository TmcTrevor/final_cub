/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <mokhames@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 18:19:25 by mokhames          #+#    #+#             */
/*   Updated: 2021/01/24 19:46:31 by mokhames         ###   ########.fr       */
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

	line = "";
	g_map.parser->map_string = ft_strdup("");
	/*while (line[0] == '\0')
	{	get_next_line(fd, &line);
		free(line);
	}
		tmp = g_map.parser->map_string;
	g_map.parser->map_string = ft_strjoin(g_map.parser->map_string, line);
	free(tmp);
	tmp = g_map.parser->map_string;
	g_map.parser->map_string = ft_strjoin(g_map.parser->map_string, "\n");
	free(tmp);*/
	while (get_next_line(fd, &line))
	{
		if (line[0] == '\0')
			write_error_one();
			tmp = g_map.parser->map_string;
	g_map.parser->map_string = ft_strjoin(g_map.parser->map_string, line);
	free(tmp);
	tmp = g_map.parser->map_string;
	g_map.parser->map_string = ft_strjoin(g_map.parser->map_string, "\n");
	free(tmp);
		free(line);
		line = NULL;
	}
	tmp = g_map.parser->map_string;
	g_map.parser->map_string = ft_strjoin(g_map.parser->map_string, line);
	free(tmp);
	tmp = g_map.parser->map_string;
	g_map.parser->map_string = ft_strjoin(g_map.parser->map_string, "\0");
	free(tmp);
	free(line);
	line = NULL;
	return (1);
}

int		parse_line(int fd)
{
	char	*line;
	int		i;
	char	*tmp;

	i = 0;
	g_map.parser->data = ft_strdup("");
	while (get_next_line(fd, &line) && i < 7)
	{
		if (line[0] == '\0')
			get_next_line(fd, &line);
		if (!ft_isdigit(line[0]))
		{
			tmp = g_map.parser->data;
			g_map.parser->data = ft_strjoin(g_map.parser->data, line);
			free(tmp);
			tmp = g_map.parser->data;
			g_map.parser->data = ft_strjoin(g_map.parser->data, "\n");
			free(tmp);
			free(line);
			line = NULL;
			i++;
		}
	}
	while (line[0] == '\0')
		get_next_line(fd, &line);
	tmp = g_map.parser->data;
			g_map.parser->data = ft_strjoin(g_map.parser->data, line);
			free(tmp);
			tmp = g_map.parser->data;
			g_map.parser->data = ft_strjoin(g_map.parser->data, "\0");
			free(tmp);
			
	free(line);
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
	if (create_map() < 0)
		return (-1);
	if (create_good_size_map() < 0)
		return (-1);
	if (get_elements() < 0)
		return (-1);
	if (check_elements_errors() < 0)
		return (-1);
	if (check_map_errors() < 0)
		return (-1);
	return (1);
}
