/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 16:46:34 by anestor           #+#    #+#             */
/*   Updated: 2018/01/15 18:22:34 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	make_grid(t_fdf *fdf)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
	while (y != fdf->grid_p_h)
	{
		x = 0;
		while (x != fdf->grid_p_w)
		{
			X(i) = x;
			Y(i) = y;
			x++;
			i++;
		}
		y++;
	}
	ft_memcpy(fdf->p_dot, fdf->dot, sizeof(t_dot) *
						fdf->grid_p_h * fdf->grid_p_w);
}

void	draw_grid(t_fdf *fdf)
{
	int		i;

	i = 0;
	while (i != fdf->grid_p_h * fdf->grid_p_w)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, PX(i), PY(i), PCOLOR(i));
		i++;
	}
	i = 0;
	while (i != fdf->grid_p_h * fdf->grid_p_w - fdf->grid_p_w)
	{
		ft_draw_vector(fdf->p_dot[i], fdf->p_dot[i + fdf->grid_p_w],
													fdf->mlx, fdf->win);
		i++;
	}
	i = 0;
	while (i != fdf->grid_p_h * fdf->grid_p_w)
	{
		if (((i + 1) % fdf->grid_p_w))
			ft_draw_vector(fdf->p_dot[i], fdf->p_dot[i + 1],
													fdf->mlx, fdf->win);
		i++;
	}
}
