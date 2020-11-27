#include "Headers/cube3d.h"

static void		*ft_memalloc(size_t size)
{
	void	*mem;

	if (!(mem = malloc(size)))
		return (NULL);
	ft_bzero(mem, size);
	return (mem);
}
int 	update(int key)
{return 1;}



int	start_game()
{
 	init_struct();
	if(parse_main() < 0)
		return -1;
	if (!(mlx.mlx_ptr = mlx_init()))
		return -1;
	player_data();
	printf("2 ----- %f\n",map.player.rotation_speed);
	mlx.win = mlx_new_window(mlx.mlx_ptr, map.el.res_x, map.el.res_y, "TreVor");
	img.img_ptr = mlx_new_image(mlx.mlx_ptr, map.el.res_x, map.el.res_y);
	img.data = (int *)mlx_get_data_addr(img.img_ptr, &img.bpp,
		&img.size_l, &img.endian);
	ft_printf("line %d\n",map.parser->line_nbr);
	draw_map();
	//ray_casting();
	
	return 1;
 
}
int		red_button()
{
	mlx_destroy_window(mlx.mlx_ptr,mlx.win);

	exit_all();
	return 0;

}

int	main(int argc, char **argv)
{
	
	//int op = open("map", O_RDONLY);
	//char *line;
	//t_map map;
	//if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
	//	return 0;

	q = 0;
	//img.op = 220;
    if (argc != 2)
		exit(1);
	 new_map(&map,argv[1]);
	 
	if(start_game() < 0)
		exit_all();
	//mlx.y = 0;
	mlx_hook(mlx.win,2,1L >> 1, ft_key, (void *) 0);
	mlx_hook(mlx.win,17,0, red_button, (void *) 0);

	//mlx_loop_hook(mlx.mlx_ptr,xd, (void *) 0);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
