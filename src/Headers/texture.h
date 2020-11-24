#ifndef FT_TEXTURE_H
#define FT_TEXTURE_H
#include "cube3d.h"

typedef struct		s_tex
{
	int		texwidth;
	int		texheight;
	void	*color_n;
	void	*color_s;
	void	*color_e;
	void	*color_w;
	int		texx;
	int		texy;
	float	step;
	float	texpos;
	int		*color;
}					t_tex;

void    free_tex();
#endif