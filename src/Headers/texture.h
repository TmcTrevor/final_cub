/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <mokhames@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:15:30 by mokhames          #+#    #+#             */
/*   Updated: 2021/01/25 08:09:33 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TEXTURE_H
# define FT_TEXTURE_H

typedef struct		s_tex
{
	int				texwidth;
	int				texheight;
	int				texx;
	int				texy;
	float			step;
	float			texpos;
	int				*color;
}					t_tex;

typedef struct		s_tex_height
{
	int				texwidth;
	int				texheight;
	int				*color;
}					t_tex1;

void				free_tex();
char				*get_sprite_texture();
char				*get_north_texture();
char				*get_west_texture();
char				*get_east_texture();
char				*get_south_texture();
int					initialize_texture();
#endif
