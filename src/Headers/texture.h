#ifndef FT_TEXTURE_H
#define FT_TEXTURE_H
#include "cube3d.h"

typedef struct		s_tex
{
	int		texwidth;
	int		texheight;
	int		*color_n;
	int		*color_s;
	int		*color_e;
	int		*color_w;
	int		texx;
	int		texy;
	float	step;
	float	texpos;
	int		*color;
	
}					t_tex;

void    free_tex();
char	*get_sprite_texture();
char	*get_north_texture();
char	*get_west_texture();	
char	*get_east_texture();
char	*get_south_texture();
void	initialize_texture();
#endif