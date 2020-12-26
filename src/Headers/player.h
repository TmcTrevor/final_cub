#ifndef FT_PLAYER_H
#define FT_PLAYER_H

//# include "array_list.h"
#include "vector.h"
#include "array_list.h"
typedef struct s_player{
   float				posx;
	 float				posy;
	 float			posx_p;
	 float 				posy_p;
	  float				dirx;
	  float				diry;
    float       rotation_angle;
    float       fov;
    float      rotation_speed;
    float      mov_speed;
    int         w_dir;
    int         t_dir;
    int         offset;
    float       planex;
    float       planey;
    //t_array_list collision;
    //t_array_list wall_rays;
   // t_array_list sprit_rays;
  //  t_array_list light_rays;

    //void (*update)(struct s_player *this);
    //void (*render)(struct s_player *this);
  //  void (*free)(void *item);
}       t_player;

typedef struct		s_big
{
	float				posx;
	float				posy;
	float				dirx;
	float				diry;
	float				planex;
	float				planey;
	float				camerax;
	float				raydirx;
	float				raydiry;
	unsigned int		mapx;
	unsigned int		mapy;
	float				sidedistx;
	float				sidedisty;
	float				deltadistx;
	float				deltadisty;
	float				perpwalldist;
	int					stepx;
	int					stepy;
	int					drawstart;
	int					drawend;
	int					wallheight;
	int					lineheight;
	int					side;
	float				movespeed;
	float				olddirx;
	float				rotspeed;
	float				oldplanex;
}					t_big;
typedef struct s_line {
    t_vector *pos;
    t_vector *dir;
}   t_line ;
int player_data();
//void  new_player(t_player *player, t_vector *pos);
//void  update_player(t_player *this);
//void  render_player(t_player *this);
//void  free_player(void *item);

#endif