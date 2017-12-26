/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 13:21:46 by anestor           #+#    #+#             */
/*   Updated: 2017/12/26 14:59:21 by anestor          ###   ########.fr       */
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
# include "minilibx_macos/mlx.h" //
# include "libft/libft.h" //
# define ABS(x) (x < 0) ? x * -1 : x
# define DRAW_UNTIL(x, s, e) (s < e) ? x <= e : e <= x
# define ITERATE(x, y, s, e) (s < e) ? x + y : x - y
# define Y(x) fdf->dot[x].y
# define X(y) fdf->dot[y].x
# define RAD(x) (x * M_PI / 180.0)
# define DEG(x) (x * 180.0 / M_PI)
# define GREATER(x, y) (x > y) ? x : y
# define LOWER(x, y) (x < y) ? x : y
# include <stdio.h> //

typedef struct		s_dot
{
	int				x;
	int				y;
//	struct s_dot	*next;
}					t_dot;

typedef struct		s_fdf
{
	t_dot			*dot;
	void			*mlx;
	void			*win;
	void			*output;
	int				grid_w;
	int				grid_h;
	int				grid_mw;
	int				grid_mh;
	int				win_w;
	int				win_h;
	int				angle;
}					t_fdf;

void	ft_draw_vector(t_dot start, t_dot end, void *mlx_ptr, void *win_ptr);

int		key_hook_exit(int keycode, t_fdf *fdf);


#endif
