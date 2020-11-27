#include "../Headers/cube3d.h"
//extern t_map *map;
int		return_error()
{
	write(1, "Error\n", 6);
	write(1, "Multiple initial positions\n", 27);
	return (exit_all());
}

int	write_error_one()
{
	write(1, "Error\n", 6);
	write(1, "Error in parsing\n", 17);
	return (exit_all());
	
}

int		parse_map(int fd)
{
	char *line;

	line = "";
	map.parser->map_string = "";
	while (line[0] == '\0')
		get_next_line(fd, &line);
	map.parser->map_string = ft_strjoin(map.parser->map_string, line);
	map.parser->map_string = ft_strjoin(map.parser->map_string, "\n");
	while (get_next_line(fd, &line))
	{
		if (line[0] == '\0')
			write_error_one();
		map.parser->map_string = ft_strjoin(map.parser->map_string, line);
		map.parser->map_string = ft_strjoin(map.parser->map_string, "\n");
		free(line);
		line = NULL;
	}
	map.parser->map_string = ft_strjoin(map.parser->map_string, line);
	map.parser->map_string = ft_strjoin(map.parser->map_string, "\0");
	free(line);
	line = NULL;
	return (1);
}
int		parse_line(int fd)
{
	char	*line;
	int		i;

	i = 0;
	map.parser->data = "";
	while (get_next_line(fd, &line) && i < 7)
	{
		if (line[0] == '\0')
			get_next_line(fd, &line);
		if (!ft_isdigit(line[0]))
		{
			map.parser->data = ft_strjoin(map.parser->data, line);
			map.parser->data = ft_strjoin(map.parser->data, "\n");
			free(line);
			line = NULL;
			i++;
		}
	}
	while (line[0] == '\0')
		get_next_line(fd, &line);
	map.parser->data = ft_strjoin(map.parser->data, line);
	map.parser->data = ft_strjoin(map.parser->data, "\0");
	free(line);
	line = NULL;
	return (1);
}

int		parse_main()
{
    int fd;
    fd = map.parser->fd;
	if (parse_line(fd) < 0)
		return (-1);
	if (parse_map(fd) < 0)
		return (-1);
	close(fd);
	if (create_map() < 0)
		return (-1);
	if (create_good_size_map() < 0)
		return (-1);
	/*if (get_sprites() < 0)
		return (-1);*/
	if (get_elements() < 0)
		return (-1);
	/*if (check_elements_errors() < 0)
		return (-1);
	if (check_map_errors() < 0)
		return (-1);*/
        int i = 0;
       // printf("\n%d",fd);
      // while(i < map.parser->line_nbr)
      // printf("\n%s\n",map.parser->data);
      // printf("hhhhhh");
      // printf("\n%s",map.parser->map_string);
	 // printf("\ne=%s e\n",map.parser->grid[i++]);

	return (1);
}