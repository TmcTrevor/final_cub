#include "Headers/cube3d.h"

int		create_images2()
{
	if (!(map.tex1[3].color = mlx_xpm_file_to_image(mlx.mlx_ptr, map.el.e_path,
		&map.tex1[3].texwidth, &map.tex1[3].texheight)))
	{
		write(1, "Error\n", 6);
		write(1, "e wrong path texture", 20);
		//exit_all();
		return (exit_all());
	}
	 /*if (!(map.tex1[4].color = mlx_xpm_file_to_image(mlx.mlx_ptr, map.el.spr_path,
		&map.tex1[4].texwidth, &map.tex1[4].texheight)))
	{
		write(1, "Error\n", 6);
		write(1, "texture of the sprite is wrong", 30);
		return (exit_all());
	}*/
	return (1);
}

int		create_images1()
{
	if (!(map.tex1[0].color = mlx_xpm_file_to_image(mlx.mlx_ptr, map.el.n_path,
		&map.tex1[0].texwidth, &map.tex1[0].texheight)))
	{
		 write(1, "Error\n", 6);
		write(1, "n wrong path texture\n", 20);
		return (exit_all());
	}
	if (!(map.tex1[1].color = mlx_xpm_file_to_image(mlx.mlx_ptr, map.el.s_path,
		&map.tex1[1].texwidth, &map.tex1[1].texheight)))
	{
		write(1, "Error\n", 6);
		write(1, "s wrong path texture", 20);
		return (exit_all());
	}
	if (!(map.tex1[2].color = mlx_xpm_file_to_image(mlx.mlx_ptr, map.el.w_path,
		&map.tex1[2].texwidth, &map.tex1[2].texheight)))
	{
		write(1, "Error\n", 6);
		write(1, "w wrong path texture", 20);
		return (exit_all());
	}
	return (1);
}

int	initialize_texture()
{
	void	*text_n;
	void	*text_s;
	void	*text_e;
	void	*text_w;
    create_images1();
    create_images2();

map.tex1[0].color = (int*)mlx_get_data_addr(map.tex1[0].color,
		&img.bpp, &img.size_l, &img.bpp);
	map.tex1[1].color = (int*)mlx_get_data_addr(map.tex1[1].color,
		&img.bpp, &img.size_l, &img.bpp);
	map.tex1[2].color = (int*)mlx_get_data_addr(map.tex1[2].color,
		&img.bpp, &img.size_l, &img.bpp);
	map.tex1[3].color = (int*)mlx_get_data_addr(map.tex1[3].color,
		&img.bpp, &img.size_l, &img.bpp);
 // map.tex1[4].color = (int*)mlx_get_data_addr(map.tex1[4].color,
	//	&img.bpp, &img.size_l, &img.bpp); 
	return 1;
}
