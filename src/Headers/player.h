/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <mokhames@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:15:39 by mokhames          #+#    #+#             */
/*   Updated: 2021/01/24 18:15:40 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PLAYER_H
#define FT_PLAYER_H



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
	int			rl_dir;
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



int player_data();
//void  new_player(t_player *player, t_vector *pos);
//void  update_player(t_player *this);
//void  render_player(t_player *this);
//void  free_player(void *item);

#endif