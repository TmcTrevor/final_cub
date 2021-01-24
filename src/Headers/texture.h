#ifndef FT_TEXTURE_H
#define FT_TEXTURE_H


typedef struct		s_tex
{
	int		texwidth;
	int		texheight;
	/*int		*spr_tex;
	int		*color_n;
	int		*color_s;
	int		*color_e;
	int		*color_w;*/
	int		texx;
	int		texy;
	float	step;
	float	texpos;
	int		*color;
	
}					t_tex;

typedef struct		s_tex_height
{
	int		texwidth;
	int		texheight;
	int		*color;
}					t_tex1;


void    free_tex();
char	*get_sprite_texture();
char	*get_north_texture();
char	*get_west_texture();	
char	*get_east_texture();
char	*get_south_texture();
int		initialize_texture();
#endif