#include "Headers/cube3d.h"



void   init_ray()
{
    int x;

    x = 0;
    map.ray = (t_ray *)malloc((map.el.res_x * sizeof(t_ray)));
    while (x < map.el.res_x)
    {
        map.ray[x].len = 0;
		map.ray[x].posx = map.player.posx_p;
		map.ray[x].posy = map.player.posy_p;
		map.ray[x].angle = 0;
		map.ray[x].wallstripheight = 0;
   map.ray[x].ray_down = 0;
     map.ray[x].ray_up = 0;
     map.ray[x].ray_right = 0;
     map.ray[x].ray_left = 0;        
        x++;
    }
    //map.ray[0].angle = 5;
 //  while (i <)

}
void rec(int  x ,int  y, int  sizex ,int sizey)
{
  int x2 = x + sizex;
  int y2 = y+ sizey;
  int vx =  x;
  while (y < y2)
  {
    vx = x;
      while (vx < x2)
        {
          img.data[y * map.el.res_x + vx] = WHITE;
          vx++;
        }
        y += 1;
  }

}
void  check_angle(float angle,int x)
{
  if (angle > 0 && angle < M_PI)
      map.ray[x].ray_down = 1;
  else
      map.ray[x].ray_up = 1;
  if )
  

}
void  cast_horizontal_inter_ray(float angle)
{
    float xintercept;
    float yintercept;
    float xstep;
    float ystep;
    yintercept =  floor(map.player.posy_p / map.wall_height) * map.wall_height;
    xintercept =  map.player.posx_p + (yintercept - map.player.posy_p) / tan(angle);
}
void    project_wall()
{
    int x;
    float len;
    float wallstripheight;

    x = 0;

    while (x < map.el.res_x)
    {
        len = map.ray[x].len ;
        printf("len = %f\n",len);
        wallstripheight = map.ray[x].wallstripheight;
        ft_line(x,(map.el.res_y / 2) - (wallstripheight / 2),wallstripheight,M_PI / 2,WHITE);
        //rec(x,(map.el.res_y / 2) - (wallstripheight / 2),1,wallstripheight);
        x++;
    }
}
