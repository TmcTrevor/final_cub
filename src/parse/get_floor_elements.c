#include "../Headers/cube3d.h"

int		write_error_floor(int i)
{
	if (map.el.elem[map.el.f_l][i] == '\0' ||
		map.el.elem[map.el.f_l][i] != ' ')
	{
		write(1, "Error\n", 6);
		write(1, "Wrong arguments\n", 16);
		exit_all();
	}
	return (-1);
}

int		write_error_end_floor(int i)
{
	if (map.el.elem[map.el.f_l][i] != ' ')
	{
		write(1, "Error\n", 6);
		write(1, "Wrong arguments\n", 16);
		exit_all();
	}
	return (-1);
}

int		get_floor_color()
{
	int i;

	i = 0;
	while (map.el.elem[map.el.f_l][++i] == ' ')
		i++;
	while (map.el.elem[map.el.f_l][i] >= '0' && map.el.elem[map.el.f_l][i] <= '9')
		map.el.f_r = (map.el.f_r * 10) + map.el.elem[map.el.f_l][i++] - '0';
	i = i - 1;
	while (map.el.elem[map.el.f_l][++i] != ',')
		write_error_floor(i);
	while (!ft_isdigit(map.el.elem[map.el.f_l][++i]))
		write_error_floor(i);
	while (map.el.elem[map.el.f_l][i] >= '0' && map.el.elem[map.el.f_l][i] <= '9')
		map.el.f_g = (map.el.f_g * 10) + map.el.elem[map.el.f_l][i++] - '0';
	i = i - 1;
	while (map.el.elem[map.el.f_l][++i] != ',')
		write_error_floor(i);
	while (!ft_isdigit(map.el.elem[map.el.f_l][++i]))
		write_error_floor(i);
	while (map.el.elem[map.el.f_l][i] >= '0' && map.el.elem[map.el.f_l][i] <= '9')
		map.el.f_b = (map.el.f_b * 10) + map.el.elem[map.el.f_l][i++] - '0';
	i = i - 1;
	while (map.el.elem[map.el.f_l][++i] != '\0')
		write_error_end_floor(i);
	return (0);
}
