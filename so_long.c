/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouboul <ebouboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:08:16 by ebouboul          #+#    #+#             */
/*   Updated: 2024/05/13 17:35:19 by ebouboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int tab_size(char *file)
{
    
    char *line;
    int size;
    int fd;
    fd = open(file, O_RDWR);
    line = get_next_line(fd);
    size = 0;
     
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

    return tab;
}
void check_nbline(char **tab, int line_size, int size)
{
    int j;
    j = 0;
    
    while (j < size - 1)
    {

        if(tab[j][line_size] != '\n')
        {
            printf("Error\n");
            exit(1);
        }
        j++;
    }
      if(tab[size - 1][line_size ] != '\0' && tab[size - 1][line_size - 1] == '1')
        {
            
            printf("Error\n");
            exit(1);
        }
}
void check_walls(char *file,int fd, int size)
{
    char **tab;
    int i;
    tab = fill_lines(file,fd);
    i = 0;
    while(tab[0][i] != '\n')
    {
        if(tab[0][i] != '1')
        {
            printf("ERoor\n");
            exit(1);
        }
        i++;
    }
    check_nbline(tab, i, size);
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


