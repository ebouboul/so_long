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

void	free_tab2(char **tab)
{
	int	i;

	if (tab != NULL)
	{
		i = 0;
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
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int	is_ber(char *file)
{
	char	*extns;

	extns = ft_strchr(file, '.');
	if (extns == NULL)
		return (0);
	if (ft_strcmp(extns, ".ber") == 0)
		return (1);
	else
		return (0);
}

void	print_error(const char *str, char **tab, char *tab1)
{
	if (!tab && tab1)
		free(tab1);
	if (!tab1 && tab)
		free_tab2(tab);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(1);
}
void	put_img(t_vars vars, char *imgpath, int w, int h)
{
	int		img_width;
	int		img_height;
	t_img	*img;

	img = mlx_xpm_file_to_image(vars.mlx, imgpath, &img_width, &img_height);
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, img, img_width * w,
			img_height * h);
	mlx_destroy_image(vars.mlx, img);
}
///
int	coin_count(char **tab)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	j = 0;
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
	return (count);
}
void	destroy(t_vars *vars)
{
	free_tab2(vars->tab);
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
}

void move_player(t_vars *vars, int i, int j, int ni, int nj)
{
	if (vars->tab[ni][nj] == '0' || vars->tab[ni][nj] == 'C'
		|| vars->tab[ni][nj] == 'E')
	{
		if (vars->tab[ni][nj] == 'E')
		{
			printf("You win\n");
			destroy(vars);
		}
		else
		{
			vars->tab[ni][nj] = 'P';
			vars->tab[i][j] = '0';
		}
	}
}

void	change_palayer(char key, t_vars *vars)
{
	int i, j, ni, nj;
	i = 0;
	while (vars->tab[i])
	{
		j = 0;
		while (vars->tab[i][j])
		{
			if (vars->tab[i][j] == 'P')
			{
				ni = i;
				nj = j;
				if (key == 'W')
					ni--;
				else if (key == 'S')
					ni++;
				else if (key == 'D')
					nj++;
				else if (key == 'A')
					nj--;
				move_player(vars, i, j, ni, nj);
				return ;
			}
			j++;
		}
		i++;
	}
}

void	fill_win(t_vars *vars)
{
	int	j;
	int	i;

	j = -1;
	while (++j < vars->height)
	{
		i = -1;
		while (++i < vars->width)
			put_img(*vars, "earth.xpm", i, j);
	}
	j = -1;
	while (++j < vars->height)
	{
		i = -1;
		while (++i < vars->width)
		{
			if (vars->tab[j][i] == '1')
				put_img(*vars, "wall .xpm", i, j);
			if (vars->tab[j][i] == 'E')
			{
				if (coin_count(vars->tab) == 0)
				{
					put_img(*vars, "exit.xpm", i, j);
				}
				else
				{
					put_img(*vars, "door.xpm", i, j);
				}
			}
			if (vars->tab[j][i] == 'C')
				put_img(*vars, "coins.xpm", i, j);
			if (vars->tab[j][i] == 'P')
				put_img(*vars, "player.xpm", i, j);
		}
	}
}

int	handle_key(int keycode, t_vars *vars)
{
	if (keycode == ESC_KEY)
	{
		printf("ESC key pressed\n");
		destroy(vars);
	}
	else if (keycode == W_KEY)
	{
		change_palayer('W', vars);
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
	fill_win(vars);
	return (0);
}

void	get_game(char *file, int height, int width)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.tab = fill_lines(file);
	vars.height = height;
	vars.width = width;
	vars.mlx_win = mlx_new_window(vars.mlx, vars.width * 50, vars.height * 50,
			"SO_LONG");
	fill_win(&vars);
	mlx_key_hook(vars.mlx_win, handle_key, &vars);
	mlx_loop(vars.mlx);
}

int	main(int ac, char **av)
{
		int i;
		int j;

	if (ac != 2)
		return (0);
	else
	{
		if (is_ber(av[1]) == 0)
			print_error("Error: Wrong file format\n", NULL, NULL);
		i = tab_size(av[1]);
		j = big_check(av[1], i);
		get_game(av[1], i, j);
	}
}
