# ifndef FT_RAY_H
#define FT_RAY_H

#include "vector.h"

typedef struct s_ray{
        float    posx;
        float    posy;  
        float   len;
        int     kind;
        double   angle;
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

        
     
}       t_ray;

typedef struct s_ray_sp{
        t_vector *pos;
        t_vector *dir;
        int     offset;
        int     kind;
        double   angle;
        int index;
        double dist;
        struct s_sptites *sp;
        void    (*cast)(void *ray);
        void    (*render)(struct s_ray_sp *this);
        double (*length)(struct s_ray_sp *this);
        void (*update)(struct s_ray_sp *this, t_vector *dir, struct s_sptites *sp);
        void (*free)(void *item);
} t_ray_sp;

t_ray *new_ray(t_vector *pos, double angle, int i);
void    init_ray();
void    project_wall();
float    ft_line( int x, int y, int size ,float angle, int color);
void  cast_horizontal_inter_ray(float angle, int x);
void    check_angle(float angle, int x);
void    reset_ray(int x);
int     is_wall(int a, int b);
double distance(int x,int y, int x1,int y1);
//float    ft_line( int x, int y, int size ,float angle, int color);
void  cast_vertical_inter_ray(float angle, int x);
void    check_distance(int x, float angle);

#endif