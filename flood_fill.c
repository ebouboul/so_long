/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouboul <ebouboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:17:32 by ebouboul          #+#    #+#             */
/*   Updated: 2024/05/17 18:59:17 by ebouboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill(char **tab,int x , int y , char to_fill)
{
	if (tab[y][x] == '1' || (tab[y][x] != to_fill && tab[y][x] != '0' && tab[y][x] != 'E' && tab[y][x] != 'C') ||
	((tab[y][x] == 'E') &&(tab[y][x-1] == 'C' || tab[y][x+1] == 'C')))
		return;

	tab[y][x] = 'F';

	fill(tab, x + 1 , y  , to_fill);
    fill(tab,x - 1, y, to_fill);
	fill(tab,x , y - 1 , to_fill);
	fill(tab,x , y + 1, to_fill);

    
}

void	flood_fill(char **tab, t_point begin)
{
	fill(tab, begin.x , begin.y , 'P');
}

void player_position(char **tab, t_point **playre)
{
    (*playre)->y = 0;
    while(tab[(*playre)->y])
    {
        (*playre)->x = 0;
        while(tab[(*playre)->y][(*playre)->x])
        {
            if(tab[(*playre)->y][(*playre)->x] == 'P')
               return;
            (*playre)->x++;
        }
        (*playre)->y++;
    }
}
void big_check(char *file, int fd, int size)
{
    char **tab;
    tab = check_walls(file,fd, size);
    int i;
    i = 0;
    int j;
    j = 0;
    while(tab[j])
    {
        i = 0;
        while(tab[j][i])
        {
            if(tab[j][i] != '1' && tab[j][i] != 'F' && tab[j][i] != '\n')
            {
                free_tab2(tab);
                print_error("Invalid map");
            }
            i++;
        }
        j++;
    }
    free_tab2(tab);
}
