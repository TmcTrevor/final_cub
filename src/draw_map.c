#include "Headers/cube3d.h"

void	ft_cube(int x, int y)
{
	int i;
	int j;
	int a;
	//ft_printf("%d\n",map.parser->line_nbr);
	//x *= (map.el.res_x / map.parser->line_nbr) ;
	//y *= (map.el.res_y / map.parser->column_nbr);
	i = x + (map.el.res_x / map.parser->len);
	a = y + (map.el.res_y / map.parser->line_nbr);
	
	j = y;
	while (x <= i)
	{
		y = j;
		while (y <= a)
		{
			img.data[(y * map.el.res_x + x)] =0x00ff00;
			y++;
		}
		x++;

	}
}
/*void	draw_fov()
{
	float angle;
	float step;
	int x ;
	x = 0;
	step = M_PI / 180;
	angle = map.player.rotation_angle - M_PI /3;
	while(x < map.el.res_x)
	{
		ft_line(map.player.posx_p,map.player.posy_p,2000,angle,BLUE);
		angle += step;
		x++;
	}
}*/
float    ft_line( int x, int y, int size ,float angle, int color)
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
    while (r < size)
    {
        x = or_x + (r * cos(angle));
        y = or_y + (r * sin(angle));
	
		//ft_printf("i = %d ---------- j =%d\n",i, j);
		if (img.data[(int)(y *map.el.res_x + x)] == GREEN || x > map.el.res_x || y > map.el.res_y)
			break;
	 	img.data[(int)(y * map.el.res_x + x)] =  color;
		
		
	
        r++;
    }
	return r;
	//printf("-----------------------------------------------------------%d\n",r);
}
void	draw_fov()
{
	double angle;
	float step;
	int x ;
	x = 0;
	step = M_PI / 180;
	angle = 0;
	angle = map.player.rotation_angle;
	while(x < map.el.res_x - 2)
	{
		
		map.ray[x].len = ft_line(map.player.posx_p,map.player.posy_p,2000,angle,BLUE);
		map.ray[x].posx = map.player.posx_p;
		map.ray[x].posy = map.player.posy_p;
		map.ray[x].angle = angle;
		//cast_ray();
		
		angle += (M_PI / 3) / map.el.res_x;
		x++;
	}
	
}
void	draw_dir()
{
	float angle;
	angle = map.player.rotation_angle + M_PI /6;
	ft_line(map.player.posx_p,map.player.posy_p,2000,angle,RED);
}
int draw_player()
{
	float angle;
	int x;
	angle = 0;
	int radius = 10;
	float step = M_PI / 180;
	while (angle <= (2 * M_PI))
	{
		ft_line(map.player.posx_p,map.player.posy_p,radius,angle,BLUE);
		 angle += step;
	}
	draw_fov();
	draw_dir();
	return (1);
}
int draw_map()
{
	int i;
	int j;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	j = 0;
	img.img_ptr = mlx_new_image(mlx.mlx_ptr, map.el.res_x, map.el.res_y);
	img.data = (int *)mlx_get_data_addr(img.img_ptr, &img.bpp,
		&img.size_l, &img.endian);
   while(map.parser->grid[i])
	{
		j = 0;
		x = 0;
		while(map.parser->grid[i][j])
		{
			if(map.parser->grid[i][j] == '1')
			{
				
				ft_cube(x,y);
				 x += (int)(map.el.res_x / map.parser->len ); 
				//j++;
				
			}
			if(map.parser->grid[i][j] == '0' || map.parser->grid[i][j] == ' ')
			 { 
				 x += (map.el.res_x / map.parser->len);
			}
			/*else // sprite;
			{
			 
				x += (int) (map.el.res_x / map.parser->len); 
			}*/
		

			j++;
		}
		y += (int)(map.el.res_y / map.parser->line_nbr);
		i++;

	}
	draw_player();
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, img.img_ptr, 0, 0);
	

    return (1);
}