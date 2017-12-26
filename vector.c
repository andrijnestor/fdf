/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 13:21:57 by anestor           #+#    #+#             */
/*   Updated: 2017/12/26 17:24:40 by anestor          ###   ########.fr       */
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
	y =	start.y;
	vect_l = sqrt(pow(ABS((end.x - start.x)), 2) + pow(ABS((end.y - start.y)), 2));
	x_turn = (ABS((end.x - start.x))) / vect_l;
	y_turn = (ABS((end.y - start.y))) / vect_l;
//	printf("abs_x: %d\n", ABS((end.x - start.x)));
//	printf("abs_y: %d\n", ABS((end.y - start.y)));
//	printf("vector_len: %f\n", vect_l);
//	printf("x_turn: %f y_turn %f\n", x_turn, y_turn);
//	printf("x_s: %d x_e %d\n", start.x, end.x);
//	printf("y_s: %d y_e %d\n", start.y, end.y);
	while ((DRAW_UNTIL(x, start.x, end.x)) && (DRAW_UNTIL(y, start.y, end.y)))
	{	
		mlx_pixel_put(mlx_ptr, win_ptr, (int)x, (int)y, 0xffff);
		x = ITERATE(x, x_turn, start.x, end.x);
		y = ITERATE(y, y_turn, start.y, end.y);
//		printf("x: %f y: %f\n", x, y);
	}
//	mlx_pixel_put(mlx_ptr, win_ptr, end.x, end.y, 0xffa500);
}
/*
void	ft_make_vector(int x_s, int y_s, int x_e, int y_e, void *mlx_ptr, void *win_ptr)
{
	double	x_d;
	double	y_d;
	double	x_turn;
	double	y_turn;
	double	vector_len;

	x_d	= (double)x_s;
	y_d = (double)y_s;
	vector_len = sqrt((double)x_e * (double)x_e + (double)y_e * (double)y_e);

	if (x_e > x_s)
		x_turn = ((double)x_e - (double)x_s) / vector_len;
	else
		x_turn = (double)x_s - (double)x_e / vector_len;
	if (y_e > y_s)
		y_turn = ((double)y_e - (double)y_s) / vector_len;
	else
		y_turn = ((double)y_s - (double)y_e) / vector_len;

	if (x_e >= x_s && y_e >= y_s)
		while ((int)x_d <= x_e && (int)y_d <= y_e)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, (int)x_d, (int)y_d, 0xffff);
			x_d += x_turn;
			y_d += y_turn;
		}
	else if (x_e <= x_s && y_e <= y_s)
		while ((int)x_d >= x_e && (int)y_d >= y_e)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, (int)x_d, (int)y_d, 0xffff);
			x_d -= x_turn;
			y_d -= y_turn;
		}
	else if (x_e >= x_s && y_e <= y_s)
		while ((int)x_d <= x_e && (int)y_d >= y_e)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, (int)x_d, (int)y_d, 0xffff);
			x_d += x_turn;
			y_d -= y_turn;
		}
	else if (x_e <= x_s && y_e >= y_s)
		while ((int)x_d >= x_e && (int)y_d <= y_e)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, (int)x_d, (int)y_d, 0xffff);
			x_d -= x_turn;
			y_d += y_turn;
		}
}

void	ft_draw_vector(t_dot start, t_dot end, void *mlx_ptr, void *win_ptr)
{
	ft_make_vector(start.x, start.y, end.x, end.y, mlx_ptr, win_ptr);
}
*/
