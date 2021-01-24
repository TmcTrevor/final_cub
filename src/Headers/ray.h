/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <mokhames@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:15:36 by mokhames          #+#    #+#             */
/*   Updated: 2021/01/24 18:15:37 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_RAY_H
#define FT_RAY_H


#include "sprite.h"

typedef struct s_ray{
        
        float    posx;
        float    posy;  
        float   len;
        int     kind;
        float   angle;
        float   xstep;
        float   ystep;
        float   xintercept;
        float   yintercept;
        float   h_wallhitx;
        float   h_wallhity;
        float   v_wallhitx;
        float   v_wallhity;
        float   wallhitx;
        float   wallhity;
        float   distance;
        float   wallstripheight;
        int     ray_down;
        int     ray_up;
        int     ray_right;
        int     ray_left;
        int     verwallhit;
        int     horzwallhit;
        int     wasvertical;
        int     issprite;
     
}       t_ray;

typedef struct s_var_ray
{
    float xintercept;
    float yintercept;
    float xstep;
    float ystep;
    float nextx;
    float nexty;
    float xtocheck;
    float ytocheck;
}              t_var_ray;



void    init_ray();
void    project_wall();
float    ft_line( int x, int y, int size ,float angle, int color);
void  cast_horizontal_inter_ray(float angle, int x);
void    check_angle(float angle, int x);
void    reset_ray(int x);
int     is_wall(int a, int b);
float distance(float x,float y, float x1,float y1);
//float    ft_line( int x, int y, int size ,float angle, int color);
void  cast_vertical_inter_ray(float angle, int x);
void    check_distance(int x, float angle);
void    free_ray(void);
void    free_map(void);

#endif