/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <mokhames@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:15:33 by mokhames          #+#    #+#             */
/*   Updated: 2021/01/24 18:15:34 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SPRITE_H
#define FT_SPRITE_H
#include "cube3d.h"

typedef struct s_spr
{
	float x;
	float y;
	float distance;
	void	*ptr;
	int		*data;
	float 	dist2;

} t_spr;

typedef struct s_utils
{
	int x_star;
	int y_star;
	int x_end;
	int y_end;
	int height;
	float move;
	int a;
	int b;
	

} t_utils;

typedef struct s_util
{
	float xintercept;
	float yintercept;
	float xstep;
	float ystep;
	float nextx;
	float nexty;
	float xtocheck;
	float ytocheck;
	float wallstripheight;

}		t_util;

t_util	g_util;
float verhitsprites_x;
float verhitsprites_y;
float horzhitsprites_x;
float horzhitsprites_y;
int is_vertical;
void free_spr();
int get_sprites();
void init_spr();
void draw_sprit(int x);
void render_sprites(float x, float y, int id);
void render_w_s(int i);
void	ft_sprite(void);
#endif