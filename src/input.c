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
int fking_move()
{
    float move;
    map.player.rotation_angle += map.player.t_dir * map.player.rotation_speed;
    move = map.player.w_dir * map.player.mov_speed;
    int x;
    int y;
    int a;
    int b;
    a = (map.player.posx_p * map.parser->len )/ map.el.res_x; 
    b =  ( map.player.posy_p * map.parser->line_nbr )/ map.el.res_y;
    x = map.player.posx_p + (cos(map.player.rotation_angle+ M_PI / 6) * move);
    y = map.player.posy_p + (sin(map.player.rotation_angle+ M_PI / 6) * move);
    //x += 5 * map.player.w_dir;
    //y += 5 * map.player.w_dir;
    x = (x * map.parser->len )/ map.el.res_x;
    y = (y * map.parser->line_nbr )/ map.el.res_y;
    ft_printf("xx = %d ------ --- y = %d\n",x,y);
   /* if (a == x + map.player.w_dir)
        x +=  map.player.w_dir;
    if (b == y + map.player.w_dir)
        y +=  map.player.w_dir;*/
    ft_printf("x2 = %d ------ --- y2 = %d\n",x,y);
    if (map.parser->grid[b][x] != '1')
        map.player.posx_p += cos(map.player.rotation_angle + M_PI / 6) * move;
     if (map.parser->grid[y][a] != '1')
        map.player.posy_p += sin(map.player.rotation_angle + M_PI / 6) * move;
    
    return 0;
}
int ft_key(int key)
{
    ft_printf("key =%d\n",key);
    if (key == MLXK_ESC || key == MLXK_X)
		exit_all();
    printf("-----------%f\n",map.player.rotation_angle);
    key_press(key);
    
    fking_move();
    after_press(key);
    
    mlx_destroy_image(mlx.mlx_ptr,img.img_ptr);
    draw_map();
    return 0;
}