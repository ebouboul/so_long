/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouboul <ebouboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:27:46 by ebouboul          #+#    #+#             */
/*   Updated: 2024/06/11 22:35:26 by ebouboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	move_player(t_vars *vars, varib *var)
{
	if (vars->tab[var->ni][var->nj] == '0' || vars->tab[var->ni][var->nj] == 'C'
		|| vars->tab[var->ni][var->nj] == 'A')
	{
		if (vars->tab[var->ni][var->nj] == 'A')
		{
			printf("You win\n");
			destroy(vars);
		}
		else
		{
			vars->tab[var->ni][var->nj] = 'P';
			vars->tab[var->i][var->j] = '0';
			vars->i++;
			printf("%d moves\n", vars->i);
		}
	}
	
}

void	change_palayer(char key, t_vars *vars)
{
	varib	var;

	var.i = -1;
	while (vars->tab[++var.i])
	{
		var.j = -1;
		while (vars->tab[var.i][++var.j])
		{
			if (vars->tab[var.i][var.j] == 'P')
			{
				var.ni = var.i;
				var.nj = var.j;
				if (key == 'W')
					var.ni--;
				else if (key == 'S')
					var.ni++;
				else if (key == 'D')
					var.nj++;
				else if (key == 'A')
					var.nj--;
				move_player(vars, &var);
				return ;
			}
		}
	}
}

void	destroy(t_vars *vars)
{
	free_tab2(vars->tab);
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
}
