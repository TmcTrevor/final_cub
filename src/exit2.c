#include "Headers/cube3d.h"

void	free_spr()
{
	if (map.spr.zbuffer)
	{
		free(map.spr.zbuffer);
		map.spr.zbuffer = 0;
	}
	if (map.spr.sprites_x)
	{
		free(map.spr.sprites_x);
		map.spr.sprites_x = 0;
	}
	if (map.spr.sprites_y)
	{
		free(map.spr.sprites_y);
		map.spr.sprites_y = 0;
	}
}

void	free_tex()
{
	if (map.tex.color_n)
	{
		free(map.tex.color_n);
		map.tex.color_n = 0;
	}
	if (map.tex.color_s)
	{
		free(map.tex.color_s);
		map.tex.color_s = 0;
	}
	if (map.tex.color_e)
	{
		free(map.tex.color_e);
		map.tex.color_e = 0;
	}
	if (map.tex.color_w)
	{
		free(map.tex.color_w);
		map.tex.color_w = 0;
	}
}