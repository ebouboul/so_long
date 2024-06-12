/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouboul <ebouboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:08:16 by ebouboul          #+#    #+#             */
/*   Updated: 2024/06/12 23:46:33 by ebouboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	is_ber(char *file)
{
	char	*extns;

	extns = ft_strrchr(file, '.');
	if (extns == NULL)
		return (0);
	if (ft_strcmp(extns, ".ber") == 0)
		return (1);
	else
		return (0);
}

int	dest(t_vars *vars)
{
	destroy(vars);
	return (0);
}

void	get_game(char *file, int height, int width)
{
	t_vars	vars;

	vars.i = 0;
	vars.mlx = mlx_init();
	vars.tab = fill_lines(file);
	vars.height = height;
	vars.width = width;
	vars.mlx_win = mlx_new_window(vars.mlx, vars.width * 50, vars.height * 50,
			"SO_LONG");
	fill_win(&vars, 1);
	mlx_key_hook(vars.mlx_win, handle_key, &vars);
	mlx_hook(vars.mlx_win, 17, 0, dest, &vars);
	mlx_loop(vars.mlx);
}

int	main(int ac, char **av)
{
	int	i;
	int	j;

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
