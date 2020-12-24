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
     map.ray[x].horzwallhit = 0;
     map.ray[x].verwallhit = 0;       
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
/*void	line(int x0, int y0, int x1, int y1, int color)
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
}*/
void   draw_line(int x0, int y0, int x1, int y1, int color)
{
//Bresenham's Line Drawing Algorithm
  int dx =  abs (x1 - x0);
  int dy = -abs (y1 - y0);
  int sx = x0 < x1 ? 1 : -1;
  int sy = y0 < y1 ? 1 : -1;
  int p = dx + dy; //p step
  int p2;
  while(1)
  {
    //setPixel (x0,y0);
    //mlx_pixel_put(mlx, window, x0, y0, BLUE);
    img.data[y0 * map.el.res_x +  x0] = color;
    if (x0 == x1 && y0 == y1)
        break;
    p2 = 2 * p;
    if (p2 >= dy)
    {
        p += dy;
        x0 += sx;
    } // e_xy+e_x > 0
    if (p2 <= dx)
    {
        p += dx;
        y0 += sy;
    }  //e_xy+e_y < 0
  }
  //mlx_put_image_to_window(mlx, window, img, 0, 0);
}
float    fline(int x, int y, int x1,int y1,float angle, int color)
{
    float r = 0;
    int or_x = x;
    int or_y = y;
	int i;
	int j;
	//printf("1\n");
	i = 0;

	j = 0;
	//ft_printf("len = %d --------- line =%d\n",map.parser->len, map.parser->line_nbr);
    while (x != x1 && y != y1)
    {
        x = or_x + (r * cos(angle));
        y = or_y + (r * sin(angle));
	
		//ft_printf("i = %d ---------- j =%d\n",i, j);
		//if (img.data[(int)(y *map.el.res_x + x)] == GREEN|| x > map.el.res_x || y > map.el.res_y )
		//	break;
	 	img.data[(int)(y * map.el.res_x + x)] =  color;
    img.data[(int)(y * map.el.res_x + x)] =  color;
		
		
		
        r++;
    }
	double a;
	a = distance(or_x,or_y,x,y);
	//r /= 0.2;
	return r;
	//printf("-----------------------------------------------------------%d\n",r);
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
    
 printf("down = %d\n",map.ray[x].ray_down);
 printf("up = %d\n",map.ray[x].ray_up);
 printf("right = %d\n",map.ray[x].ray_right);
 printf("left = %d\n",map.ray[x].ray_left);
}

int     is_wall2(int a, int b)
{
    a = floor(a / map.wall_width);
    b = floor(b / map.wall_height);
    if (a < 0 || b < 0 || a > map.parser->len - 1 || b > map.parser->line_nbr - 1 )
        return 0;
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
    yintercept += (map.ray[x].ray_down ) ? map.wall_height : 0;
    
    xintercept =  map.player.posx_p + (yintercept - map.player.posy_p) / tan(angle);
    //printf("x = %d\ny = %d\n",xintercept,yintercept);
   //img.data[yintercept * map.el.res_x + xintercept] = RED;
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
       //  if (map.ray[x].ray_up)
      //nexty--; 
      if (is_wall2(nextx,nexty))
      {
        //wall_hit = true;
        map.ray[x].horzwallhit = 1;
        map.ray[x].h_wallhitx = nextx;
        map.ray[x].h_wallhity = nexty;
//img.data[yintercept * map.el.res_x + xintercept] = RED;
      draw_line(map.player.posx_p,map.player.posy_p,nextx,nexty, RED);
     // fline(map.player.posx_p,map.player.posy_p,nextx,nexty,angle,RED);
      // int e =(int)distance(map.player.posx_p,map.player.posy,nextx, nexty);
  
          //img.data[nexty * map.el.res_x + nextx] = BLUE;
     
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
void  cast_vertical_inter_ray(float angle, int x)
{
    int xintercept;
    int yintercept;
    int xstep;
    int ystep;
    int nextx;
    int nexty;
    //line(map.player.posx_p,map.player.posy_p,0,0,RED);
    xintercept =  floor(map.player.posx_p / map.wall_width) * map.wall_width;
    xintercept += (map.ray[x].ray_right) ? map.wall_width : 0;
 
    yintercept =  map.player.posy_p + (xintercept - map.player.posx_p) * tan(angle);
    //printf("x = %d\ny = %d\n",xintercept,yintercept);
   // img.data[yintercept * map.el.res_x + xintercept] = BLUE;
    xstep =  map.wall_width;
    xstep *= map.ray[x].ray_left ? -1 : 1;
    
    ystep = xstep * tan(angle);
    ystep *= (map.ray[x].ray_up && ystep > 0) ? -1 : 1;
    ystep *= (map.ray[x].ray_down && ystep < 0)? -1 : 1;
    nextx = xintercept;
    nexty = yintercept;//
 
   // img.data[nexty * map.el.res_x + nextx] = BLUE;
    if (map.ray[x].ray_left)
      nextx--;
    while(nextx >= 0 && nextx < map.el.res_x && nexty >=0 && nexty < map.el.res_y)
    {
      // if (map.ray[x].ray_left)
      //nextx--;
      
      if (is_wall2(nextx,nexty))
      {
         map.ray[x].verwallhit = 1;
        map.ray[x].v_wallhitx = nextx;
        map.ray[x].v_wallhity = nexty;
     // fline(map.player.posx_p,map.player.posy_p,nextx,nexty,angle,RED);
      // int e =(int)distance(map.player.posx_p,map.player.posy,nextx, nexty);
   // draw_line(map.player.posx_p,map.player.posy_p,nextx,nexty, RED);
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
void  check_distance(int x, float angle)
{
    int p1;
    int p2;
    if (map.ray[x].horzwallhit)
      p1 =distance(map.player.posx_p,map.player.posy_p,map.ray[x].h_wallhitx,map.ray[x].h_wallhity);
    else
      p1 = 3000;
    if (map.ray[x].verwallhit)
    p2 = distance(map.player.posx_p,map.player.posy_p,map.ray[x].v_wallhitx,map.ray[x].v_wallhity);
    else
    p2 = 3000;
    map.ray[x].distance = (p1 < p2) ? p1 : p2;
    map.ray[x].wallhitx = (p1 < p2) ? map.ray[x].h_wallhitx : map.ray[x].v_wallhitx;
    map.ray[x].wallhity = (p1 < p2) ? map.ray[x].h_wallhity : map.ray[x].v_wallhity;
    map.ray[x].wasvertical = (p1 < p2) ? 0 : 1;
   // fline(map.player.posx_p,map.player.posy_p,map.ray[x].wallhitx,map.ray[x].wallhity,angle,RED);
    //draw_line(map.player.posx_p,map.player.posy_p,map.ray[x].wallhitx,map.ray[x].wallhity, RED);
  
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
