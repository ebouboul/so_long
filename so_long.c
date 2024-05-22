/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouboul <ebouboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:08:16 by ebouboul          #+#    #+#             */
/*   Updated: 2024/05/22 17:55:09 by ebouboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>
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
void put_img(void *mlx, void *mlx_win, char *imgpath, int w, int h)
{

    int img_width;
    int img_height;
    void *img = mlx_xpm_file_to_image(mlx, imgpath, &img_width, &img_height);

    mlx_put_image_to_window(mlx, mlx_win, img, img_width * w , img_height * h);
}
/// 


int handle_key(int keycode, void *param)
{
    (void)param; // To suppress unused parameter warning
    if (keycode == ESC_KEY)
    {
        printf("ESC key pressed\n");
        exit(0);
    }
    else if (keycode == W_KEY)
        printf("W key pressed\n");
    else if (keycode == A_KEY)
        printf("A key pressed\n");
    else if (keycode == S_KEY)
        printf("S key pressed\n");
    else if (keycode == D_KEY)
        printf("D key pressed\n");
    return 0;
}

/// 

void get_game(char *file, int height, int width)
{
    void *mlx = mlx_init();
    char **tab;
    tab = fill_lines(file);
 void *mlx_win = mlx_new_window(mlx, width * 50, height *50, "Hello world!");
    int j = 0;
    while (j < height)
    {
        int i = 0;
        while (i < width)
        {
            put_img(mlx, mlx_win, "earth.xpm", i, j);
            i++;
        }
        j++;
    }
    j = 0;
    while (j < height)
    {
        int i = 0;
        while (i < width)
        {
            if (tab[j][i] == '1')
            put_img(mlx, mlx_win, "wall .xpm", i, j);
            if(tab[j][i] == 'E')
            put_img(mlx, mlx_win, "door.xpm", i, j);
            if(tab[j][i] == 'C')
            put_img(mlx, mlx_win, "coins.xpm", i, j);
            if(tab[j][i] == 'P')
            put_img(mlx, mlx_win, "player.xpm", i, j);
            i++;
        }
        j++;
    }
    mlx_key_hook(mlx_win, handle_key, NULL);
    mlx_loop(mlx);
}
int main(int ac, char **av)
{
    if(ac != 2)
        return(0);
    else
    {
        if(is_ber(av[1]) == 0)
        print_error("Error: Wrong file format\n", NULL, NULL);
        int i;
        int j;
        i = tab_size(av[1]);
        j = big_check(av[1], i);
        get_game(av[1], i, j);
        
    }
}




