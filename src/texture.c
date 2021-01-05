#include "Headers/cube3d.h"

int		create_images2()
{
	if (!(map.tex.color_e = mlx_xpm_file_to_image(mlx.mlx_ptr, map.el.e_path,
		&map.tex.texwidth, &map.tex.texheight)))
	{
		write(1, "Error\n", 6);
		write(1, "e wrong path texture", 20);
		//exit_all();
		return (exit_all());
	}
	if (!(map.spr.spr_tex = mlx_xpm_file_to_image(mlx.mlx_ptr, map.el.spr_path,
		&map.spr.sprwidth, &map.spr.sprheight)))
	{
		write(1, "Error\n", 6);
		write(1, "texture of the sprite is wrong", 30);
		return (exit_all());
	}
	return (1);
}

int		create_images1()
{
	if (!(map.tex.color_n = mlx_xpm_file_to_image(mlx.mlx_ptr, map.el.n_path,
		&map.tex.texwidth, &map.tex.texwidth)))
	{
		write(1, "Error\n", 6);
		write(1, "n wrong path texture\n", 20);
		return (exit_all());
	}
	if (!(map.tex.color_s = mlx_xpm_file_to_image(mlx.mlx_ptr, map.el.s_path,
		&map.tex.texwidth, &map.tex.texheight)))
	{
		write(1, "Error\n", 6);
		write(1, "s wrong path texture", 20);
		return (exit_all());
	}
	if (!(map.tex.color_w = mlx_xpm_file_to_image(mlx.mlx_ptr, map.el.w_path,
		&map.tex.texwidth, &map.tex.texheight)))
	{
		write(1, "Error\n", 6);
		write(1, "w wrong path texture", 20);
		return (exit_all());
	}
	return (1);
}

void	initialize_texture()
{
	void	*text_n;
	void	*text_s;
	void	*text_e;
	void	*text_w;
    create_images1();
    create_images2();

map.tex.color_n = (int*)mlx_get_data_addr(map.tex.color_n,
		&img.bpp, &img.size_l, &img.bpp);
	map.tex.color_s = (int*)mlx_get_data_addr(map.tex.color_s,
		&img.bpp, &img.size_l, &img.bpp);
	map.tex.color_w = (int*)mlx_get_data_addr(map.tex.color_w,
		&img.bpp, &img.size_l, &img.bpp);
	map.tex.color_e = (int*)mlx_get_data_addr(map.tex.color_e,
		&img.bpp, &img.size_l, &img.bpp);
	map.spr.spr_tex = (int*)mlx_get_data_addr(map.spr.spr_tex,
		&img.bpp, &img.size_l, &img.bpp);

}


/*int		generate_textures(t_index *m)
{
	if (create_images1(m) < 0)
		return (exit_all(m));
	if (create_images2(m) < 0)
		return (exit_all(m));
	
	return (0);
}*/
