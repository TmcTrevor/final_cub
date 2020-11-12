#include "Headers/cube3d.h"


static void		*ft_memalloc(size_t size)
{
	void	*mem;

	if (!(mem = malloc(size)))
		return (NULL);
	ft_bzero(mem, size);
	return (mem);
}
void new_map(t_map *map, char *file_name)
{
   map->parser = (t_parser *)ft_memalloc(sizeof(t_parser));
   map->h= 0.0f;
   map->w = 0.0f;
   //map->bi = 0;
   new_array_list(&(map->errors), 10, sizeof(char *));
    new_array_list(&(map->walls), 10, sizeof(t_wall));
    //new_array_list(&(map->sprites), 10, sizeof(t_sprites));
    //new_array_list(&(map->lights), 10, sizeof(t_sprites));
    //new_array_list(&map->allocated_sp_tex, 2, sizeof(t_sp_texture));
    //new_array_list(&map->allocated_tex, 4, sizeof(t_texture));
    new_parser(map->parser, file_name ,map);
   //map->exit = &__exit_;
   //map->to_string = &game_to_string;
   //map->free = &free_game;
  // map->parser->do_final(map->parser);
    
  //  if (map->errors.index > 0)
   //  map->exit(map, NULL);
  
    //map->parser->free(map->parser);pl
    //free(map->parser);
}