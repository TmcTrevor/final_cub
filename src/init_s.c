#include "Headers/cube3d.h"

void    init_mlx()
{
    mlx.mlx_ptr = NULL;
	mlx.win = NULL;
}

void    init_image()
{
    img.img_ptr = NULL;
	img.data = NULL;
	img.bpp = 0;

	img.size_l = 0;
	img.endian = 0;
}
void    init_parser()
{
    map.parser->data = NULL;
	map.parser->map_string = NULL;
	map.parser->map_string_clean = NULL;
	map.parser->grid = NULL;
	map.parser->line_nbr = 0;
	map.parser->column_nbr = 0;
	map.parser->pos_x_init = 0;
	map.parser->pos_y_init = 0;
	map.parser->dir = 0;   
}
void    init_sprite()
{
    map.spr.numsprites = 0;
	map.spr.numsprites = 0;
	map.spr.spr_tex = NULL;
	map.spr.sprwidth = 0;
	map.spr.sprheight = 0;
	map.spr.spritex = 0;
	map.spr.spritey = 0;
	map.spr.invdet = 1;
	map.spr.transformx = 0;
	map.spr.transformy = 0;
	map.spr.spritescreenx = 0;
	map.spr.vmovescreen = 0;
	map.spr.drawstarty = 0;

    map.spr.drawendy = 0;
	map.spr.drawstartx = 0;
	map.spr.drawendx = 0;
	map.spr.stripe = 0;
	map.spr.texx = 0;
	map.spr.texy = 0;

	map.spr.spritedistance = 0;
}

void    init_struct()
{
    init_mlx();
    init_image();
    init_parser();
    init_sprite();

}