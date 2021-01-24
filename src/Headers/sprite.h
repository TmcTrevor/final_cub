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

} t_utils;

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