/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <mokhames@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:15:45 by mokhames          #+#    #+#             */
/*   Updated: 2021/01/25 07:33:54 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ELEMENTS_H
# define FT_ELEMENTS_H

# include "cube3d.h"

typedef struct		s_elements
{
	char			**elem;
	int				resolution_line;
	int				res_x;
	int				res_y;
	int				north_line;
	int				south_line;
	int				west_line;
	int				east_line;
	int				sprite_line;
	int				f_l;
	int				c_l;
	int				c_r;
	int				c_g;
	int				c_b;
	int				f_r;
	int				f_g;
	int				f_b;
	int				c_color_hex;
	int				f_color_hex;
	char			*n_path;
	char			*s_path;
	char			*w_path;
	char			*e_path;
	char			*spr_path;
	int				nb_rays;
	int				wsw;
}					t_elements;
int					get_floor_color();
int					get_ceilling_color();
void				create_hex_color();
int					check_elements_errors();
int					check_map_errors();
void				ft_join(char *line, char *c);
void				ft_join2(char *line, char *c);

#endif
