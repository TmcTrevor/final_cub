#include "Headers/cube3d.h"


int key_press(int key)
{
    if (key == MLXK_W || key == MLXK_UP)
        map.player.w_dir = 1;
	if (key == MLXK_S || key == MLXK_DOWN)
        map.player.w_dir = -1;
	if (key == MLXK_RIGHT)
        map.player.t_dir = 1;
	if (key == MLXK_LEFT)
        map.player.t_dir = -1;
        
 //printf("-----------%f\n",map.player.t_dir);
    return 0;

}
void    reset_ray2()
{
    int x;

    x = 0;
    while(x < map.el.nb_rays)
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
}
int after_press(int key)
{
    if (key == MLXK_W || key == MLXK_UP)
        map.player.w_dir = 0;
	if (key == MLXK_S || key == MLXK_DOWN)
        map.player.w_dir = 0;
	if (key == MLXK_RIGHT)
        map.player.t_dir = 0;
	if (key == MLXK_LEFT)
        map.player.t_dir = 0;
        
 //printf("-----------%f\n",map.player.t_dir);
    return 0;


}
int     is_wall(int a, int b)
{
    if (a < 0 || b < 0 || a > map.parser->len || b > map.parser->line_nbr )
        return 0;
    if (map.parser->grid[b][a] != '1')
        return 1;
    return 0;
}
int fking_move()
{
    float move;
    map.player.rotation_angle += map.player.t_dir * map.player.rotation_speed;
    move = map.player.w_dir * map.player.mov_speed ;
    int x;
    int y;
    int a;
    int b;
    //printf("angle = %f\n",map.player.rotation_angle);
    a = floor(map.player.posx_p / map.wall_width); 
    b =  floor(map.player.posy_p / map.wall_height);
    x = (map.player.posx_p + (cos(map.player.rotation_angle+ M_PI / 6) * move) * 0.2) + 3;
    y = (map.player.posy_p + (sin(map.player.rotation_angle+ M_PI / 6) * move) * 0.2) + 3;
    //x += 5 * map.player.w_dir;
    //y += 5 * map.player.w_dir;
    //printf("x1_P = %f ------ --- x2_P = %f\n",map.player.posx_p,map.player.posy_p);
    //ft_printf("x2_P = %d ------ --- x2_P = %d\n",x,y);

    x = floor(x / map.wall_width) ;
    y = floor(y /map.wall_height) ;
     
   // ft_printf("x = %d ------ --- b = %d ------ %c \n",x,b);
   /* if (a == x + map.player.w_dir)
        x +=  map.player.w_dir;
    if (b == y + map.player.w_dir)
        y +=  map.player.w_dir;*/
   //ft_printf("a = %d ------ --- y = %d\n",x,y);

   // 
    if (is_wall(x,b))
    //{
        map.player.posx_p += ((cos(map.player.rotation_angle + M_PI / 6) * move)) * 0.2;
      ///  printf("3\n");
    //}
    if (is_wall(a,y)) 
        map.player.posy_p += ((sin(map.player.rotation_angle + M_PI / 6) * move))* 0.2;
      //  printf("5\n");
     //}
    
    return 0;
}
int ft_key(int key)
{
    ft_printf("key =%d\n",key);
    if (key == MLXK_ESC || key == MLXK_X)
		exit_all();
    //printf("-----------%f\n",map.player.rotation_angle);
    key_press(key);
    
    fking_move();
   //reset_ray2();
    after_press(key);
    
    mlx_destroy_image(mlx.mlx_ptr,img.img_ptr);
    draw_map();
    return 0;
}