/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouboul <ebouboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:08:42 by ebouboul          #+#    #+#             */
/*   Updated: 2024/06/11 20:47:27 by ebouboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "get_next_line.h"
#include "./minilibx-linux/mlx_int.h"
#include "./minilibx-linux/mlx.h"
#define ESC_KEY 65307
#define W_KEY 119
#define A_KEY 97
#define S_KEY 115
#define D_KEY 100

typedef struct 	s_point {
	int			x;				// x : Width  | x-axis
	int			y;				// y : Height | y-axis
}				t_point;

 
 typedef struct	s_vars {
	void	*mlx;
	void	*mlx_win;
    char **tab;
    int height;
    int width;
	t_img	*img;
}				t_vars;

typedef struct s_variables {
	int i;
 	int j;
	int ni;
	int nj;
}				varib;



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

// window functions
void	put_img(t_vars vars, char *imgpath, int w, int h);
void	fill_win(t_vars *vars);
void	fill_background(t_vars *vars);
void	fill_elements(t_vars *vars);
void	move_player(t_vars *vars, varib *var);
void	change_palayer(char direction, t_vars *vars);
void	handle_move(char direction, t_vars *vars);
int	handle_key(int keycode, t_vars *vars);
void	get_game(char *file, int height, int width);
void	destroy(t_vars *vars);
int	coin_count(char **tab);


#endif