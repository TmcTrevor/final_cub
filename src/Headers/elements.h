#ifndef FT_ELEMENTS_H
# define FT_ELEMENTS_H
# include "cube3d.h"
typedef struct		s_elements
{
	char	**elem;
	int		resolution_line;
	int		res_x;
	int		res_y;
	int		north_line;
	int		south_line;
	int		west_line;
	int		east_line;
	int		sprite_line;
	int		f_l;
	int		c_l;
	int		c_r;
	int		c_g;
	int		c_b;
	int		f_r;
	int		f_g;
	int		f_b;
	int		c_color_hex;
	int		f_color_hex;
	char	*n_path;
	char	*s_path;
	char	*w_path;
	char	*e_path;
	char	*spr_path;
}					t_elements;

#endif