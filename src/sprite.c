#include "Headers/cube3d.h"

void init_spr()
{
	int i;
	int us;

	i = 0;
	if (!(map.spr = malloc(sizeof(t_spr) * (map.numsprites + 1))))
		return;
	while (i < map.numsprites)
	{
		if (!(map.spr[i] = malloc(sizeof(t_spr))))
			return;
		map.spr[i]->ptr = mlx_xpm_file_to_image(mlx.mlx_ptr, map.el.spr_path,
												&map.tex1[4].texwidth, &map.tex1[4].texheight);
		map.spr[i]->data = (int *)mlx_get_data_addr(map.spr[i]->ptr,
													&us,
													&us,
													&us);
		i++;
	}
	map.spr[i] = NULL;
}

void sprite_sort(void)
{
	int i;
	int j;
	t_spr *tmp;

	i = 0;
	while (i < map.numsprites)
	{
		j = 0;
		while (j < map.numsprites - i - 1)
		{
			if (map.spr[j]->distance <= map.spr[j + 1]->distance)
			{
				tmp = map.spr[j];
				map.spr[j] = map.spr[j + 1];
				map.spr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
void update_sprite(void)
{
	int i;
	int j;
	int spt_id;
	//float sp_angle;

	i = -1;
	spt_id = 0;
	while (++i < map.parser->line_nbr)
	{
		j = -1;
		while (++j < map.parser->len)
		{
			
			if (map.parser->grid[i][j] == '2')
			{
				//printf("%d\n",2);
				map.spr[spt_id]->y = (i * map.wall_width) + map.wall_width / 2;
				map.spr[spt_id]->x = (j * map.wall_width) + map.wall_width / 2;
				map.spr[spt_id]->distance = distance(
					map.spr[spt_id]->x, map.spr[spt_id]->y,
					map.player.posx_p, map.player.posy_p);
				//sp_angle = map.player.rotation_angle + (M_PI / 6) - sp_angle;
				spt_id++;
			}
		}
	}
	sprite_sort();
}

void			render_sprite(int k, float x_fs, float y_fs, int sp_size)
{
	int			i;
	int			j;
	int			color;
	int x;
	int y;

	i = -1;
	while (++i < sp_size)
	{
		if (x_fs + i < 0 || y_fs + i > map.el.res_y)
			continue ;
		if (x_fs + i < map.el.res_x )
			if (map.ray[(int)x_fs + i].distance > map.spr[k]->distance)
				continue;
		j = -1;
		while (++j < sp_size)
		{
           
			if (y_fs + j < 0 || y_fs + j > map.el.res_y)
				continue ;
			color = map.spr[k]->data[map.tex1[4].texwidth * (j *
					map.tex1[4].texheight / sp_size) +
				(i * map.tex1[4].texwidth / sp_size)];
				
			x = (x_fs + i);
			y = (y_fs + j);
			if (color)
				img.data[(y) * map.el.res_x + x] = color;
		}
		//printf("%d\n",x_fs +i);
	}
}
void	reset_spr(int id)
{
	map.spr[id]->x = 0;
	map.spr[id]->y = 0;
	map.spr[id]->distance = 0;
}

void			sprite_data(int spt_id)
{
	float		x_offset;
	float		y_offset;
	float		sp_angle;
	float		sp_size;

    map.player.rotation_angle = normalize_angle(map.player.rotation_angle);
	sp_angle = atan2((map.spr[spt_id]->y) - map.player.posy_p,
			(map.spr[spt_id]->x) - map.player.posx_p);
	if (sp_angle - map.player.rotation_angle + (M_PI / 6)  > M_PI)
		sp_angle -= 2 * M_PI;
	if (sp_angle - map.player.rotation_angle + (M_PI / 6) < -M_PI)
		sp_angle += 2 * M_PI;
	//if (sp_angle - map.player.rotation_angle + (M_PI / 6) > M_PI)

		
	sp_size = (map.el.res_x / map.spr[spt_id]->distance) * map.wall_width;
	x_offset = (sp_angle - map.player.rotation_angle + M_PI / 6) / 
		FOV_ANGLE * map.el.res_x + (map.el.res_x / 2 - sp_size / 2);
	y_offset = ((map.el.res_y / 2) - (sp_size / 2));
	//if (x_offset + sp_size && y_offset)
		render_sprite(spt_id, x_offset, y_offset, sp_size);
	//reset_spr(spt_id);
}

/*void calc_x_start(int i)
{
	float sp_angle;
	float pixel_num;
	float rotation;
	sp_angle = normalize_angle(atan2(map.spr[i]->y - map.player.posy_p,
								 map.spr[i]->x - map.player.posx_p));
	rotation = normalize_angle(map.player.rotation_angle);
	//printf("%f    |%f    |", sp_angle, rotation);
	sp_angle = sp_angle - rotation;
	//printf("%f\n", sp_angle);
	// if (sp_angle > M_PI)
	// 	sp_angle -= 2 * M_PI;
	// else if (sp_angle < -M_PI)
	// 	sp_angle += 2 * M_PI;
	//sp_angle = normalize_angle(sp_angle);
	pixel_num = (float)FOV_ANGLE / (float)map.el.res_x;
	map.util.x_star = sp_angle / pixel_num;
}
void befor_draw(int i)
{
	map.util.height = map.distanceProjPlane * (map.wall_width / map.spr[i]->distance);
	map.util.y_star = (map.el.res_y / 2) - (map.util.height / 2);
	map.util.y_star = map.util.y_star < 0 ? 0 : map.util.y_star;
	map.util.y_end = (map.el.res_y / 2) + (map.util.height / 2);
	map.util.y_end = map.util.y_end >= map.el.res_y ? map.el.res_y : map.util.y_end;
	calc_x_start(i);
	map.util.x_star = map.util.x_star - (map.util.height / 2);
	map.util.x_end = map.util.x_star + map.util.height;
}
void draw_sprite(int i)
{
	int trp;
	float tex_x;
	float tex_y;
	int y;
	int color;
	int d;

	trp = map.util.x_star;
	while (trp < map.util.x_end && map.util.x_star < map.el.res_x)
	{
		tex_x = (trp - map.util.x_star) % 64 ;
		y = map.util.y_star;
		if (trp >= 0 && trp < map.el.res_x &&
			map.spr[i]->dist2 < map.ray[trp].distance)
		{
			while (y < map.util.y_end)
			{
				d = y + (map.util.height / 2) - (map.el.res_y / 2);
				tex_y = ( d * ((map.wall_width * 1.0) / map.util.height)) / 0.2;
			//printf("%d  | %d  \n", tex_y, tex_x);
				//printf("%d\n", y);
			//printf("%d", map.spr[i]->data[64 * (int)tex_y + (int)tex_x]);
				if (map.spr[i]->data[64 * (int)tex_y + (int)tex_x] != 0)
					img.data[y * map.el.res_x + trp] = map.spr[i]->data[64 * (int)tex_y + (int)tex_x];
				y++;
			}
		}
		trp++;
	}
	printf("%d   | %d\n", map.util.y_star ,map.util.y_end);
}*/

void ft_sprite(void)
{
	int id;

	id = -1;
	//printf(" num = %d\n", map.numsprites);
	update_sprite();
	
	while (++id < map.numsprites)
	{	sprite_data(id);
		/*for (int k = 0; k < (64*64); k++){
			printf("%d   ", map.spr[id]->data[k]);
		}
		befor_draw(id);
		draw_sprite(id);*/
	}
}