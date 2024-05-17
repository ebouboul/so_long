/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouboul <ebouboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:08:16 by ebouboul          #+#    #+#             */
/*   Updated: 2024/05/17 22:33:28 by ebouboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <string.h>


void free_tab2(char **tab)
{
    if (tab != NULL)
    {
        int i = 0;
        while (tab[i] != NULL)
        {
            free(tab[i]);
            i++;
        }
        free(tab);
    }
}
int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}


int is_ber(char *file)
{
    char *extns = ft_strchr(file, '.');
    if(extns == NULL)
    return 0;
    if (ft_strcmp(extns, ".ber") == 0)
    return(1);
    else 
    return(0);
}

void print_error(const char *str, char **tab, char *tab1)
{
    if(!tab && tab1)
    free(tab1);
    if(!tab1 && tab)
    free_tab2(tab);
    write(2, str, ft_strlen(str));
    write(2, "\n", 1);
    exit(1);
}

int main(int ac, char **av)
{
    if(ac != 2)
        return(0);
    else
    {
        if(is_ber(av[1]) == 0)
        print_error("Error: Wrong file format\n", NULL, NULL);
        int fd;
        int i;
        i = tab_size(av[1]);
        
        fd = open(av[1], O_RDWR);
        
        big_check(av[1],fd, i);
    }
}


