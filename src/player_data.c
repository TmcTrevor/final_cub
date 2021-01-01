#include "Headers/cube3d.h"
void	data_e_w()
{
	if (map.parser->dir == 'E')
	{
		map.player.rotation_angle =  2 * M_PI / 3;
		map.player.planex = 0;
		map.player.planey = 0.66;
		map.player.dirx = 1;
		map.player.diry = 0;
	}
	if (map.parser->dir == 'W')
	{
		map.player.rotation_angle = - M_PI / 6;
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
		map.player.rotation_angle = M_PI / 3;
		map.player.planex = -0.66;
		map.player.planey = 0;
		map.player.dirx = 0;
		map.player.diry = 1;
	}
	if (map.parser->dir == 'N')
	{
		map.player.rotation_angle = - 2 * M_PI / 3;
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
	
	map.wall_width =  (map.el.res_x / map.parser->len) * 0.2;
	map.wall_height = (map.el.res_y / map.parser->line_nbr) * 0.2;
	map.player.posx = map.parser->pos_x_init;
	map.player.posy = map.parser->pos_y_init;
	map.player.posx_p = map.player.posx * map.wall_width;
	map.player.posy_p = map.player.posy * map.wall_height;
	map.player.posx_p += map.wall_width  / 2;
	map.player.posy_p += map.wall_height /2;
	map.tex.texwidth = 64;
	map.tex.texheight = 64;
	map.spr.sprwidth = 0;
	map.spr.sprheight = 0;
	map.player.mov_speed = 30;
	map.player.rotation_speed = 2 * (M_PI / 180);
	map.el.wsw = 1;
	map.el.nb_rays = map.el.res_x / map.el.wsw;
	map.distanceProjPlane = (map.el.res_x / 2)  * tan(M_PI /6);
	init_ray();
	
	if (!(map.spr.zbuffer = malloc(sizeof(float *) * map.el.res_x + 1)))
		return (exit_all());
	return (1);
}
