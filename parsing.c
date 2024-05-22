/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouboul <ebouboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:19:52 by ebouboul          #+#    #+#             */
/*   Updated: 2024/05/21 23:23:50 by ebouboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int tab_size(char *file)
{
    
    char *line;
    int size;
    int fd;
    fd = open(file, O_RDWR);
    line = get_next_line(fd);
    size = 0;
    if(!line)
    print_error("The map is empty or dosent exist", NULL, NULL);
    while (line)
    {
        free(line);
        size++;
        line = get_next_line(fd);
    }
    
    free(line);
    close(fd);
    return(size);
}


char **fill_lines(char *file)
{
    char **tab;
    char *map_line;
    int i;
    int fd;
    
    i = 0;
    tab = malloc(sizeof(char *) * (tab_size(file) + 1));
    fd = open(file, O_RDWR);
    map_line = get_next_line(fd);   
    while (map_line)
    {
       
        tab[i] = map_line;
        i++;
        map_line = get_next_line(fd);
    }
    free(map_line);
    tab[i] = NULL;
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
            print_error("Map must contain only 1 at the last line", tab, NULL);
        i++;
    }  
    while (j < size - 1)
    {
        if(tab[j][line_size] != '\n')
            print_error("The map lines are not same sized", tab, NULL);
        j++;
    }
      if(tab[size - 1][line_size ] != '\0' && tab[size - 1][line_size - 1] == '1')
            print_error("Map must contain only 1 at end", tab, NULL);
        char *full_line;
        full_line = malloc(sizeof(size * line_size) + 1);
        full_line[0] = 0;
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
            else if (map[i] != '0' && map[i] != '1' && map[i] != '\n') 
                print_error("Invalid character found", NULL, map);
            i++;
        }
        if (exits != 1)
        print_error(" Map must contain exactly one exit", NULL, map);
    if (collectibles < 1)
        print_error("Map must contain at least one collectible", NULL, map);
    if (player != 1)
        print_error("Map must contain exactly one starting position", NULL, map);
    free(map);
}
char **check_walls(char *file, int size)
{
    char **tab;
    int i;
    int j;
    t_point *playre;
    playre = malloc(sizeof(t_point));
    tab = fill_lines(file);
    i = 0;
    j = 0;
    while(tab[0][i] != '\n')
    {
        if(tab[0][i] != '1')
        print_error("Map must contain only 1 at the first line", tab, NULL);
        i++;
    }
    while (j < size)
    {
        if(tab[j][0] != '1' || tab[j][i - 1] != '1')
            print_error("Map must contain only 1 at the first an last of each line", tab, NULL);
        j++;
    }
    check_c0pe(check_nbline(tab, i, size));
    player_position(tab, &playre);
    flood_fill(tab, playre);
    return(tab);
}

