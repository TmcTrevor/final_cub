/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <mokhames@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:15:39 by mokhames          #+#    #+#             */
/*   Updated: 2021/01/25 07:53:05 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PLAYER_H
# define FT_PLAYER_H

typedef struct			s_player
{
	float				posx;
	float				posy;
	float				posx_p;
	float				posy_p;
	float				dirx;
	float				diry;
	float				rotation_angle;
	float				fov;
	float				rotation_speed;
	float				mov_speed;
	int					w_dir;
	int					t_dir;
	int					rl_dir;
	int					offset;
	float				planex;
	float				planey;
}						t_player;

int						player_data();

#endif
