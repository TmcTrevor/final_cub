#include "Headers/cube3d.h"
void new_parser(t_parser *this, char *filename, t_map *g_p)
{
    //new_array_list(&(this->lines), 7, sizeof(char *));
    //this->get_lines = &get_lines;
    this->get_fd = &get_fd;
    //this->do_final = &parser_do_final;
    //this->free = &free_parser;
    //this->g_p = g_p;
    this->fd = this->get_fd(filename);
    printf("%d\n",this->fd);
    //printf("%s",this->lines.arr[1]);
}

/*void get_lines(t_parser *this)
{
    char *line;
    int result;

    if (this->fd > -1)
    {
        while ((result = get_next_line(this->fd, &line)) > 0)
        {
            if (this->lines.push(&(this->lines), ft_strdup(line), sizeof(line)) != TRUE) 
                this->lines.free(&(this->lines), &free);
            free(line);
        }
        if (this->lines.push(&(this->lines),(void *) ft_strdup(line), sizeof(line)) != TRUE) 
            this->lines.free(&(this->lines), &free);
        free(line);
    }
    close(this->fd);
}*/

int get_fd(char *filename)
{
    int fd = -1;
    if (filename != NULL)
         fd = open(filename , O_RDONLY);
    return fd;
}
