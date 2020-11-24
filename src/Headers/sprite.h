#ifndef FT_SPRITE_H
# define FT_SPRITE_H
#include "cube3d.h"

typedef struct		s_spr
{
	int		numsprites;
	void	*spr_tex;
	int		*color;
	int		sprwidth;
	int		sprheight;
	float	spritex;
	float	spritey;
	float	invdet;
	float	transformx;
	float	transformy;
	int		spritescreenx;
	int		drawstarty;
	int		drawendy;
	int		drawstartx;
	int		drawendx;
	int		stripe;
	int		texx;
	int		texy;
	float	*zbuffer;
	float	*sprites_x;
	float	*sprites_y;
	float	spritedistance;
	int		vmovescreen;
}					t_spr;
void	free_spr();
#endif