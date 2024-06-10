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
int coin_count(char **tab)
        {
            int count = 0;
            int i = 0;
            int j = 0;
            while (tab[i])
            {
                j = 0;
                while (tab[i][j])
                {
                    if (tab[i][j] == 'C')
                        count++;
                    j++;
                }
                i++;
            }
            return count;
        }
    void destroy(void *mlx, void *mlx_win, void *put_img, char **tab)
{
    free_tab2(tab);
    mlx_destroy_image(mlx, put_img);
    mlx_destroy_window(mlx, mlx_win);
    mlx_destroy_display(mlx);
    free(mlx);
    exit(0);
}
void change_palayer(char key, t_vars *vars)
{
    int i = 0;
    int j = 0;
    while (vars->tab[i])
    {
        j = 0;
        while (vars->tab[i][j])
        {
            if(vars->tab[i][j] == 'P')
            {   
                if(key == 'W')
                {
                    if(vars->tab[i - 1][j] == '0' || vars->tab[i - 1][j] == 'C')
                    {
                        vars->tab[i - 1][j] = 'P';
                        vars->tab[i][j] = '0';
                    }
                    // return;
                }
                else if(key == 'S')
                {
                    if(vars->tab[i + 1][j] == '0' || vars->tab[i + 1][j] == 'C')
                    {
                        vars->tab[i + 1][j] = 'P';
                        vars->tab[i][j] = '0';
                    }
                    return;
                }
                else if(key == 'D')
                {
                    if(vars->tab[i][j + 1] == '0' || vars->tab[i][j + 1] == 'C' || vars->tab[i][j + 1] == 'E')
                    {
                if(vars->tab[i][j + 1] == 'E')
                {
                    printf("You win\n");
                    destroy(vars->mlx, vars->mlx_win, NULL, vars->tab);
                }
                else
                    {        vars->tab[i][j + 1] = 'P';
                        vars->tab[i][j] = '0';
                        }
                    }
                    return;
                }
                else if(key == 'A')
                {
                    if(vars->tab[i][j - 1] == '0' || vars->tab[i][j - 1] == 'C' )
                    {
                        vars->tab[i][j - 1] = 'P';
                        vars->tab[i][j] = '0';

                    }
                    return;
                }
            }
            j++;
        }
        i++;
    }
}
void fill_win(void *mlx, void *mlx_win, char **tab, int height, int width)
{
    int j = -1;
    while (++j < height)
    {
        int i = -1;
        while (++i < width)
            put_img(mlx, mlx_win, "earth.xpm", i, j);
    }
    j = -1;
    while (++j < height)
    {
        int i = -1;
        while (++i < width)
        {
            if (tab[j][i] == '1')
            put_img(mlx, mlx_win, "wall .xpm", i, j);
            if(tab[j][i] == 'E')
            {
            if(coin_count(tab) == 0)
            {
               put_img(mlx, mlx_win, "exit.xpm", i, j); 
            }
            else
            put_img(mlx, mlx_win, "door.xpm", i, j);
            }
            // put_img(mlx, mlx_win, "door.xpm", i, j);
            if(tab[j][i] == 'C')
            put_img(mlx, mlx_win, "coins.xpm", i, j);
            if(tab[j][i] == 'P')
            put_img(mlx, mlx_win, "player.xpm", i, j);
        }
    }
    // mlx_destroy_image(mlx, put_img);
    // mlx_destroy_image(mlx, put_img);
}


int handle_key(int keycode, t_vars *vars)
{
    if (keycode == ESC_KEY)
    {
        printf("ESC key pressed\n");
        exit(0);
    }
    else if (keycode == W_KEY)
    {
        change_palayer('W',  vars);
        printf("W key pressed\n");
    }
    else if (keycode == A_KEY)
    {
        change_palayer('A', vars);
        printf("A key pressed\n");
    }
    else if (keycode == S_KEY)
    {
        change_palayer('S', vars);
        printf("S key pressed\n");
    }
    else if (keycode == D_KEY)
    {
        change_palayer('D', vars);
        printf("D key pressed\n");
    }
    fill_win(vars->mlx, vars->mlx_win, vars->tab, vars->height, vars->width);
    // mlx_loop(vars->mlx);
    return 0;
}


// char **ft_strchr_2d(char **tab, char c)
// {
//     int i = 0;
//     while (tab[i])
//     {
//         ft_strchr(tab[i], "P")
//     }
    
// }
// /// 
// void change_palayer(char **tab, char key)
// {
//     if(key == W)
//     {
//     }
// }
void get_game(char *file, int height, int width)
{
    t_vars vars;
    vars.mlx = mlx_init();
    vars.tab = fill_lines(file);
    vars.height = height;
    vars.width = width;
    vars.mlx_win = mlx_new_window(vars.mlx, vars.width * 50, vars.height *50, "SO_LONG");
    fill_win(vars.mlx, vars.mlx_win, vars.tab, vars.height, vars.width);
    mlx_key_hook(vars.mlx_win, handle_key, &vars);

    mlx_loop(vars.mlx);
    mlx_destroy_window(vars.mlx, vars.mlx_win);

    

    // mlx_loop(mlx);
    // mlx_destroy_window(mlx, mlx_win);
    
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




