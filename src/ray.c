#include "Headers/cube3d.h"



void   init_ray()
{
    map.ray = (t_ray *)malloc((map.el.res_x * sizeof(t_ray)));
    //map.ray[0].angle = 5;
}