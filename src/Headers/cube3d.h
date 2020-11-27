#ifndef EXAMPLE_H
# define EXAMPLE_H

# include <math.h>
# include "mlx.h"
#include "../../ft_printf.h"
#include "fcntl.h"
#include "map.h"
#include "player.h"
#include "vector.h"
#include "../../GNL/get_next_line.h"
#include "array_list.h"
#include "ray.h"
#include "sprite.h"
#include "elements.h"
# define DEFAULT_WINDOW_X 2560
# define DEFAULT_WINDOW_Y 1395
# define MAP_GAME "0123NSEW"
# define PLAYER_INIT_POS "NSEW"
# define TILE_SIZE 1
# define ESC 53
# define UP 13
# define DOWN 1
# define RIGHT 2
# define LEFT 0
# define SPACE 49
# define SHIFHT 257
# define L_AROW 123
# define R_AROW	124
# define BLUE 255
# define RED 16711680
# define WHITE 16777215
# define BLACK 0
# define GREEN 65280
# define YELLOW 16776960
# define GREY 6579300
# define MOVE_SPEED 0.13
# define ROTATE_SPEED 2.7
# define FOV 60
# define RUN_SPEED 0.131
# define RUN_ROTATE_SPEED 2.72
# define STRAF_FACTOR 2
# define NB_TEXTURE 7
# define TEX_NO 0
# define TEX_SO 1
# define TEX_WE 2
# define TEX_EA 3
# define TEX_S 4
# define TEX_LIFE 5
# define TEX_SCOOP 6
# define TEXTURE_SIZE 663
# define FAC_UP 0
# define FAC_DOWN 1
# define FAC_LEFT 2
# define FAC_RIGHT 3
# define ARROW_UP 126
# define ARROW_DOWN 125
# define MLXK_ESC 53
# define MLXK_X 17
# define MLXK_W 13
# define MLXK_A 0
# define MLXK_S 1
# define MLXK_D 2
# define MLXK_LEFT 123
# define MLXK_RIGHT 124
# define MLXK_UP 126
# define MLXK_DOWN 125
# define MLXK_TD 14
# define MLXK_TG 12

/*
 Defines for the width and height of your window. I suggest you to do the same so
 you can change easily the size of your window later if needed.
*/
//int	WIN_WIDTH;
 //int	WIN_HEIGHT ;
//int fd;
//char *line;
/*
 Here I built a struct of the MLX image :
 It contains everything you need.
 - img_ptr to store the return value of mlx_new_image
 - data to store the return value of mlx_get_data_addr
 - the 3 other variables are pretty much useless, but you'll need
 them in the prototype of mlx_get_data_addr (see the man page for that)
 */


/*typedef struct s_player 
{
	float x;
	float y;
	float radius;
	float turn_direction;
	float run_direction;
	float rotate_angle;
	float movement_speed;
	float rotation_speed;
	float 


}		t_player;*/

typedef struct	s_img
{
	void		*img_ptr;
	int			*data; //Here you got an int * even though mlx_get_data_addr returns
						//a char *, i'll talk more about this in the .c file.
//Here are the 3 "useless" variables. You can find more informations about these in the man page.
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

/*
 Here is my main struct containing every variables needed by the MLX.
 - mlx_ptr stores the return value of mlx_init
 - win stores the return value of mlx_new_window
 - img will store everything we need for the image part, the struct is described above.
 */
typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win;
;
}				t_mlx;
void    dimension(t_map *map);
void    draw(void);
int     nie(int key,void *p);
t_mlx	mlx;
t_img 	img; 
//t_player *player;
int q;
t_player *player;
t_map map;





int 	start_game();
void	init_struct();
void	read_map(t_map *map);
void	ft_hello(t_mlx f,t_map *map,t_img l);
void	read_2d_map(t_map *map);
//void	ft_cube(int *x, int *y);
t_map	*new_game(t_map *map);
t_vector    *new_vec(t_vector *vec,int x,int y);
t_player  *new_player(t_player *player,t_vector *pos);
double  normelize_angel(double angle);
void image_put_pixel(int x, int y, int color);
void	line(int x0, int y0, int x1, int y1, int color);
double      ray_len(t_ray *ray);
void sub(t_vector *this, t_vector *o);



#endif
