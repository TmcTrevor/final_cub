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
void	line(int x0, int y0, int x1, int y1, int color)
{
	int		dx;
	int		dy;
	float		steps;
	float	xinc;
	float	yinc;
	int		i;

	dx = x1 - x0;
	dy = y1 - y0;
	steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
 // steps = fmax(dx, dy);
  xinc = dx / (float)steps;
	yinc = dy / (float)steps;
	i = -1;
	while (++i <= steps)
	{
    img.data[y0 *  map.el.res_x + x0] = color;
		x0 += xinc;
		y0 += yinc;
	}
}
void  reset_ray(int x)
{
     map.ray[x].ray_down = 0;
     map.ray[x].ray_up = 0;
     map.ray[x].ray_right = 0;
     map.ray[x].ray_left = 0;   
}
void  check_angle(float angle,int x)
{
  if (angle > 0 && angle < M_PI)
      map.ray[x].ray_down = 1;
  else
      map.ray[x].ray_up = 1;
  if (angle < M_PI / 2 || angle  > ((3 * M_PI) / 2))
    map.ray[x].ray_right = 1;
  else
      map.ray[x].ray_left = 1;
    
 
}

int     is_wall2(int a, int b)
{
    a = floor(a / map.wall_width);
    b = floor(b / map.wall_height);
    if (a < 0 || b < 0 || a > map.parser->len || b > map.parser->line_nbr )
        return 1;
    if (map.parser->grid[b][a] == '1')
        return 1;
    return 0;
}
void  cast_horizontal_inter_ray(float angle, int x)
{
    int xintercept;
    int yintercept;
    int xstep;
    int ystep;
    int nextx;
    int nexty;
    //line(map.player.posx_p,map.player.posy_p,0,0,RED);
    yintercept =  floor(map.player.posy_p / map.wall_height) * map.wall_height;
    yintercept += map.ray[x].ray_down;
 
    xintercept =  map.player.posx_p + (yintercept - map.player.posy_p) / tan(angle);
    //printf("x = %d\ny = %d\n",xintercept,yintercept);
   // img.data[yintercept * map.el.res_x + xintercept] = BLUE;
    ystep =  map.wall_height;
    ystep *= map.ray[x].ray_up ? -1 : 1;
    
    xstep = ystep / tan(angle);
    xstep *= (map.ray[x].ray_left && xstep > 0) ? -1 : 1;
    xstep *= (map.ray[x].ray_right && xstep < 0)? -1 : 1;
    nextx = xintercept;
    nexty = yintercept;
    if (map.ray[x].ray_up)
      nexty--;
    while(nextx >= 0 && nextx < map.el.res_x && nexty >=0 && nexty < map.el.res_y)
    {
      
      if (is_wall2(nextx,nexty))
      {
     // line(map.player.posx_p,map.player.posy_p,nextx,nexty,RED);
      // int e =(int)distance(map.player.posx_p,map.player.posy,nextx, nexty);
  
          img.data[nexty * map.el.res_x + nextx] = BLUE;
     
      // printf("x = %d\ny = %d\n",nextx,nexty);
       //ft_line(map.player.posx_p ,map.player.posy_p ,e,angle,RED);
        break;
      }
      else
        {
          nextx += xstep;
          nexty += ystep;
        }
    }

    
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
