/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouboul <ebouboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:08:16 by ebouboul          #+#    #+#             */
/*   Updated: 2024/05/16 12:35:26 by ebouboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

// typedef struct 	s_point {
// 	int			x;				// x : Width  | x-axis
// 	int			y;				// y : Height | y-axis
// }				t_point;
 
// void	fill(char **tab, t_point size, t_point cur, char to_fill)
// {
// 	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
// 		|| tab[cur.y][cur.x] != to_fill)
// 		return;

// 	tab[cur.y][cur.x] = 'F';
// 	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
// 	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
// 	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
// 	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
// }

// void	flood_fill(char **tab, t_point size, t_point begin)
// {
// 	fill(tab, size, begin, tab[begin.y][begin.x]);
// }

void print_error(const char *str)
{
    write(2, str, ft_strlen(str));
    write(2, "\n", 1);
    exit(1);
}

int tab_size(char *file)
{
    
    char *line;
    int size;
    int fd;
    fd = open(file, O_RDWR);
    line = get_next_line(fd);
    size = 0;
    if(!line)
    print_error("The map is empty");
    while (line)
    {
        size++;
        line = get_next_line(fd);
    }
    
    free(line);
    close(fd);
    return(size);
}
char **fill_lines(char *file,int fd)
{
    char **tab;
    char *map_line;
    int i;

    i = 0;
    tab = NULL;
    tab = malloc(sizeof(char *) * (tab_size(file) + 1));
    fd = open(file, O_RDWR);
    map_line = get_next_line(fd);   
    while (map_line)
    {
       
        tab[i] = map_line;
        i++;
        map_line = get_next_line(fd);
    }
    // t_point size;
    // t_point begin;
    // size.x = 6;
    // size.y = 35;
    // begin.x = 5;
    // begin.y = 1;
    // flood_fill(tab, size, begin);
    // int k = 0;
    // while (tab[k])
    // {
    //     printf("%s", tab[k++]);
    // }
    
    return tab;
}

char *check_nbline(char **tab, int line_size, int size)
{
    int j;
    j = 0;
    int i;
    i = 0;
    while(i < line_size)
    {
        if(tab[size - 1][i] != '1')
        print_error("Map must contain only 1 at the last line");
        i++;
    }  
    while (j < size - 1)
    {
        if(tab[j][line_size] != '\n')
       print_error("The map lines are not same sized");
        j++;
    }
      if(tab[size - 1][line_size ] != '\0' && tab[size - 1][line_size - 1] == '1')
        print_error("Map must contain only 1 at end");
        char *full_line;
        full_line = malloc(sizeof(size * line_size) + 1);
        int k = 0;
        while(k < size)
        full_line = ft_strjoin(full_line, tab[k++]);
        return(full_line);
} 
void check_c0pe(char *map)
{
    int exits = 0;
    int collectibles = 0;
    int player = 0;

    int i = 0;
        while (map[i])
        {
            if (map[i] == 'E')
                exits++;
            else if (map[i] == 'C')
                collectibles++;
            else if (map[i] == 'P')
                player++;
            else if (map[i] != '0' && map[i] != '1' && map[i] != '\n') {
                print_error("Invalid character found");
            }
            i++;
        }
        if (exits != 1)
       print_error(" Map must contain exactly one exit");
    if (collectibles < 1)
        print_error("Map must contain at least one collectible");
    if (player != 1)
        print_error("Map must contain exactly one starting position");
    free(map);
}
void check_walls(char *file,int fd, int size)
{
    char **tab;
    int i;
    int j;
    tab = fill_lines(file,fd);
    i = 0;
    j = 0;
    while(tab[0][i] != '\n')
    {
        if(tab[0][i] != '1')
      print_error("Map must contain only 1 at the first line");
        i++;
    }
    while (j < size)
    {
        if(tab[j][0] != '1' || tab[j][i - 1] != '1')
        print_error("Map must contain only 1 at the first an last of each line");
        j++;
    }
    check_c0pe(check_nbline(tab, i, size));
}



int main(int ac, char **av)
{
    if(ac != 2)
        return(0);
    else
    {
        int fd;
        int i;
        i = tab_size(av[1]);
        
        fd = open(av[1], O_RDWR);
        
        check_walls(av[1],fd, i);
    }
}


