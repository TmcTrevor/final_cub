#include "../Headers/cube3d.h"
char	*get_east_texture()
{
	int	i;
	int	j;
	int	count;

	i = 2;
	count = 0;
	while (map.el.elem[map.el.east_line][i] == ' ')
		i++;
	j = i;
	i = i - 1;
	while (map.el.elem[map.el.east_line][i++] != '\0')
		count++;
	i = j;
	j = 0;
	if (!(map.el.e_path = malloc(sizeof(char) * count + 1)))
		return (NULL);
	while (map.el.elem[map.el.east_line][i] != '\0')
	{
		map.el.e_path[j] = map.el.elem[map.el.east_line][i];
		i++;
		j++;
	}
	map.el.e_path[j] = '\0';
	return ("");
}

char	*get_west_texture()
{
	int	i;
	int	j;
	int	count;

	i = 2;
	count = 0;
	while (map.el.elem[map.el.west_line][i] == ' ')
		i++;
	j = i;
	i = i - 1;
	while (map.el.elem[map.el.west_line][i++] != '\0')
		count++;
	i = j;
	j = 0;
	if (!(map.el.w_path = malloc(sizeof(char) * count + 1)))
		return (NULL);
	while (map.el.elem[map.el.west_line][i] != '\0')
	{
		map.el.w_path[j] = map.el.elem[map.el.west_line][i];
		i++;
		j++;
	}
	map.el.w_path[j] = '\0';
	return ("");
}

char	*get_south_texture()
{
	int	i;
	int	j;
	int	count;

	i = 2;
	count = 0;
	while (map.el.elem[map.el.south_line][i] == ' ')
		i++;
	j = i;
	i = i - 1;
	while (map.el.elem[map.el.south_line][i++] != '\0')
		count++;
	i = j;
	j = 0;
	if (!(map.el.s_path = malloc(sizeof(char) * count + 1)))
		return (NULL);
	while (map.el.elem[map.el.south_line][i] != '\0')
	{
		map.el.s_path[j] = map.el.elem[map.el.south_line][i];
		i++;
		j++;
	}
	map.el.s_path[j] = '\0';
	return ("");
}

char	*get_north_texture()
{
	int	i;
	int	j;
	int	count;

	i = 2;
	count = 0;
	while (map.el.elem[map.el.north_line][i] == ' ')
		i++;
	j = i;
	i = i - 1;
	while (map.el.elem[map.el.north_line][i++] != '\0')
		count++;
	i = j;
	j = 0;
	if (!(map.el.n_path = malloc(sizeof(char) * count + 1)))
		return (NULL);
	while (map.el.elem[map.el.north_line][i] != '\0')
	{
		map.el.n_path[j] = map.el.elem[map.el.north_line][i];
		i++;
		j++;
	}
	map.el.n_path[j] = '\0';
	return ("");
}

char	*get_sprite_texture()
{
	int	i;
	int	j;
	int	count;

	i = 2;
	count = 0;
	while (map.el.elem[map.el.sprite_line][i] == ' ')
		i++;
	j = i;
	i = i - 1;
	while (map.el.elem[map.el.sprite_line][i++] != '\0')
		count++;
	i = j;
	j = 0;
	if (!(map.el.spr_path = malloc(sizeof(char) * count + 1)))
		return (NULL);
	while (map.el.elem[map.el.sprite_line][i] != '\0')
	{
		map.el.spr_path[j] = map.el.elem[map.el.sprite_line][i];
		i++;
		j++;
	}
	map.el.spr_path[j] = '\0';
	return ("");
}
