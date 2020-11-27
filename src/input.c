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
    move = map.player.w_dir * map.player.mov_speed;
    int x;
    int y;
    int a;
    int b;
    //printf("angle = %f\n",map.player.rotation_angle);
    a = (map.player.posx_p * map.parser->len )/ map.el.res_x; 
    b =  ( map.player.posy_p * map.parser->line_nbr )/ map.el.res_y;
    x = map.player.posx_p + (cos(map.player.rotation_angle+ M_PI / 6) * move);
    y = map.player.posy_p + (sin(map.player.rotation_angle+ M_PI / 6) * move);
    //x += 5 * map.player.w_dir;
    //y += 5 * map.player.w_dir;
    printf("x1_P = %f ------ --- x2_P = %f\n",map.player.posx_p,map.player.posy_p);
    ft_printf("x2_P = %d ------ --- x2_P = %d\n",x,y);

    x = (x * map.parser->len )/ map.el.res_x;
    y = (y * map.parser->line_nbr )/ map.el.res_y;
     
    ft_printf("x1 = %d ------ --- x2 = %d\n",a,b);
   /* if (a == x + map.player.w_dir)
        x +=  map.player.w_dir;
    if (b == y + map.player.w_dir)
        y +=  map.player.w_dir;*/
    ft_printf("x2 = %d ------ --- y2 = %d\n",x,y);
    
    if (is_wall(x,b))
    //{
        map.player.posx_p += cos(map.player.rotation_angle + M_PI / 6) * move;
      ///  printf("3\n");
    //}
    if (is_wall(a,y)) 
        map.player.posy_p += sin(map.player.rotation_angle + M_PI / 6) * move;
      //  printf("5\n");
     //}
    
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