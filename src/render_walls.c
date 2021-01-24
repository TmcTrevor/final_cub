#include "Headers/cube3d.h"
#include "Headers/ray.h"


void    render_ceiling(float top, int x)
{
    int e;

    e = -1;
    while (++e < top)
	{
		img.data[e * map.el.res_x + x] =  map.el.c_color_hex;
	   // e++;

	}
}
void    render_floor(float bot, int i)
{
    while(bot < map.el.res_y)
    {
        img.data[(int)bot *  map.el.res_x + i] = map.el.f_color_hex;
        bot++;    
    }
}
void    render_wall(float bot, float top,int x, float w_height,int t)
{
    float texx;
    float texy;
    int   y;
    int color;

    y = top;
    texx = map.ray[x].wasvertical ? map.ray[x].wallhity / map.wall_width :
        map.ray[x].wallhitx / map.wall_width;
    texx -= (int)texx;
    texx *= map.tex1[t].texwidth;
    while (y < bot)
    {
        /*texy = (y - ((map.el.res_y / 2)- (w_height / 2)))
            * ((float)map.tex1[t].texheight / w_height);*/
            
		int distancefromtop = y + (w_height / 2) - (map.el.res_y / 2);
						texy = distancefromtop * (float)(map.tex1[t].texheight / w_height);
        color = map.tex1[t].color[(int)texy * map.tex1[t].texwidth + (int)texx];
        img.data[y * map.el.res_x + x] = color;
        y++;
    }


}

int     set_t(int t, int x)
{
    if(map.ray[x].ray_down && !map.ray[x].wasvertical)
				t = 0;
	if(map.ray[x].ray_right && map.ray[x].wasvertical)
				t = 2;
	if(map.ray[x].ray_left && map.ray[x].wasvertical)
				t = 3;
    else
        t = 1;
    return (t);
}
void    project_wall()
{
    float wallstripheight;
    float wallTopPixel;
    float wallbottomPixel;
    float len;
    int x;
    int t;
    
    x = 0;
    t = 1;
    while (x <= map.el.nb_rays - 2)
    {
        len = map.ray[x].distance * cos(normalize_angle(map.ray[x].angle - map.player.rotation_angle - (M_PI / 6)));
		wallstripheight = floor((map.wall_height / len) * map.distanceProjPlane);
        wallTopPixel = (map.el.res_y / 2) - (wallstripheight / 2);
		wallTopPixel = (wallTopPixel < 0) ? 0 : wallTopPixel;
		wallbottomPixel = (map.el.res_y / 2) + (wallstripheight / 2);
		wallbottomPixel = (wallbottomPixel > map.el.res_y) ? map.el.res_y : wallbottomPixel;
       render_ceiling(wallTopPixel,x);
        t = set_t(t,x);
        //printf("%d\n",t);
        render_wall(wallbottomPixel,wallTopPixel,x,wallstripheight,t);
        render_floor(wallbottomPixel,x);
        
        x++;
    }
    ft_sprite();

}