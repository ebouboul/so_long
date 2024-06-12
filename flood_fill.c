/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouboul <ebouboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:17:32 by ebouboul          #+#    #+#             */
/*   Updated: 2024/06/13 00:03:58 by ebouboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill(char **tab, int x, int y, char to_fill)
{
	if (tab[y][x] == '1' || (tab[y][x] != to_fill && tab[y][x] != '0'
			&& tab[y][x] != 'E' && tab[y][x] != 'C') || ((tab[y][x] == 'E')
			&& (tab[y][x - 1] == 'C' || tab[y][x + 1] == 'C'
				|| tab[y - 1][x] == 'C' || tab[y + 1][x] == 'C')))
		return ;
	tab[y][x] = 'F';
	fill(tab, x + 1, y, to_fill);
	fill(tab, x - 1, y, to_fill);
	fill(tab, x, y - 1, to_fill);
	fill(tab, x, y + 1, to_fill);
}

void	flood_fill(char **tab, t_point *begin)
{
	fill(tab, begin->x, begin->y, 'P');
	free(begin);
}

void	player_position(char **tab, t_point **playre)
{
	(*playre)->y = 0;
	while (tab[(*playre)->y])
	{
		(*playre)->x = 0;
		while (tab[(*playre)->y][(*playre)->x])
		{
			if (tab[(*playre)->y][(*playre)->x] == 'P')
				return ;
			(*playre)->x++;
		}
		(*playre)->y++;
	}
}

int	big_check(char *file, int size)
{
	char	**tab;
	int		i;
	int		j;

	tab = check_walls(file, size);
	i = 0;
	j = 0;
	while (tab[j])
	{
		i = 0;
		while (tab[j][i])
		{
			if (tab[j][i] != '1' && tab[j][i] != 'F' && tab[j][i] != '\n')
				print_error("Invalid map", tab, NULL);
			i++;
		}
		j++;
	}
	free_tab2(tab);
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		count;
	char	*str;

	str = (char *)s;
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)c)
			count = i;
		i++;
	}
	if (str[i] == (unsigned char)c)
		return (str = &str[i]);
	else if (count == 0 && s[0] != (unsigned char)c)
		return (0);
	else
	{
		str = &str[count];
		return (str);
	}
}
