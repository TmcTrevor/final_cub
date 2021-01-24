/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <mokhames@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:09:33 by mokhames          #+#    #+#             */
/*   Updated: 2021/01/24 18:18:50 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXAMPLE_H
# define EXAMPLE_H

# include <math.h>
# include "mlx.h"
# include "../../ft_printf.h"
# include "fcntl.h"
# include "map.h"
# include "player.h"
# include "../../GNL/get_next_line.h"
# include "ray.h"
# include "sprite.h"
# include "elements.h"
# define DEFAULT_WINDOW_X 2560
# define DEFAULT_WINDOW_Y 1395
# define MAP_GAME "0123NSEW"
# define PLAYER_INIT_POS "NSEW"
# define TILE_SIZE 1
# define ESC 53
# define UP 13
# define DOWN 1
# define RIGHT 2
# define LEFT 0
# define SPACE 49
# define SHIFHT 257
# define L_AROW 123
# define R_AROW	124
# define BLUE 255
# define RED 16711680
# define WHITE 16777215
# define BLACK 0
# define GREEN 65280
# define YELLOW 16776960
# define GREY 6579300
# define MOVE_SPEED 0.13
# define ROTATE_SPEED 2.7
# define FOV 60
# define RUN_SPEED 0.131
# define RUN_ROTATE_SPEED 2.72
# define STRAF_FACTOR 2
# define NB_TEXTURE 7
# define TEX_NO 0
# define TEX_SO 1
# define TEX_WE 2
# define TEX_EA 3
# define TEX_S 4
# define TEX_LIFE 5
# define TEX_SCOOP 6
# define TEXTURE_SIZE 663
# define FAC_UP 0
# define FAC_DOWN 1
# define FAC_LEFT 2
# define FAC_RIGHT 3
# define ARROW_UP 126
# define ARROW_DOWN 125
# define MLXK_ESC 53
# define MLXK_X 17
# define MLXK_W 13
# define MLXK_A 0
# define MLXK_S 1
# define MLXK_D 2
# define MLXK_LEFT 123
# define MLXK_RIGHT 124
# define MLXK_UP 126
# define MLXK_DOWN 125
# define MLXK_TD 14
# define MLXK_TG 12
# define FOV_ANGLE 1.04719755

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win;

}				t_mlx;

void		dimension(t_map *map);
void		draw(void);
int			nie(int key, void *p);

t_mlx	g_mlx;
t_img 	g_img; 
t_map	g_map;

int			start_game();
void		init_struct();
void		read_map(t_map *map);

void		read_2d_map(t_map *map);

t_map		*new_game(t_map *map);
double		normelize_angel(double angle);
void		image_put_pixel(int x, int y, int color);
void		line(int x0, int y0, int x1, int y1, int color);
double		ray_len(t_ray *ray);

#endif
