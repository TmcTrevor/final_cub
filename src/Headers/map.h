#ifndef FT_MAP_H
# define FT_MAP_H
#include "vector.h"
#include "player.h"
#include "array_list.h"
#include "sprite.h"
#include "cube3d.h"
#include "elements.h"
#include "texture.h"

typedef struct s_parser{
        //t_array_list lines;
        int             fd;
        int             line_nbr;
        int             column_nbr;
        int             pos_x_init;
        int             pos_y_init;
        int             dir;
        char            *data;
        char            *map_string;
        char            **grid;
        char            *map_string_clean;
        int             len;
        
       // t_map          *g_p;
        void (*get_lines)(struct s_parser *this);
        int (*get_fd)(char *filename);
        void  (*do_final)( struct s_parser *this);
        void (*free)(void *this);
}           t_parser;



typedef struct s_map
{
    //t_vector    *ppos; //player position
    int         WIN_WIDTH;
    int         WIN_HEIGHT;
    int         fd;
    char        *line;
    double      w;
    double      h;
    
    t_player    player;
    t_array_list errors;
    t_array_list walls;
    t_parser    *parser;
    t_spr       spr;
    t_elements  el;
    t_tex       tex;

   
    //t_array_list walls;



}               t_map;



typedef struct s_wall{
        t_vector  *pos;
        t_vector  *dir;
        int     kind;
}               t_wall;

void new_map(t_map *map, char *file_name);
t_wall *new_wall(t_vector *pos , t_vector *dir, int angle);

t_bool check_empty_line(char *line);
void get_lines(t_parser *this);
int get_fd(char *filename);

void new_parser(t_parser *this, char *filename , t_map *g_p);
///////// parser check//////
int		parse_main();
int             parse_line(int fd);
int             parse_map(int fd);
int             create_map();
int             check_borders_lines();
int             check_borders_columns();
int		create_good_size_map();
int             get_elements();
int             exit_all();
int             draw_map();
int             ft_key();
//oid  parser_do_final(t_parser *this);
//void   free_parser(void *this);
//void sprite_tex_parser(char *line);

#endif