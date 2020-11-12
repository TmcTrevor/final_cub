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
	return (new);
}

int		create_good_size_map()
{
	int i;
	int len;
	int diff;

	i = 0;
	diff = 0;
	len = ft_strlen(map.parser->grid[i]);
	while (map.parser->grid[i] != NULL)
	{
		if (ft_strlen(map.parser->grid[i]) > len)
			len = ft_strlen(map.parser->grid[i]);
		i++;
	}
	i = 0;
	while (map.parser->grid[i] != NULL)
	{
		if (ft_strlen(map.parser->grid[i]) < len)
		{
			diff = len - ft_strlen(map.parser->grid[i]);
            //printf("\n d = %zu",ft_strlen("        1111111111111111111111111"));
			//printf("\ndiff =%d\n len = %d\n",diff,len);
			if (!(map.parser->grid[i] = create_new_line(map.parser->grid[i], diff)))
				return (-1);
		}
		i++;
	}
	return (1);
}