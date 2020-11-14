#include "../Headers/cube3d.h"

int		transform_to_hex(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}
void	create_hex_color()
{
	map.el.c_color_hex = transform_to_hex(map.el.c_r,
		map.el.c_g, map.el.c_b);
	map.el.f_color_hex = transform_to_hex(map.el.f_r,
		map.el.f_g, map.el.f_b);
}