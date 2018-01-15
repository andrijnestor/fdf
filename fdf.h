/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 13:21:46 by anestor           #+#    #+#             */
/*   Updated: 2018/01/15 22:06:11 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include "libft/libft.h"
# define ABS(x) (x < 0) ? x * -1 : x
# define DRAW_UNTIL(x, s, e) (s < e) ? x <= e : e <= x
# define ITERATE(x, y, s, e) (s < e) ? x + y : x - y
# define Y(i) fdf->dot[i].y
# define X(i) fdf->dot[i].x
# define Z(i) fdf->dot[i].z
# define COLOR(i) fdf->dot[i].col
# define PY(i) fdf->p_dot[i].y
# define PX(i) fdf->p_dot[i].x
# define PZ(i) fdf->p_dot[i].z
# define PCOLOR(i) fdf->p_dot[i].col
# define WIN_H 1000
# define WIN_W 1000
# define ANGLE_STEP 15
# define SCALE_STEP 0.1
# define RAD(x) (x * M_PI / 180.0)
# define DEG(x) (x * 180.0 / M_PI)
# define GREATER(x, y) (x > y) ? x : y
# define LOWER(x, y) (x < y) ? x : y

typedef struct		s_dot
{
	int				x;
	int				y;
	int				z;
	int				col;
}					t_dot;

typedef struct		s_mouse
{
	int				x;
	int				y;
	int				last_x;
	int				last_y;
	char			is_down;
}					t_mouse;

typedef struct		s_parmcol
{
	int				is_set;
	int				col1;
	int				col2;
}					t_parmcol;

typedef struct		s_fdf
{
	t_dot			*dot;
	t_dot			*p_dot;
	void			*mlx;
	void			*win;
	int				grid_p_w;
	int				grid_p_h;
	int				win_w;
	int				win_h;
	int				x_angle;
	int				y_angle;
	int				z_angle;
	double			scale;
	double			z_scale;
	t_mouse			mouse;
	t_parmcol		col_param;
}					t_fdf;

/*
** exit with massage
*/

int					fdf_exit(char *text);

/*
** readings and init settings
*/

int					read_fdf(char *file, t_fdf *fdf);
void				allocate_dots(char *file, t_fdf *fdf);
void				read_lines(char *line, t_fdf *fdf, int *n);
void				first_scale(t_fdf *fdf);
void				pre_render(t_fdf *fdf);

/*
** grids
*/

void				make_grid(t_fdf *fdf);
void				draw_grid(t_fdf *fdf);

/*
** scale, rotation, and render
*/

void				scale_and_position(t_fdf *fdf);
void				rotate_x(t_fdf *fdf);
void				rotate_y(t_fdf *fdf);
void				rotate_z(t_fdf *fdf);
void				render(t_fdf *fdf);

/*
** vector draw
*/

void				ft_draw_vector(t_dot start, t_dot end, void *mlx_ptr,
															void *win_ptr);
int					color_grad(int start, int end, double perc);
int					color(int c1, int c2, double perc);

/*
** hooks
*/

int					key_hooks(int keycode, t_fdf *fdf);
int					hook_mouse_down(int button, int x, int y, t_fdf *fdf);
int					hook_mouse_up(int button, int x, int y, t_fdf *fdf);
int					hook_mouse_move(int x, int y, t_fdf *fdf);

/*
** bonus colors
*/

void				color_gamma(int c1, int c2, t_fdf *fdf);
void				change_colors(t_fdf *fdf);

#endif
