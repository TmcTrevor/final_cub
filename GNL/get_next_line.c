/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:21:58 by mokhames          #+#    #+#             */
/*   Updated: 2020/01/08 14:33:29 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 10

static char			*read_save(char *save, char **line)
{
	char *str;
	char *tmp;

	str = NULL;
	if (save)
	{
		if ((str = ft_strchr(save, '\n')))
		{
			*str = '\0';
			*line = ft_strdup(save);
			ft_strcpy(save, ++str);
		}
		else
		{
			*line = ft_strdup(save);
			save = ft_calloc(1, 1);
			tmp = save;
			free(tmp);
		}
	}
	else
		*line = ft_calloc(1, 1);
	return (str);
}

static int			help(char **save, char **buff)
{
	free(*save);
	*save = NULL;
	free(*buff);
	return (0);
}

static void			help1(char **str, char **save)
{
	char *tmp;

	**str = '\0';
	*str += 1;
	tmp = *save;
	*save = ft_strdup(*str);
	free(tmp);
}

int					get_next_line(int fd, char **line)
{
	static char	*save;
	char		*buff;
	int			size_read;
	char		*str;
	char		*tmp;

	if (fd < 0 || line == NULL || (read(fd, NULL, 0) != 0) ||
			!(buff = malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (-1);
	str = read_save(save, line);
	while (!str)
	{
		if ((size_read = read(fd, buff, BUFFER_SIZE)) == 0)
			return (help(&save, &buff));
		buff[size_read] = '\0';
		if ((str = ft_strchr(buff, '\n')))
			help1(&str, &save);
		tmp = *line;
		*line = ft_strjoin(*line, buff);
		free(tmp);
	}
	free(buff);
	return (1);
}
/*int main()
{
	int fd;
	char **line;
	char *e;

	fd = open("hello",O_RDONLY);
	while (get_next_line(fd,line) > 0)
	{
		e = *line;
		printf("%s\n",e);
	}
	if (get_next_line(fd,line) ==  1)
		{	
			get_next_line(fd,line);
			e = *line;
		}
		printf("%s",e);
}*/
