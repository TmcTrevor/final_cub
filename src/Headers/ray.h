# ifndef FT_RAY_H
#define FT_RAY_H

#include "vector.h"

typedef struct s_ray{
        float    posx;
        float    posy;  
        float   len;
        int     kind;
        double   angle;
        int index;
        int coli;
       void (*update)(struct s_ray *this, double angle, int i);
        void    (*cast)(void *ray);
        void    (*render)(struct s_ray *this);
        double (*length)(struct s_ray *this);
        void (*free)(void *item);
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


#endif