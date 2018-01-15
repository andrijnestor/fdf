/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 13:21:57 by anestor           #+#    #+#             */
/*   Updated: 2018/01/15 17:53:44 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_vector(t_dot start, t_dot end, void *mlx_ptr, void *win_ptr)
{
	double	x;
	double	y;
	double	vect_l;
	double	x_turn;
	double	y_turn;

	x = start.x;
	y = start.y;
	vect_l = sqrt(pow(ABS((end.x - start.x)), 2) +
							pow(ABS((end.y - start.y)), 2));
	x_turn = (ABS((end.x - start.x))) / vect_l;
	y_turn = (ABS((end.y - start.y))) / vect_l;
	while ((DRAW_UNTIL(x, start.x, end.x)) && (DRAW_UNTIL(y, start.y, end.y)))
	{
		mlx_pixel_put(mlx_ptr, win_ptr, (int)x, (int)y,
			color(end.col, start.col, (end.x - x) / (end.x - start.x)));
		x = ITERATE(x, x_turn, start.x, end.x);
		y = ITERATE(y, y_turn, start.y, end.y);
	}
}

int		color_grad(int start, int end, double perc)
{
	if (start == end)
		return (start);
	return ((int)((double)start + (end - start) * perc));
}

int		color(int c1, int c2, double perc)
{
	int r;
	int g;
	int b;

	if (c1 == c2)
		return (c1);
	r = color_grad((c1 >> 16) & 0xFF, (c2 >> 16) & 0xFF, perc);
	g = color_grad((c1 >> 8) & 0xFF, (c2 >> 8) & 0xFF, perc);
	b = color_grad(c1 & 0xFF, c2 & 0xFF, perc);
	return (r << 16 | g << 8 | b);
}
