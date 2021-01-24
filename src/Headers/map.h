/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <mokhames@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:15:42 by mokhames          #+#    #+#             */
/*   Updated: 2021/01/24 18:15:43 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_H
# define FT_MAP_H

#include "player.h"
#include "sprite.h"
#include "cube3d.h"
#include "elements.h"
#include "texture.h"
#include "ray.h"
#include <limits.h>

typedef struct s_parser{
        //t_array_list lines;
        int             fd;
        int             line_nbr;
        int             column_nbr;
        int             pos_x_init;
        int             pos_y_init;
        int             dir;
        char            *data;
        char            *map_string;
        char            **grid;
        int             len;
        
}           t_parser;



typedef struct s_map
{
    //t_vector    *ppos; //player position
    int         WIN_WIDTH;
    int         WIN_HEIGHT;
    int         fd;
    double      w;
    double      h;
    int         wall_height;
    int         wall_width;
    int         numsprites;

    float       distanceProjPlane;
    
    t_player    player;
 
    t_parser    *parser;
    t_spr       **spr;
    t_elements  el;
    t_tex       tex;
    t_ray       *ray;
    t_utils     util;
    t_tex1      tex1[5];
   
    //t_array_list walls;



}               t_map;


int new_map(char **argv, int argc);
void get_lines(t_parser *this);
int get_fd(char *filename);
int new_parser(char **argv, int argc);
///////// parser check//////
int		parse_main();
int             parse_line(int fd);
int             parse_map(int fd);
int             create_map();
int             check_borders_lines();
int             check_borders_columns();
int		create_good_size_map();
int             get_elements();
int             exit_all();
int             draw_map();
int             ft_key();
int     screen_shot();
float	normalize_angle(float angle);
int     is_wall2(float a, float b, char c);
int     check_map_errors();
int		check_map_errors();
int		return_error_exit(void);
void	free_parser();

#endif


