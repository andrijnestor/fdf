/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 16:45:10 by anestor           #+#    #+#             */
/*   Updated: 2018/01/15 20:45:49 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	render(t_fdf *fdf)
{
	scale_and_position(fdf);
	rotate_x(fdf);
	rotate_y(fdf);
	rotate_z(fdf);
	draw_grid(fdf);
}

void	rotate_x(t_fdf *fdf)
{
	int		i;
	int		y;
	int		z;
	int		y1;
	int		z1;

	i = 0;
	while (i != fdf->grid_p_h * fdf->grid_p_w)
	{
		y = PY(i) - WIN_H / 2;
		z = PZ(i);
		y1 = y;
		z1 = z;
		y = y1 * cos(RAD(fdf->x_angle)) + z1 * sin(RAD(fdf->x_angle));
		z = -y1 * sin(RAD(fdf->x_angle)) + z1 * cos(RAD(fdf->x_angle));
		PY(i) = y + WIN_H / 2;
		PZ(i) = z;
		i++;
	}
}

void	rotate_y(t_fdf *fdf)
{
	int		i;
	int		x;
	int		z;
	int		x1;
	int		z1;

	i = 0;
	while (i != fdf->grid_p_h * fdf->grid_p_w)
	{
		x = PX(i) - WIN_W / 2;
		z = PZ(i);
		x1 = x;
		z1 = z;
		x = x1 * cos(RAD(fdf->y_angle)) + z1 * sin(RAD(fdf->y_angle));
		z = -x1 * sin(RAD(fdf->y_angle)) + z1 * cos(RAD(fdf->y_angle));
		PX(i) = x + WIN_W / 2;
		PZ(i) = z;
		i++;
	}
}

void	rotate_z(t_fdf *fdf)
{
	int		i;
	int		x;
	int		y;
	int		x1;
	int		y1;

	i = 0;
	while (i != fdf->grid_p_h * fdf->grid_p_w)
	{
		x = PX(i) - WIN_W / 2;
		y = PY(i) - WIN_H / 2;
		x1 = x;
		y1 = y;
		x = x1 * cos(RAD(fdf->z_angle)) - y1 * sin(RAD(fdf->z_angle));
		y = x1 * sin(RAD(fdf->z_angle)) + y1 * cos(RAD(fdf->z_angle));
		PX(i) = x + WIN_W / 2;
		PY(i) = y + WIN_H / 2;
		i++;
	}
}

void	scale_and_position(t_fdf *fdf)
{
	int		x_offset;
	int		y_offset;
	int		i;
	int		step;

	i = 0;
	step = WIN_H / (GREATER(fdf->grid_p_h, fdf->grid_p_w));
	step = fdf->scale * step;
	x_offset = WIN_W / 2 - fdf->grid_p_w * step / 2 + step / 2;
	y_offset = WIN_H / 2 - fdf->grid_p_h * step / 2 + step / 2;
	while (i != fdf->grid_p_h * fdf->grid_p_w)
	{
		PX(i) = step * X(i) + x_offset;
		PY(i) = step * Y(i) + y_offset;
		PZ(i) = step * Z(i) * fdf->z_scale;
		i++;
	}
}
