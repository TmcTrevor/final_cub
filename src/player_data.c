#include "Headers/cube3d.h"
void	data_e_w()
{
	if (map.parser->dir == 'E')
	{
		map.player.planex = 0;
		map.player.planey = 0.66;
		map.player.dirx = 1;
		map.player.diry = 0;
	}
	if (map.parser->dir == 'W')
	{
		map.player.planex = 0;
		map.player.planey = -0.66;
		map.player.dirx = -1;
		map.player.diry = 0;
	}
}

void	data_n_s()
{
	if (map.parser->dir == 'S')
	{
		map.player.planex = -0.66;
		map.player.planey = 0;
		map.player.dirx = 0;
		map.player.diry = 1;
	}
	if (map.parser->dir == 'N')
	{
		map.player.planex = 0.66;
		map.player.planey = 0;
		map.player.dirx = 0;
		map.player.diry = -1;
	}
}
int		player_data()
{
	data_e_w();
	data_n_s();
	map.player.posx = map.parser->pos_x_init;
	map.player.posy = map.parser->pos_y_init;
	map.tex.texwidth = 64;
	map.tex.texheight = 64;
	map.spr.sprwidth = 0;
	map.spr.sprheight = 0;
	map.player.mov_speed = 0.2;
	map.player.rotation_speed = 0.06;
	if (!(map.spr.zbuffer = malloc(sizeof(float *) * map.el.res_x + 1)))
		return (exit_all());
	return (1);
}
