/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouboul <ebouboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:08:42 by ebouboul          #+#    #+#             */
/*   Updated: 2024/05/17 22:43:06 by ebouboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "get_next_line.h"
typedef struct 	s_point {
	int			x;				// x : Width  | x-axis
	int			y;				// y : Height | y-axis
}				t_point;
 

// parcing functions
char ** check_walls(char *file,int fd, int size);
void check_c0pe(char *map);
char *check_nbline(char **tab, int line_size, int size);
char **fill_lines(char *file, int size);
int tab_size(char *file);
void print_error(const char *str, char **tab, char *tab1);
void free_tab2(char **tab);
void	flood_fill(char **tab, t_point *begin);
void big_check(char *file, int fd, int size);
void player_position(char **tab, t_point **playre);

#endif