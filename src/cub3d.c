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
	mlx.win = mlx_new_window(mlx.mlx_ptr, 500, 500, "TreVor");
	
	return 1;
 
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
	 
	 start_game();
	//mlx.y = 0;
	//mlx_hook(mlx.win,2,1, nie, (void *) 0);
	//mlx_loop_hook(mlx.mlx_ptr,xd, (void *) 0);
	//mlx_loop(mlx.mlx_ptr);
	return (0);
}
