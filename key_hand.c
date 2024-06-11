/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hand.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouboul <ebouboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:29:45 by ebouboul          #+#    #+#             */
/*   Updated: 2024/06/11 22:31:30 by ebouboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	handle_move(char direction, t_vars *vars)
{
	change_palayer(direction, vars);
	fill_win(vars , 2);
}

int	handle_key(int keycode, t_vars *vars)
{
	if (keycode == ESC_KEY)
	{
		printf("ESC key pressed\n");
		destroy(vars);
	}
	else if (keycode == W_KEY)
		handle_move('W', vars);
	else if (keycode == A_KEY)
		handle_move('A', vars);
	else if (keycode == S_KEY)
		handle_move('S', vars);
	else if (keycode == D_KEY)
		handle_move('D', vars);
	return (0);
}

void	fill_background(t_vars *vars)
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
}

void	fill_elements(t_vars *vars)
{
	int (i), (j);
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
					vars->tab[j][i] = 'A';
				else
					put_img(*vars, "door.xpm", i, j);
			}
			if (vars->tab[j][i] == 'C')
				put_img(*vars, "coins.xpm", i, j);
			if (vars->tab[j][i] == 'P')
				put_img(*vars, "player.xpm", i, j);
			if (vars->tab[j][i] == 'A')
				put_img(*vars, "exit.xpm", i, j);
		}
	}
}
void change_place(t_vars *vars)
{
	int (i), (j);
	j = -1;
	while (++j < vars->height)
	{
		i = -1;
		while (++i < vars->width)
		{
			if (vars->tab[j][i] == 'P')
				put_img(*vars, "player.xpm", i, j);
			if (vars->tab[j][i] == '0')
				put_img(*vars, "earth.xpm", i, j);
			if (vars->tab[j][i] == 'E')
			{
				if (coin_count(vars->tab) == 0)
					vars->tab[j][i] = 'A';
				else
					put_img(*vars, "door.xpm", i, j);
			}
			if (vars->tab[j][i] == 'A')
				put_img(*vars, "exit.xpm", i, j);
		}
	}
}

void	fill_win(t_vars *vars, int flag)
{
	if(flag == 1)
	{
		fill_background(vars);
		fill_elements(vars);
	}
	else
		change_place(vars);
}
