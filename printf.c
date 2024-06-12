/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouboul <ebouboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:10:37 by ebouboul          #+#    #+#             */
/*   Updated: 2024/06/12 18:45:43 by ebouboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_nbr(int n)
{
	char	digit;

	if (n >= 10)
		put_nbr(n / 10);
	digit = n % 10 + '0';
	write(1, &digit, 1);
}

void	change_place(t_vars *vars)
{
	int (i), (j);
	j = -1;
	while (++j < vars->height)
	{
		i = -1;
		while (++i < vars->width)
		{
			if (vars->tab[j][i] == 'P')
				put_img(*vars, "img/player.xpm", i, j);
			if (vars->tab[j][i] == '0')
				put_img(*vars, "img/earth.xpm", i, j);
			if (vars->tab[j][i] == 'E')
			{
				if (coin_count(vars->tab) == 0)
					vars->tab[j][i] = 'A';
				else
					put_img(*vars, "img/door.xpm", i, j);
			}
			if (vars->tab[j][i] == 'A')
				put_img(*vars, "img/exit.xpm", i, j);
		}
	}
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
