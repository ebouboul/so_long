/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouboul <ebouboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:08:42 by ebouboul          #+#    #+#             */
/*   Updated: 2024/05/22 17:55:22 by ebouboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "get_next_line.h"
#define ESC_KEY 65307
#define W_KEY 119
#define A_KEY 97
#define S_KEY 115
#define D_KEY 100

typedef struct 	s_point {
	int			x;				// x : Width  | x-axis
	int			y;				// y : Height | y-axis
}				t_point;
 

// parcing functions
char ** check_walls(char *file, int size);
void check_c0pe(char *map);
char *check_nbline(char **tab, int line_size, int size);
char **fill_lines(char *file);
int tab_size(char *file);
void print_error(const char *str, char **tab, char *tab1);
void free_tab2(char **tab);
void	flood_fill(char **tab, t_point *begin);
int big_check(char *file, int size);
void player_position(char **tab, t_point **playre);

#endif